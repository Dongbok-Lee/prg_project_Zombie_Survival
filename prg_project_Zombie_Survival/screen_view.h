#pragma once
#include<stdio.h>
#include <windows.h>
#include "console_event.h"

void initGame();
void initBoard();
void initInfo();


void initGame() {
	SetConsoleTitle("Zombie Servival");
	SetConsoleSize(120, 40);
	SetCursor(false);
	initBoard();
	initInfo();
}

void initBoard() {
	char Board[31][100] = { ' ', };

	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 80; j += 2) {
			if (i % 30 == 0 || j % 80 == 0) {
				Board[i][j] = 'o';
				GotoXY(1 + j, 5 + i);
				printf("%c", Board[i][j]);
			}
		}
	}
}

void initInfo() {
	GotoXY(87, 6);
	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆");
	GotoXY(93, 7);
	printf("Zombie Servival");
	GotoXY(87, 8);
	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆");
	GotoXY(87, 12);
	printf("최고 점수: ");
	GotoXY(87, 15);
	printf("현재 점수: ");
	GotoXY(93, 18);
	printf("☆☆☆☆☆☆☆☆☆");
	GotoXY(93, 19);
	printf("☆   STAGE      ☆");
	GotoXY(93, 20);
	printf("☆☆☆☆☆☆☆☆☆");
	GotoXY(87, 23);
	printf("게임설명");
	GotoXY(87, 25);
	printf("주인공 방향: 방향키");
	GotoXY(87, 27);
	printf("공격 & 공격방향:");
	GotoXY(87, 29);
	printf("위W 왼쪽A 오른쪽S 아래D");
	GotoXY(87, 31);
	printf("몰려오는 좀비를 무찌르고");
	GotoXY(87, 34);
	printf("최대한 오래 살아남으세요");

}