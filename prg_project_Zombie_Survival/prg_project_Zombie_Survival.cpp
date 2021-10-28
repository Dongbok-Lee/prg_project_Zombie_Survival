#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "console_event.h"
#include "character_member.h"
#include "character_event.h"
#include "screen_view.h"


int main() {

	HERO	_player = {14, 28};
	HERO* player;
	player = &_player;

	initGame();

	while (1) {
		makeHero(player);

		Sleep(30);

	}
}
