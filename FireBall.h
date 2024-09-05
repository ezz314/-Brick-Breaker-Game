#pragma once
#include"Collectables.h"


class FireBall :public Collectables
{
public:
	FireBall(point r_uprleft, int r_width, int r_height, game* r_pGame, paddle* p);
	void collisionAction();

};

