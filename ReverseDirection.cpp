#include "ReverseDirection.h"
#include"game.h"

ReverseDirection::ReverseDirection(point r_uprleft, int r_width, int r_height, game* r_pGame, paddle* p) :Collectables(r_uprleft,r_width, r_height, r_pGame,p) {
	image = "images\\Collectables\\ReverseDirection.jpg";
	setImageName(image);
}
void ReverseDirection::collisionAction()
{
	char key;
	int elaspT=0;
	pGame->getWind()->GetKeyPress(key);
	clock_t s_time = clock();
	while (elaspT < 2) {
		if (key == 4) pad->movepaddleright();
		else if (key == 6) pad->movepaddleleft();
		elaspT = static_cast<int>(s_time) / CLOCKS_PER_SEC / 60;
	}

}
