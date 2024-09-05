#pragma once
#include"collidable.h"
#include"gameConfig.h"
class paddle :public collidable
{
	string image;
public:
	paddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void movepaddleleft();
	void movepaddleright();
	void collisionAction();
};

