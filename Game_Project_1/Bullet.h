#pragma once
#include <string>
#include <vector>
using namespace std;


class Bullet 
{
public:
	int owner;
	struct position {
		int x;
		int y;
	};
	string type;
	int dx = 0;
	int dy = 0;
	position pos;
	Bullet(int x, int y,int owner,string type = "basic")
	{
		this->pos.x = x;
		this->pos.y = y;
		this->owner = owner;//0Àº user 1Àº enemy
		this->type = type;
		if (type == "mirror") 
		{
			//dx = 1;
			dy = (owner == 0) ? -1 : 1;
		}
	};

};
