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
void move_Zombie(ZOMBIE*, int, int);


void init_Entire_Zombie(ZOMBIE* arr) {
	for (int i = 0; i < 200; i++) {
		arr[i] = { false, 0, 0};
	}
}

void save_Zombie(int index, ZOMBIE* zombie, int x, int y) {
	zombie[index].status = true;
	zombie[index].loc_x = x;
	zombie[index].loc_y = y;
}

void make_Zombie(int* index, ZOMBIE* entire_zombie) {

	if (*index == 200)
		*index = 0;

	srand(GetTickCount64());
	int side = rand() % 4;

	switch (side) {
		case 0:
		{
			int rand_loc = 2*(rand() % 37)+ 4;
			save_Zombie(*index, entire_zombie, rand_loc, 6);
			*index += 1;
			break;
		}
		case 1:
		{
			int rand_loc_1 = 2*(rand() % 37) +4;
			save_Zombie(*index, entire_zombie, rand_loc_1, 34);
			*index += 1;
			break;
		}
		case 2:
		{
			int rand_loc_2 = rand() % 29 + 6;
			save_Zombie(*index, entire_zombie, 4, rand_loc_2);
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

void move_Zombie(ZOMBIE * entire_Zombie, int hero_x, int hero_y) {
	for (int i = 0; i < 200; i++) {
		if (entire_Zombie[i].status) {

			int x = entire_Zombie[i].loc_x;
			int y = entire_Zombie[i].loc_y;

			GotoXY(x, y);
			printf("  ");

			if (abs(hero_x - x) > abs(hero_y - y) &&  hero_x != x) {
				x+= ((hero_x-x) / abs(hero_x - x)) * 2;
			}
			else if(hero_y != y){
				y += (hero_y - y) / abs(hero_y - y);
			}

			GotoXY(x, y);
			SetColor(0, 12);
			printf("¡Ü");
			SetColor(0, 15);
			entire_Zombie[i].loc_x = x;
			entire_Zombie[i].loc_y = y;
			
		}
	}
}