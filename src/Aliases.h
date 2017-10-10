#pragma once

#define screen_width 1600
#define screen_hight 900

#define menu_plate_x 0
#define menu_plate_y screen_hight - 108 - i * 110
#define menu_text_y menu_plate_y + 20

#define pause_between_press 0.25

#define Scroll_Shooter_text 4
#define Race_text 3
#define Shooter_text 2
#define Control_text 1
#define Exit_text 0

#define Scroll_Shooter_background_scale_x float(screen_width) / 275.0
#define Scroll_Shooter_background_scale_y float(screen_hight) / 183.0
#define Race_background_scale_x float(screen_width) / 275.0
#define Race_background_scale_y float(screen_hight) / 183.0
#define Shooter_background_scale_x float(screen_width) / 3542.0
#define Shooter_background_scale_y float(screen_hight) / 1494.0

#define background_speed 0.6

#define RIGHT 0
#define LEFT 1
#define DOWN 2
#define UP 3
#define UP_LEFT 4
#define UP_RIGHT 5
#define DOWN_RIGHT 6
#define DOWN_LEFT 7
#define STAY 8

#define player_side 1
#define enemies_side 0

#define aim_width 69
#define aim_hight 100

#define bullet_width 6
#define bullet_hight 15

#define player_spawn_x 750
#define player_spawn_y 650
#define player_width 70
#define player_hight 150
#define player_speed 0.7
#define player_spawn_health 100
#define Scroll_Shooter_player_time_between_shots 0.25
#define Shooter_player_time_between_shots 0.5
#define Scroll_Shooter_player_damage_per_shot 20
#define Shooter_player_damage_per_shot 20
#define Effects_player_spawn_x player.get_x() + player.get_w() / 2
#define Effects_player_spawn_y player.get_y() + player.get_h() / 2
#define player_shot_1point_x player.get_x() + 15
#define player_shot_2point_x player.get_x() + 55 - bullet_width
#define player_shot_1point_y player.get_y()
#define player_shot_2point_y player.get_y()
#define player_bullet_speed 1

#define Scroll_Shooter_effects_shooting_width 35
#define Scroll_Shooter_effects_shooting_hight 36
#define Scroll_Shooter_effects_shooting_speed 0
#define Scroll_Shooter_effects_shooting_exist_time 0.03

#define Shooter_effects_shooting_width 181
#define Shooter_effects_shooting_hight 166
#define Shooter_effects_shooting_speed 0
#define Shooter_effects_shooting_exist_time 0.1

#define Effects_spawn_x e->get_x() + e->get_w() / 2
#define Effects_spawn_y e->get_y() + e->get_h() / 2

#define Effects_bullets_spawn_x b->get_x() + b->get_w() / 2
#define Effects_bullets_spawn_y b->get_y() + b->get_h() / 2

#define effects_explosion1_width 67
#define effects_explosion1_hight 69
#define effects_explosion1_exist_time 0.1

#define effects_explosion2_width 151
#define effects_explosion2_hight 150
#define effects_explosion2_exist_time 0.25

#define interface_plate_width 448
#define interface_plate_hight 108
#define interface_plate_x screen_width - interface_plate_width
#define interface_plate_y screen_hight - interface_plate_hight
#define interface_text_x screen_width - 400
#define interface_text_y screen_hight - 120

#define Scroll_Shooter_game_difficulty 5000								//
#define Scroll_Shooter_max_game_difficulty 1000							//
#define Scroll_Shooter_background_object_probability 3000				//
#define Race_game_difficulty 2000										//
#define Race_max_game_difficulty 1000									//
#define Race_background_object_probability 3000							//„ем выше значени€ тем реже по€вл€ютс€ объекты
#define Shooter_game_difficulty 50000									//
#define Shooter_background_object_probability 6000						//
#define Shooter_max_game_difficulty 5000								//

#define Compensating_for_performance_losses_coefficient Compensating_for_performance_losses_time / 800

