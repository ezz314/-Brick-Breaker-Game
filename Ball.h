#pragma once
#include "collidable.h"
#include "Bricks.h"


class Ball :public collidable
{
protected:
	int Xinc, Yinc;
	color c;
public:
	Ball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void draw(color c, window*);
	void ball_Movement();
	void collisionAction();
	void setprevuprlefty(int y) { this->uprLft.y = y; }
	void resetcenter();
};