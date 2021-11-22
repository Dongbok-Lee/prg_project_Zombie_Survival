#pragma once

typedef struct hero{
	bool status;
	int loc_x;
	int loc_y;
	//int speed;
}HERO;

typedef struct bullet {
	bool status;
	int loc_x;
	int loc_y;
	int direction_x;
	int direction_y;
}BULLET;


typedef struct zombie {
	bool status;
	int loc_x;
	int loc_y;
}ZOMBIE;
//void Weapon();
//void bullet();