#define Scroll_Shooter_background_object_spawn_x rand() % screen_width
#define Scroll_Shooter_background_object_spawn_y -200
#define Race_background_object_spawn_x rand() % screen_width
#define Race_background_object_spawn_y -200
#define Shooter_background_object_spawn_x screen_width + 200
#define Shooter_background_object_spawn_y rand() % 350 + 550

#define background_rocksand1_width 113
#define background_rocksand1_hight 127
#define background_rocksand2_width 78
#define background_rocksand2_hight 70
#define background_rockgray1_width 93
#define background_rockgray1_hight 65

#define Scroll_Shooter_enemy_up_spawn_x rand() % (screen_width - 100) + 100
#define Scroll_Shooter_enemy_up_spawn_y -300

#define Scroll_Shooter_enemy_down_spawn_x rand() % (screen_width - 100) + 100
#define Scroll_Shooter_enemy_down_spawn_y screen_hight + 300

#define Scroll_Shooter_enemy_battlemule_width 90
#define Scroll_Shooter_enemy_battlemule_hight 150
#define Scroll_Shooter_enemy_battlemule_speed 0.15
#define Scroll_Shooter_enemy_battlemule_health 25
#define Scroll_Shooter_enemy_battlemule_time_between_attack 0.7
#define Scroll_Shooter_enemy_battlemule_damage 5

#define Scroll_Shooter_enemy_impalabattle_width 70
#define Scroll_Shooter_enemy_impalabattle_hight 150
#define Scroll_Shooter_enemy_impalabattle_speed 0.2
#define Scroll_Shooter_enemy_impalabattle_health 15
#define Scroll_Shooter_enemy_impalabattle_time_between_attack 0.7
#define Scroll_Shooter_enemy_impalabattle_damage 5

#define Scroll_Shooter_enemy_slage_width 142
#define Scroll_Shooter_enemy_slage_hight 295
#define Scroll_Shooter_enemy_slage_speed 0.15
#define Scroll_Shooter_enemy_slage_health 45
#define Scroll_Shooter_enemy_slage_time_between_attack 2
#define Scroll_Shooter_enemy_slage_damage 15

#define enemy_shot_point_x e->get_x() + e->get_w() / 2
#define enemy_shot_down_point_y e->get_y() + e->get_h()
#define enemy_shot_up_point_y e->get_y()
#define enemy_bullet_speed 0.5

#define Race_enemy_spawn_x rand() % screen_width
#define Race_enemy_spawn_y -200

#define Race_hedges_deadcars1_width 96
#define Race_hedges_deadcars1_hight 111
#define Race_hedges_deadcars1_health 10

#define Race_hedges_deadcars2_width 96
#define Race_hedges_deadcars2_hight 111
#define Race_hedges_deadcars2_health 10

#define Shooter_enemy_spawn_x -200
#define Shooter_enemy_spawn_y rand() % 350 + 450

#define Shooter_enemy_copsjups_width 198
#define Shooter_enemy_copsjups_hight 109
#define Shooter_enemy_copsjups_speed 0.3
#define Shooter_enemy_copsjups_health 35
#define Shooter_enemy_copsjups_time_between_attack 10
#define Shooter_enemy_copsjups_damage 10

#define Shooter_enemy_hammer_width 198
#define Shooter_enemy_hammer_hight 109
#define Shooter_enemy_hammer_speed 0.3
#define Shooter_enemy_hammer_health 25
#define Shooter_enemy_hammer_time_between_attack 10
#define Shooter_enemy_hammer_damage 15

#define Shooter_enemy_lapdcar_width 198
#define Shooter_enemy_lapdcar_hight 109
#define Shooter_enemy_lapdcar_speed 0.4
#define Shooter_enemy_lapdcar_health 15
#define Shooter_enemy_lapdcar_time_between_attack 5
#define Shooter_enemy_lapdcar_damage 5