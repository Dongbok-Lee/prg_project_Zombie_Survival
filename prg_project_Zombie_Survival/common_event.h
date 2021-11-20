#pragma once
#include <stdio.h>
#include <windows.h>

bool set_function_interval(int, int*);
bool is_Blocked(int, int);

bool set_function_interval(int interval, int* time) {
	return (*time % interval == 0);
}

bool is_Blocked(int x, int y) {
	if (x >= 2 && x <= 78) {
		if (y >= 6 && y <= 34) {
			return false;
		}
	}
	return true;

}