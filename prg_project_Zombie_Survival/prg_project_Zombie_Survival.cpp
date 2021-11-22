#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "console_event.h"
#include "character_member.h"
#include "hero_event.h"
#include "bullet_event.h"
#include "zombie_event.h"
#include "common_event.h"
#include "screen_view.h"
#include "score_event.h"
#define TIME 1
#define NORMAL 50


int main() {
	int game_time = 0;
	int count_killed_zombie = 0;
	int score = 0;
	int stage = 1;
	int game_speed = NORMAL;

	HERO	_player = {true, 14, 28};
	HERO* player;
	player = &_player;

	ZOMBIE entire_Zombie[200];
	int z_index = 0;

	BULLET entire_Bullet[100];
	int b_index = 0;
	

	initGame();
	game_Start(entire_Zombie,entire_Bullet);

	while (1) {

		if (player->status) {

			game_time += 1;
			set_Game_Speed(&game_speed);
			count_Score(game_time, &count_killed_zombie, &score, stage, game_speed);
			write_Stage(stage);

			if (is_Hero_Attacked(entire_Zombie, player->loc_x, player->loc_y)) {
				game_Over(entire_Zombie, score);
				player->status = false;
			}

			move_Bullet(entire_Zombie, entire_Bullet, player->loc_x, player->loc_y, &count_killed_zombie);

			if (set_function_interval(TIME*2, &game_time)) {
				move_Hero(player, player->loc_x, player->loc_y);
			}
			if (set_function_interval(TIME*4, &game_time)) {
				make_Bullet(&b_index, entire_Bullet, player->loc_x, player->loc_y);
				move_Zombie(entire_Zombie, player->loc_x, player->loc_y);
			}
			if (set_function_interval(TIME * 12 - ((stage-1) * 2), &game_time)){
				make_Zombie(&z_index, entire_Zombie);
			}
			if (set_function_interval(TIME * 200, &game_time) && stage <= 6) {
				stage += 1;
			}
		}

		else {
			game_time = 0;
			count_killed_zombie = 0;
			stage = 1;
			retry_Game(player,entire_Zombie,entire_Bullet);
		}
		Sleep(game_speed);
	}
}
