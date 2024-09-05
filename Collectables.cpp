#include "Collectables.h"
#include "FireBall.h"
#include "WindGlide.h"
#include "ReverseDirection.h"
#include "game.h"
#include <cstdlib>
Collectables::Collectables(point r_uprleft, int r_width, int r_height, game* r_pGame, paddle* p) : collidable(r_uprleft, r_width, r_height, r_pGame)
{
	pad = p;
	moveCollectable();
}

int Collectables::PickRandomCollectable(Coltype c) 
{
	srand(10);
	if (c == UP) {
		int NumOfPupColl = 2;
		return 1 + rand() % (NumOfPupColl);
	}
	else {
		int NumOfPdownColl = 1;
		return 1 + rand() % (NumOfPdownColl);
	}
}

void Collectables::moveCollectable()
{

	window* pwind = pGame->getWind();
	if (this->uprLft.y != config.windHeight + config.wy) {
		pwind->SetPen(LAVENDER, 1);
		pwind->SetBrush(LAVENDER);
		pwind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + 2 * config.collecSide, uprLft.y + 2 * config.collecSide); //2* because less than this won't delete the prev rect totally
		this->uprLft.y += 6;
		this->draw();
	}

	pwind->UpdateBuffer();
}