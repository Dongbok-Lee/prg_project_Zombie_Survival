#pragma once
#include <stdio.h>
#include <windows.h>
#include"console_event.h"
#include "character_member.h"

void makeHero(HERO*);
void hero_Move(HERO* hero, int, int);


void makeHero(HERO* hero) {
	hero_Move(hero, hero->loc_x, hero->loc_y);
}

void hero_Move(HERO* hero, int x, int y) {
	
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		GotoXY(x,y);
		printf("  ");
		x -= 2;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		GotoXY(x,y);
		printf("  ");
		x += 2;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		GotoXY(x,y);
		printf("  ");
		y--;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		GotoXY(x, y);
		printf("  ");
		y++;
	}
	GotoXY(x, y);
	printf("¡Ú");
	hero->loc_x = x, hero->loc_y = y;
}