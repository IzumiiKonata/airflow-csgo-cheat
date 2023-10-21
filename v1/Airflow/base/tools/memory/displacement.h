#pragma once
#include <Windows.h>

class c_address;

namespace modules
{
	extern HMODULE client;
	extern HMODULE server;
	extern HMODULE engine;
	extern HMODULE materialsystem;
	extern HMODULE tier0;
	extern HMODULE shaderapidx9;
	extern HMODULE vgui2;
	extern HMODULE inputsystem;
	extern HMODULE vstdlib;
	extern HMODULE localize;
	extern HMODULE datacache;
	extern HMODULE studiorender;
	extern HMODULE vguimatsurface;
	extern HMODULE vphysics;
	extern HMODULE gameoverlayrenderer;
	extern HMODULE ntdll;

	extern void init();
}

namespace patterns
{
	extern c_address get_name;
	extern c_address init_key_values;
	extern c_address load_from_buffer;
	extern c_address list_leaves_in_box;
	extern c_address get_color_modulation;
	extern c_address draw_models;
	extern c_address using_static_prop_debug;
	extern c_address load_named_sky;
	extern c_address disable_post_process;
	extern c_address post_process_data;
	extern c_address return_addr_drift_pitch;
	extern c_address return_addr_apply_shake;
	extern c_address return_addr_maintain_seq_transitions;
	extern c_address remove_smoke;
	extern c_address remove_fog;
	extern c_address check_file_crc_with_server;
	extern c_address set_view_model_offsets;
	extern c_address prediction_random_seed;
	extern c_address prediction_player;
	extern c_address physics_run_think;
	extern c_address think;
	extern c_address move_helper;
	extern c_address beam;
	extern c_address add_view_model_bob;
	extern c_address calc_view_model_bob;
	extern c_address input;
	extern c_address player_resource;
	extern c_address game_rules;
	extern c_address inventory_access;
	extern c_address create_animstate;
	extern c_address reset_animstate;
	extern c_address update_animstate;
	extern c_address client_state;
	extern c_address set_abs_angles;
	extern c_address set_abs_origin;
	extern c_address should_skip_anim_frame;
	extern c_address modify_eye_position;
	extern c_address setup_bones;
	extern c_address setup_bones_base_player;
	extern c_address update_clientside_animation;
	extern c_address build_transformations;
	extern c_address standard_blending_rules;
	extern c_address do_extra_bone_processing;
	extern c_address return_addr_setup_velocity;
	extern c_address return_addr_accumulate_layers;
	extern c_address return_addr_reevaluate_anim_lod;
	extern c_address return_addr_extrapolation;
	extern c_address return_addr_setup_bones;
	extern c_address return_addr_loadout_allowed;
	extern c_address get_bone_merge;
	extern c_address get_pose_parameter;
	extern c_address update_merge_cache;
	extern c_address ik_context_ptr;
	extern c_address invalidate_bone_cache;
	extern c_address custom_player_ptr;
	extern c_address copy_to_follow;
	extern c_address copy_from_follow;
	extern c_address add_dependencies;
	extern c_address attachments_helper;
	extern c_address ik_ctx_construct;
	extern c_address ik_ctx_destruct;
	extern c_address ik_ctx_init;
	extern c_address ik_ctx_update_targets;
	extern c_address ik_ctx_solve_dependencies;
	extern c_address bone_setup_init_pose;
	extern c_address accumulate_pose;
	extern c_address bone_setup_calc_autoplay_sequences;
	extern c_address bone_setup_calc_bone_adjust;
	extern c_address studio_hdr_ptr;
	extern c_address accumulate_pose_debug_break;
	extern c_address invalidate_physics_recursive;
	extern c_address trace_filter;
	extern c_address trace_filter_skip_entities;
	extern c_address modify_body_yaw;
	extern c_address lookup_bone;
	extern c_address physics_simulate;
	extern c_address write_user_cmd;
	extern c_address send_move_addr;
	extern c_address view_render;
	extern c_address post_think_physics;
	extern c_address simulate_player_simulated_entities;
	extern c_address cl_move;
	extern c_address glow_object;
	extern c_address draw_hitbox;
	extern c_address server_edict;
	extern c_address model_renderable_animating;
	extern c_address setup_clr_modulation;
	extern c_address setup_clr_modulation_brushes;
	extern c_address calc_viewmodel_view;
	extern c_address set_collision_bounds;
	extern c_address get_hud_ptr;
	extern c_address find_hud_element;
	extern c_address clear_hud_weapons;
	extern c_address get_sequence_activity;
	extern c_address return_addr_cam_think;
	extern c_address send_net_msg;
	extern c_address assign_str;
	extern c_address process_packet;
	extern c_address direct_reset;
	extern c_address direct_present;
	extern c_address direct_device;
	extern c_address screen_matrix;
	extern c_address local;
	extern c_address global_vars;
	extern c_address interpolate_server_entities;
	extern c_address read_packets;
	extern c_address alloc_key_values_engine;
	extern c_address alloc_key_values_client;
	extern c_address calc_view;
	extern c_address add_renderable;
	extern c_address perform_screen_overlay;
	extern c_address render_glow_boxes;
	extern c_address clear_killfeed;
	extern c_address clip_ray_to_hitbox;
	extern c_address read_packets_return_addr;
	extern c_address compute_hitbox_surrounding_box;
	extern c_address clantag;
	extern c_address is_in_ironsight;
	extern c_address update_postscreen_effects;
	extern c_address is_breakable_entity;
	extern c_address on_bbox_change_callback;
	extern c_address process_interpolated_list;
	extern c_address allow_extrapolation;
	extern c_address get_exposure_range;
	extern c_address temp_entities;
	extern c_address calc_shotgun_spread;
	extern c_address line_goes_through_smoke;
	extern c_address send_datagram;
	extern c_address file_system_ptr;
	extern c_address item_system;
	extern c_address force_update;
	extern c_address trace_filter_to_head_collision;
	extern c_address want_reticle_shown;
	extern c_address return_addr_process_input;
	extern c_address update_visibility;
	extern c_address viewmodel_arm_cfg;
	extern c_address thread_id_allocated;
	extern c_address weapon_shootpos;
	extern c_address mask_ptr;
	extern c_address update_addon_models;
	extern c_address update_all_viewmodel_addons;
	extern c_address get_viewmodel;
	extern c_address viewmodel_interpolate;
	extern c_address host_shutdown;
	extern c_address note_pred_error;
	extern c_address construct_voice_data_message;
	extern c_address destruct_voice_data_message;
	extern c_address msg_voice_data;
	extern c_address put_attachments;
	extern c_address calc_absolute_position;
	extern c_address eye_angles;
	extern c_address eye_pos_and_vectors;
	extern c_address draw_renderable_;
	extern c_address draw_brushes;
	extern c_address draw_model_cbase;
	extern c_address get_weapon_prefix;
	extern c_address find_mapping;
	extern c_address select_sequence_from_mods;
	extern c_address vac_bypass;
	extern c_address compensate_pred_errors;
	extern c_address reset_latched;
	extern c_address teleported;
	extern c_address base_interpolate_part1;
	extern c_address interpolate_player;
	extern c_address start_sound_immediate;
	extern c_address process_spotted_entity_update;
	extern c_address cl_fireevents;
	extern c_address weapon_system;
	extern c_address get_sequence_linear_motion;
	extern c_address lookup_sequence;
	extern c_address update_layer_order_preset;
	extern c_address get_sequence_desc;

	extern void init();
}