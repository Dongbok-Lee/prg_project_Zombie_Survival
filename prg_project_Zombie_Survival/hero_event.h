#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include"console_event.h"
#include "character_member.h"

void move_Hero(HERO* hero, int, int);

void move_Hero(HERO* hero, int x, int y) {

	if (GetAsyncKeyState(VK_LEFT) & 0x8000 && x > 2) {
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
	printf("¡Ú");
	hero->loc_x = x, hero->loc_y = y;
}




