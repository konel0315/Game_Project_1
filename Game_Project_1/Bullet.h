#pragma once
#include <string>
#include <vector>
using namespace std;


class Bullet 
{
	float speed=0;
	int damage=0;
	string type;//총알 타입
	
public:
	int owner;
	struct position {
		int x;
		int y;
	};
	position pos;
	Bullet(int x, int y,int owner) 
	{
		this->pos.x = x;
		this->pos.y = y;
		this->owner = owner;//0은 user 1은 enemy
	};

};
