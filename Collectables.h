#pragma once
#include "paddle.h"
#include"collidable.h"
#include"gameConfig.h"

enum Coltype { UP, DOWN };
//enum CollectableType { RevD, Wg, fire ,Null }; /// Delete it if you won't use it  
class Collectables :public collidable
{
protected:
	//CollectableType ct;
	paddle* pad;
	string image;
public:
	Collectables(point r_uprleft, int r_width, int r_height, game* r_pGame, paddle* p);
	static int PickRandomCollectable(Coltype c) ;
	void moveCollectable();
};