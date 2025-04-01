#pragma once
#include <string>
using namespace std;

class Bullet 
{
	float speed;
	int damage;
	string type;
public:
	struct position {
		int x;
		int y;
	};
	Bullet(int x, int y) 
	{
		this->pos.x = x;
		this->pos.y = y;
	};
	position pos;
	vector<int> CreateBullet(int x, int y);

};