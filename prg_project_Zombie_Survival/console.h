#pragma once


#include <windows.h>

//──────────────────────────────────────────────────────
// 화면을 지워주고 커서의 위치를 0,0 으로 이동시키는 함수
//──────────────────────────────────────────────────────
void Clear(void);
//──────────────────────────────────────────────────────
// 커서의 위치를 _x, _y 로 변경하는 함수
//──────────────────────────────────────────────────────
void GotoXY(int _x, int _y);
//──────────────────────────────────────────────────────
// console 창의 title을 변경해 주는 함수
//──────────────────────────────────────────────────────
void SetTitle(char* _szConsoleName);
//──────────────────────────────────────────────────────
// 배경색, 글자색을 변경해 주는 함수
//──────────────────────────────────────────────────────
void SetColor(unsigned char _BgColor, unsigned char _TextColor);
//──────────────────────────────────────────────────────
// cursor를 보이게, 안보이게 하는 함수 
//──────────────────────────────────────────────────────
void SetCursor(BOOL _bShow);
//──────────────────────────────────────────────────────
// console 창의 크기를 정하는 함수 ( 디폴트 80, 25 )
//──────────────────────────────────────────────────────
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