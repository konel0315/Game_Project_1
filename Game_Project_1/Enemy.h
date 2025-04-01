#pragma once
#include "Bullet.h"


class Enemy
{
	struct position
	{
		int x;
		int y;
	};
	int health;
	Bullet bulletType;

public:
	void move(int *position_x, int *position_y);
	void shoot(Bullet bulletType);
};