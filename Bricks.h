#pragma once

//This file contains all classes bricks classes 
#include "collidable.h"

enum BrickType	//add more brick types
{
	BRK_NRM,	//Normal Brick
	BRK_HRD,	//Hard Brick
	BRK_ROCK,
	BRK_BOMB,
	BRK_PUP,
	BRK_PDOWN,
	BRK_CROSSBOMB


	//TODO: Add more types
};

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
//Base class for all bricks
class brick :public collidable
{
protected:
	int strength;
	BrickType type;
public:
	brick(point r_uprleft, int r_width, int r_height, game* r_pGame, BrickType t, int s);
	BrickType getBrickType() { return type; }
	int getstrength() { return strength; }
	void setstrength(int s) { strength = s; }

};


////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{
public:

	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void collisionAction() override;
};

//////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
class hardBrick :public brick
{
public:
	hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void collisionAction() override;
};

//////////////////////////////////////////////////////  class RockBrick  /////////////////////////////////
class RockBrick :public brick
{
public:
	RockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void collisionAction() override;

};

//////////////////////////////////////////////////////  class BombBrick  /////////////////////////////////
class BombBrick :public brick
{
public:
	BombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void collisionAction() override;

};

class CrossBombBrick :public brick
{
public:
	CrossBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void collisionAction() override;

};


class PowerUpBrick :public brick
{
public:
	PowerUpBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void collisionAction() override;

};


class PowerDownBrick :public brick
{
public:
	PowerDownBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void collisionAction() override;
};