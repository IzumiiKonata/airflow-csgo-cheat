#include "globals.hpp"
#include "thirdpesron.hpp"
#include "anti_aim.hpp"

void c_thirdperson::run_alive()
{
	if (!HACKS->in_game || !HACKS->local)
		return;

	bool alive = HACKS->local && HACKS->local->is_alive();

	if (g_cfg.binds[tp_b].toggled)
	{
		if (alive)
		{
			if (!HACKS->input->camera_in_third_person)
				HACKS->input->camera_in_third_person = true;
		}
		else
		{
			if (HACKS->input->camera_in_third_person)
			{
				HACKS->input->camera_in_third_person = false;
				HACKS->input->camera_offset.z = 0.f;
			}

			if (g_cfg.misc.thirdperson_dead && HACKS->local->observer_mode() == 4)
				HACKS->local->observer_mode() = 5;
		}

		enabled = true;
	}
	else if (HACKS->input->camera_in_third_person && enabled)
	{
		HACKS->input->camera_in_third_person = false;
		HACKS->input->camera_offset.z = 0.f;
		enabled = false;
	}

	if (HACKS->input->camera_in_third_person)
	{
		vec3_t offset{};
		HACKS->engine->get_view_angles(offset);

		vec3_t forward;
		math::angle_vectors(offset, forward);

		offset.z = g_cfg.misc.thirdperson_dist;

		auto view_offset = ANTI_AIM->is_fake_ducking() ?
			vec3_t{0.f, 0.f, HACKS->game_movement->get_player_view_offset(false).z + 0.064f} : HACKS->local->view_offset();
		auto origin = HACKS->local->get_render_origin() + view_offset;

		c_trace_filter_world_and_props_only filter{};
		c_game_trace tr{};

		HACKS->engine_trace->trace_ray(ray_t(origin, origin - (forward * offset.z), { -16.f, -16.f, -16.f }, { 16.f, 16.f, 16.f }), MASK_NPCWORLDSTATIC, (i_trace_filter*)&filter, &tr);
		offset.z *= tr.fraction;

		HACKS->input->camera_offset = { offset.x, offset.y, offset.z };

		if (g_cfg.misc.movement_camera) {
			vec3_t eye_pos = HACKS->local->get_eye_position();
			vec3_t vec = vec3_t(g_cfg.misc.interpX, g_cfg.misc.interpY, g_cfg.misc.interpZ);

			float dist = eye_pos.dist_to(vec);
			bool should_update = dist > 120;

			if (g_cfg.misc.interpX == 0 || should_update) {
				g_cfg.misc.interpX = eye_pos.x;
			}

			if (g_cfg.misc.interpY == 0 || should_update) {
				g_cfg.misc.interpY = eye_pos.y;
			}

			if (g_cfg.misc.interpZ == 0 || should_update) {
				g_cfg.misc.interpZ = eye_pos.z;
			}

			g_cfg.misc.interpX = std::lerp(g_cfg.misc.interpX, eye_pos.x, RENDER->get_animation_speed() * (g_cfg.misc.interp_speed / 10.0f));
			g_cfg.misc.interpY = std::lerp(g_cfg.misc.interpY, eye_pos.y, RENDER->get_animation_speed() * (g_cfg.misc.interp_speed / 10.0f));
			g_cfg.misc.interpZ = std::lerp(g_cfg.misc.interpZ, eye_pos.z, RENDER->get_animation_speed() * (g_cfg.misc.interp_speed / 10.0f));
			
			vec3_t view_offset = HACKS->local->view_offset();

			HACKS->local->view_offset() = { -(eye_pos.x - g_cfg.misc.interpX), -(eye_pos.y - g_cfg.misc.interpY), view_offset.z };
		}

	}
}

void c_thirdperson::run_dead()
{
}

void c_thirdperson::fix_camera_on_fakeduck(c_view_setup* setup)
{
	if (!HACKS->in_game || !HACKS->local || !HACKS->local->is_alive())
		return;

	if (!ANTI_AIM->is_fake_ducking())
		return;

	setup->origin = HACKS->local->get_render_origin() + vec3_t{0.f, 0.f, HACKS->game_movement->get_player_view_offset(false).z + 0.064f};

	if (HACKS->input->camera_in_third_person)
	{
		vec3_t angles = { HACKS->input->camera_offset.x, HACKS->input->camera_offset.y, 0.f };

		vec3_t forward = {};
		math::angle_vectors(angles, forward);

		math::vector_multiply(setup->origin, -HACKS->input->camera_offset.z, forward, setup->origin);
	}
}