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
	printf("�ߡߡߡߡߡߡߡߡߡߡߡߡ�");
	GotoXY(93, 7);
	printf("Zombie Servival");
	GotoXY(87, 8);
	printf("�ߡߡߡߡߡߡߡߡߡߡߡߡ�");
	GotoXY(87, 12);
	printf("�ְ� ����: ");
	GotoXY(87, 15);
	printf("���� ����: ");
	GotoXY(93, 18);
	printf("�١١١١١١١١�");
	GotoXY(93, 19);
	printf("��   STAGE      ��");
	GotoXY(93, 20);
	printf("�١١١١١١١١�");
	GotoXY(87, 23);
	printf("���Ӽ���");
	GotoXY(87, 25);
	printf("���ΰ� ����: ����Ű");
	GotoXY(87, 27);
	printf("���� & ���ݹ���:");
	GotoXY(87, 29);
	printf("��W ����A ������S �Ʒ�D");
	GotoXY(87, 31);
	printf("�������� ���� �����");
	GotoXY(87, 34);
	printf("�ִ��� ���� ��Ƴ�������");

}