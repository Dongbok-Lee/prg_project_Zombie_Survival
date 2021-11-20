#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include"console_event.h"
#include "character_member.h"

void init_Entire_Zombie(ZOMBIE*);
void save_Zombie(int, ZOMBIE*, int ,int);
void make_Zombie(int*, ZOMBIE*);
void move_Zombie(ZOMBIE*, BULLET*,	int, int);
bool zombie_is_blocked(BULLET*, int, int, int, int);

void init_Entire_Zombie(ZOMBIE* arr) {
	for (int i = 0; i < 100; i++) {
		arr[i] = { false, 0, 0};
	}
}

void save_Zombie(int index, ZOMBIE* zombie, int x, int y) {
	zombie[index].status = true;
	zombie[index].loc_x = x;
	zombie[index].loc_y = y;
}

void make_Zombie(int* index, ZOMBIE* entire_zombie) {

	if (*index == 99)
		*index = 0;

	srand(GetTickCount64());
	int side = rand() % 4;

	switch (side) {
		case 0:
		{
			int rand_loc = 2*(rand() % 37)+ 2;
			save_Zombie(*index, entire_zombie, rand_loc, 6);
			*index += 1;
			break;
		}
		case 1:
		{
			int rand_loc_1 = 2*(rand() % 37) +2;
			save_Zombie(*index, entire_zombie, rand_loc_1, 34);
			*index += 1;
			break;
		}
		case 2:
		{
			int rand_loc_2 = rand() % 29 + 6;
			save_Zombie(*index, entire_zombie, 2, rand_loc_2);
			*index += 1;
			break;
		}
		case 3:
		{
			int rand_loc_3 = rand() % 29 + 6;
			save_Zombie(*index, entire_zombie,  78, rand_loc_3);
			*index += 1;
			break;
		}
	}
}
void move_Zombie(ZOMBIE * entire_Zombie, BULLET* entire_Bullet, int hero_x, int hero_y) {
	for (int i = 0; i < 100; i++) {
		if (entire_Zombie[i].status) {

			int x = entire_Zombie[i].loc_x;
			int y = entire_Zombie[i].loc_y;

			if (zombie_is_blocked(entire_Bullet, x, y, hero_x, hero_y) || is_Blocked(x, y)) {
				entire_Zombie[i].status = false;
				GotoXY(x, y);
				printf("  ");
			}
			else {
				GotoXY(x, y);
				printf("  ");

				if (abs(hero_x - x) > abs(hero_y - y)) {
					x+= (hero_x-x)/ abs(hero_x - x) * 2;
				}
				else {
					y += (hero_y - y) / abs(hero_y - y);
				}

				GotoXY(x, y);
				printf("¡ß");

				entire_Zombie[i].loc_x = x;
				entire_Zombie[i].loc_y = y;
			}
		}
	}
}

bool zombie_is_blocked(BULLET* entire_Bullet,int x, int y, int hero_x, int hero_y) {
	if (x == hero_x && y == hero_y)
		return true;
	for (int i = 0; i < 100; i++) {
		if (entire_Bullet[i].loc_x == x && entire_Bullet[i].loc_y == y) {
			return true;
		}
	}

	return false;
}