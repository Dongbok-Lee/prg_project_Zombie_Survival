#pragma once

typedef struct hero{
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


//void Zombie();
//void Weapon();
//void bullet();