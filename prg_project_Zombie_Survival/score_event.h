#pragma once
#include <stdio.h>
#include <windows.h>
#include "console_event.h"
#include "character_member.h"
#include "hero_event.h"
#include "bullet_event.h"
#include "zombie_event.h"
#include "screen_view.h"


void count_Score(int, int*, int*, int);
void save_High_Score(int);
int get_High_Score();

void count_Score(int game_time, int* killed_zombie, int* score, int stage, int game_speed) {
	*score = *killed_zombie * (200+stage*20) + game_time*(10 + stage + game_speed) ;
	GotoXY(98, 15);
	SetColor(0, 3);
	printf("%d", *score);
	SetColor(0, 15);
}
int get_High_Score(){

	FILE* fp;
	int h_score;
	
	fopen_s(&fp, "score.txt", "r");

	if (fp == NULL) {
		save_High_Score(0);
		fopen_s(&fp, "score.txt", "r");
	}

	fscanf_s(fp, "%d", &h_score);

	fclose(fp);

	return h_score;
}

void save_High_Score(int score) {
	FILE* fp;

	fopen_s(&fp, "score.txt", "w");

	fprintf(fp, "%d", score);
	fclose(fp);
}