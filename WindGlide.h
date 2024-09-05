#pragma once
#include"Collectables.h"
class WindGlide :public Collectables
{
	public:
	WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame, paddle* p);
	void collisionAction();
	
};

