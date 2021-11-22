#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include"console_event.h"
#include "character_member.h"


void	init_Entire_Bullet(BULLET*);
void save_Bullet(int, BULLET*, int, int, int, int);
void make_Bullet(int*, BULLET*, int, int);
void move_Bullet(ZOMBIE*, BULLET*, int, int, int*);
bool is_Blocked(int, int);
bool attack_Zombie(ZOMBIE*, int, int, int*);



void init_Entire_Bullet(BULLET* arr) {
	for (int i = 0; i < 100; i++) {
		arr[i] = { false, 0, 0, 0, 0 };
	}
}

void save_Bullet(int index, BULLET* bullet, int x, int y, int direction_x, int direction_y) {
	bullet[index].status = true;
	bullet[index].direction_x = direction_x;
	bullet[index].direction_y = direction_y;
	bullet[index].loc_x = x;
	bullet[index].loc_y = y;
}

void make_Bullet(int* index, BULLET* entire_Bullet, int hero_x, int hero_y) {

	if (*index == 100)
		*index = 0;


	if (GetAsyncKeyState(0x41) & 0x8000 && hero_x > 2) {
		save_Bullet(*index, entire_Bullet, hero_x, hero_y, -2, 0);
		*index += 1;
	}//A
	else if (GetAsyncKeyState(0x44) & 0x8000 && hero_x < 78) {
		save_Bullet(*index, entire_Bullet, hero_x, hero_y, 2, 0);
		*index += 1;
	}//D
	else if (GetAsyncKeyState(0x57) & 0x8000 && hero_y > 6) {
		save_Bullet(*index, entire_Bullet, hero_x, hero_y, 0, -1);
		*index += 1;
	}//W
	else if (GetAsyncKeyState(0x53) & 0x8000 && hero_y < 34) {
		save_Bullet(*index, entire_Bullet, hero_x, hero_y, 0, 1);
		*index += 1;
	}//S
}

void move_Bullet(ZOMBIE* entire_Zombie, BULLET* entire_Bullet, int hero_x, int hero_y, int* count_kill_zombie) {

	for (int i = 0; i < 100; i++) {
		if (entire_Bullet[i].status) {

			int x = entire_Bullet[i].loc_x;
			int y = entire_Bullet[i].loc_y;

			if (is_Blocked(x + entire_Bullet[i].direction_x, y + entire_Bullet[i].direction_y) || attack_Zombie(entire_Zombie, x, y, count_kill_zombie)) {
				entire_Bullet[i].status = false;
				GotoXY(x, y);
				printf("  ");
			}
			else {
				if (hero_x != x || hero_y != y) {
					GotoXY(x, y);
					printf("  ");
				}
				x += entire_Bullet[i].direction_x;
				y += entire_Bullet[i].direction_y;
				GotoXY(x, y);
				SetColor(0, 11);
				printf("им");
				SetColor(0, 15);

				entire_Bullet[i].loc_x = x;
				entire_Bullet[i].loc_y = y;
			}
		}
	}
}

bool is_Blocked(int x, int y) {
	if (x >= 4 && x <= 78) {
		if (y >= 6 && y <= 34) {
			return false;
		}
	}
	return true;

}

bool attack_Zombie(ZOMBIE* entire_Zombie, int x, int y, int* count_kill_zombie) {
	for (int i = 0; i < 200; i++) {
		if (entire_Zombie[i].status) {
			if (entire_Zombie[i].loc_x == x && entire_Zombie[i].loc_y == y) {
				entire_Zombie[i].status = false;
				*count_kill_zombie += 1;
				return true;
			}
		}
	}
	
		

	return false;
}