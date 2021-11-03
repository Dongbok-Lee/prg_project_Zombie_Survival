#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "console_event.h"
#include "character_member.h"
#include "character_event.h"
#include "screen_view.h"


int main() {

	HERO	_player = {14, 28};
	HERO* player;
	player = &_player;

	BULLET entire_Bullet[100];
	int _index = 0;
	int* index = &_index;
	

	initGame();
	init_Entire_Bullet(entire_Bullet);

	while (1) {
		make_Bullet(index, entire_Bullet, player->loc_x, player->loc_y);
		move_Bullet(entire_Bullet, player->loc_x, player->loc_y);

		move_Hero(player, player -> loc_x, player -> loc_y);

		Sleep(60);

	}
}
