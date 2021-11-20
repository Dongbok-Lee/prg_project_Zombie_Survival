#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "console_event.h"
#include "character_member.h"
#include "hero_event.h"
#include "bullet_event.h"
#include "zombie_event.h"
#include "screen_view.h"


int main() {

	int game_time = time(0);

	HERO	_player = {14, 28};
	HERO* player;
	player = &_player;

	ZOMBIE entire_Zombie[100];

	BULLET entire_Bullet[100];
	int _index = 0;
	int* index = &_index;
	

	initGame();
	init_Entire_Bullet(entire_Bullet);
	init_Entire_Zombie(entire_Zombie);

	while (1) {

		make_Bullet(index, entire_Bullet, player->loc_x, player->loc_y);
		move_Bullet(entire_Bullet, player->loc_x, player->loc_y);

		move_Hero(player, player -> loc_x, player -> loc_y);
		if (set_function_interval(1000, &time)) {
			make_Zombie(index, entire_Zombie);
		}
		move_Zombie(entire_Zombie, entire_Bullet, player->loc_x, player->loc_y);

		Sleep(100);

	}
}
