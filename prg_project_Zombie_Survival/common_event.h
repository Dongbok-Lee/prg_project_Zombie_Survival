#pragma once
#include <stdio.h>
#include <windows.h>
#include "console_event.h"
#include "character_member.h"
#include "hero_event.h"
#include "bullet_event.h"
#include "zombie_event.h"
#include "screen_view.h"
#include "score_event.h"
#define EASY 100
#define NORMAL 50
#define DIFFICULT 30


bool set_function_interval(int, int*);
void game_Over(ZOMBIE*, int);
void game_Start(ZOMBIE*, BULLET*);
void retry_Game(HERO*, ZOMBIE*, BULLET*);
void set_Game_Speed(int*);

bool set_function_interval(int interval, int* time) {
	return (*time % interval == 0);
}

void game_Over(ZOMBIE* entire_Zombie, int score) {
	GotoXY(37, 20);
	SetColor(0, 4);
	printf("Game Over");
	SetColor(0, 15);
	if (get_High_Score() < score)
		save_High_Score(score);
}

void game_Start(ZOMBIE* entire_Zombie, BULLET* entire_Bullet) {
	init_Entire_Bullet(entire_Bullet);
	init_Entire_Zombie(entire_Zombie);
}

void retry_Game(HERO* hero, ZOMBIE* entire_Zombie, BULLET* entire_Bullet){
	if (GetAsyncKeyState(0x52) & 0x8000) {
		hero->status = true;
		initBoard();
		initInfo(get_High_Score());
		init_Entire_Bullet(entire_Bullet);
		init_Entire_Zombie(entire_Zombie);
	}//R
}

void set_Game_Speed(int* speed) {
	if (GetAsyncKeyState(0x31) & 0x8000) {
		*speed = EASY;
	}
	else if (GetAsyncKeyState(0x32) & 0x8000) {
		*speed = NORMAL;
	}
	else if (GetAsyncKeyState(0x33) & 0x8000) {
		*speed = DIFFICULT;
	}
}