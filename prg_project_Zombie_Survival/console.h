#pragma once


#include <windows.h>

//������������������������������������������������������������������������������������������������������������
// ȭ���� �����ְ� Ŀ���� ��ġ�� 0,0 ���� �̵���Ű�� �Լ�
//������������������������������������������������������������������������������������������������������������
void Clear(void);
//������������������������������������������������������������������������������������������������������������
// Ŀ���� ��ġ�� _x, _y �� �����ϴ� �Լ�
//������������������������������������������������������������������������������������������������������������
void GotoXY(int _x, int _y);
//������������������������������������������������������������������������������������������������������������
// console â�� title�� ������ �ִ� �Լ�
//������������������������������������������������������������������������������������������������������������
void SetTitle(char* _szConsoleName);
//������������������������������������������������������������������������������������������������������������
// ����, ���ڻ��� ������ �ִ� �Լ�
//������������������������������������������������������������������������������������������������������������
void SetColor(unsigned char _BgColor, unsigned char _TextColor);
//������������������������������������������������������������������������������������������������������������
// cursor�� ���̰�, �Ⱥ��̰� �ϴ� �Լ� 
//������������������������������������������������������������������������������������������������������������
void SetCursor(BOOL _bShow);
//������������������������������������������������������������������������������������������������������������
// console â�� ũ�⸦ ���ϴ� �Լ� ( ����Ʈ 80, 25 )
//������������������������������������������������������������������������������������������������������������
void SetConsoleSize(int _col, int _lines);

void Clear(void)
{
	system("cls");
}

void GotoXY(int _x, int _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetTitle(char* _szConsoleName)
{
	SetConsoleTitle(_szConsoleName);
}

void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void SetCursor(BOOL _bShow)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = _bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}