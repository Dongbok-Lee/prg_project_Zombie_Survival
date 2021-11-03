#pragma once
#include <stdio.h>
#include <windows.h>
#include"console_event.h"
#include "character_member.h"

void move_Hero(HERO* hero, int, int);

void make_Bullet(int*, BULLET* , int, int);
void save_Bullet(int, BULLET*, int, int, int, int);
void	init_Entire_Bullet(BULLET*);
bool is_Blocked(int, int);

void move_Hero(HERO* hero, int x, int y) {
	
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 && x>2) {
		GotoXY(x,y);
		printf("  ");
		x -= 2;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && x<78) {
		GotoXY(x,y);
		printf("  ");
		x += 2;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000 && y>6) {
		GotoXY(x,y);
		printf("  ");
		y--;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000 && y<34) {
		GotoXY(x, y);
		printf("  ");
		y++;
	}
	GotoXY(x, y);
	printf("б┌");
	hero->loc_x = x, hero->loc_y = y;
}

void make_Bullet(int* index, BULLET* entire_Bullet, int hero_x, int hero_y) {

	if (*index == 100)
		*index = 0;


	if (GetAsyncKeyState(0x41) & 0x8000 && hero_x > 2) {
		save_Bullet(*index,entire_Bullet, hero_x, hero_y , -2, 0);
		*index+=1;
	}//A
	if (GetAsyncKeyState(0x44) & 0x8000 && hero_x < 78) {
		save_Bullet(*index, entire_Bullet, hero_x, hero_y, 2, 0);
		*index+=1;
	}//D
	if (GetAsyncKeyState(0x57) & 0x8000 && hero_y > 6) {
		save_Bullet(*index, entire_Bullet, hero_x, hero_y, 0, -1);
		*index += 1;
	}//W
	if (GetAsyncKeyState(0x53) & 0x8000 && hero_y < 34) {
		save_Bullet(*index, entire_Bullet, hero_x, hero_y, 0, 1);
		*index += 1;
	}//S
}

void save_Bullet(int index, BULLET* bullet,int x, int y, int direction_x, int direction_y) {
	bullet[index].status = true;
	bullet[index].direction_x = direction_x;
	bullet[index].direction_y = direction_y;
	bullet[index].loc_x = x;
	bullet[index].loc_y = y;
}

void move_Bullet(BULLET* entire_Bullet, int hero_x, int hero_y) {

	for (int i = 0; i < 100; i++) {
		if (entire_Bullet[i].status) {

			int x = entire_Bullet[i].loc_x;
			int y = entire_Bullet[i].loc_y;

			if (is_Blocked(x, y)) {
				entire_Bullet[i].status = false;
				GotoXY(x, y);
				printf("  ");
			}
			else {
				GotoXY(x, y);
				printf("  ");
				x += entire_Bullet[i].direction_x;
				y += entire_Bullet[i].direction_y;

				GotoXY(x, y);
				printf("им");
				
				entire_Bullet[i].loc_x = x;
				entire_Bullet[i].loc_y = y;
			}
		}
	}
}

void init_Entire_Bullet(BULLET*arr) {
	for (int i = 0; i < 100; i++) {
		arr[i] = { false, 0, 0, 0, 0 };
	}
}

bool is_Blocked(int x, int y) {
	if (x > 2 && x < 78) {
		if (y > 6 && y < 34) {
			return false;
		}
	}
	return true;
}