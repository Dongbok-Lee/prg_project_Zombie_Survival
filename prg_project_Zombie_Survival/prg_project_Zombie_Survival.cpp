#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "console.h"


int main() {
	SetConsoleTitle("Zombie Servival");

	int x = 14, y = 28;
	SetConsoleSize(100, 40);
	printf("Hello World");
	SetCursor(false);
	while (1) {
		Clear();
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			x--;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			x++;
		}

		GotoXY(x, y);
		printf("★");
		Sleep(10);
	}
}
