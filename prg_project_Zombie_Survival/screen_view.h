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
				printf("��");
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
	printf("�ߡߡߡߡߡߡߡߡߡߡߡߡ�");
	GotoXY(93, 7);
	printf("Zombie Servival");
	GotoXY(87, 8);
	printf("�ߡߡߡߡߡߡߡߡߡߡߡߡ�");
	SetColor(0, 13);
	GotoXY(87, 12);
	printf("�ְ� ����: %d",high_score);
	GotoXY(87, 15);
	SetColor(0, 3);
	printf("���� ����:                       ");
	SetColor(0, 10);
	GotoXY(93, 18);
	printf("�١١١١١١١١�");
	GotoXY(93, 19);
	printf("��   STAGE      ��");
	GotoXY(93, 20);
	printf("�١١١١١١١١�");
	SetColor(0, 6);
	GotoXY(87, 23);
	printf("���Ӽ���");
	GotoXY(87, 25);
	printf("���ΰ� ����: ����Ű");
	GotoXY(87, 27);
	printf("���� & ���ݹ���:");
	GotoXY(87, 29);
	printf("��W ����A ������S �Ʒ�D");
	GotoXY(87, 31);
	printf("�ٽ��ϱ� : R");
	GotoXY(87, 33);
	printf("���Ӽӵ� :");
	GotoXY(87, 34);
	printf("1 = EASY 2 = NORMAL 3 = HARD");
	GotoXY(87, 37);
	printf("�������� ���� �����");
	GotoXY(87, 38);
	printf("�ִ��� ���� ��Ƴ�������");
	SetColor(0, 15);
}

void write_Stage(int stage) {
	GotoXY(105, 19);
	SetColor(0,9);
	printf("%d", stage);
	SetColor(0, 15);
}