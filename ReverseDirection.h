#pragma once
#include"Collectables.h"

class ReverseDirection :public Collectables
{
public:
	ReverseDirection(point r_uprleft, int r_width, int r_height, game* r_pGame,paddle* p);
	void collisionAction();
};

