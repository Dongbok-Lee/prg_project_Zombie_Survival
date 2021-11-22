#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include"console_event.h"
#include "character_member.h"

void move_Hero(HERO* hero, int, int);
bool is_Hero_Attacked(ZOMBIE*, int, int);

void move_Hero(HERO* hero, int x, int y) {

	if (GetAsyncKeyState(VK_LEFT) & 0x8000 && x > 4) {
		GotoXY(x, y);
		printf("  ");
		x -= 2;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && x < 78) {
		GotoXY(x, y);
		printf("  ");
		x += 2;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000 && y > 6) {
		GotoXY(x, y);
		printf("  ");
		y--;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000 && y < 34) {
		GotoXY(x, y);
		printf("  ");
		y++;
	}
	GotoXY(x, y);
	SetColor(0, 14);
	printf("¡Ú");
	SetColor(0, 15);
	hero->loc_x = x, hero->loc_y = y;
}
bool is_Hero_Attacked(ZOMBIE* entire_Zombie, int hero_x, int hero_y) {
	
	for (int i = 0; i < 200; i++) {
		if (entire_Zombie[i].status) {
			int x = entire_Zombie[i].loc_x;
			int y = entire_Zombie[i].loc_y;
			if (hero_x == x && hero_y == y) {
				return true;
			}
		}
	}

	return false;
}



