#pragma once
#include<stdio.h>
#include <windows.h>
#include "console_event.h"
#include "score_event.h"

void initGame();
void initBoard();
void initInfo(int);
void write_Stage(int);

void initGame() {
	SetConsoleTitle("Zombie Servival");
	SetConsoleSize(120, 40);
	SetCursor(false);
	initBoard();
	initInfo(get_High_Score());
}

void initBoard() {
	SetColor(0, 3);
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 80; j ++) {
			if ((i % 30 == 0 && j % 2 == 0 ) || j % 80 == 0) {
				GotoXY(1 + j, 5 + i);
				printf("■");
			}
			else {
				GotoXY(1 + j, 5 + i);
				printf("  ");
			}
		}
	}
	SetColor(0, 15);
}

void initInfo(int high_score) {
	SetColor(0, 12);
	GotoXY(87, 6);
	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆");
	GotoXY(93, 7);
	printf("Zombie Servival");
	GotoXY(87, 8);
	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆");
	SetColor(0, 13);
	GotoXY(87, 12);
	printf("최고 점수: %d",high_score);
	GotoXY(87, 15);
	SetColor(0, 3);
	printf("현재 점수:                       ");
	SetColor(0, 10);
	GotoXY(93, 18);
	printf("☆☆☆☆☆☆☆☆☆");
	GotoXY(93, 19);
	printf("☆   STAGE      ☆");
	GotoXY(93, 20);
	printf("☆☆☆☆☆☆☆☆☆");
	SetColor(0, 6);
	GotoXY(87, 23);
	printf("게임설명");
	GotoXY(87, 25);
	printf("주인공 방향: 방향키");
	GotoXY(87, 27);
	printf("공격 & 공격방향:");
	GotoXY(87, 29);
	printf("위W 왼쪽A 오른쪽S 아래D");
	GotoXY(87, 31);
	printf("다시하기 : R");
	GotoXY(87, 33);
	printf("게임속도 :");
	GotoXY(87, 34);
	printf("1 = EASY 2 = NORMAL 3 = HARD");
	GotoXY(87, 37);
	printf("몰려오는 좀비를 무찌르고");
	GotoXY(87, 38);
	printf("최대한 오래 살아남으세요");
	SetColor(0, 15);
}

void write_Stage(int stage) {
	GotoXY(105, 19);
	SetColor(0,9);
	printf("%d", stage);
	SetColor(0, 15);
}