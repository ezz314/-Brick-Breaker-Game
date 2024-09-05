#include "WindGlide.h"
#include"game.h"

WindGlide::WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame, paddle* p): Collectables(r_uprleft, r_width, r_height, r_pGame,p)
{
	image = "images\\Collectables\\WindGlide.jpg";
	setImageName(image);
}

void WindGlide::collisionAction()
{
	char key;
	int elaspT = 0;
	clock_t s_time = clock();
	int pk = pGame->getWind()->GetKeyPress(key);
	while (elaspT<1)
	{
		if (pk == 6) {
			if (pad->getuprleft().x >= config.wx) {
				pad->getgame()->getWind()->SetPen(LAVENDER, 1);
				pad->getgame()->getWind()->SetBrush(LAVENDER);
				pad->getgame()->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + width, uprLft.y + height);
				pad->setuprleftx(getuprleft().x - 40);
				pad->draw();
			}
		}
		else if (pk == 4) {
			if (pad->getuprleft().x + config.paddleWidth <= config.wx + config.windWidth - 20) {
				pad->getgame()->getWind()->SetPen(LAVENDER, 1);
				pad->getgame()->getWind()->SetBrush(LAVENDER);
				pad->getgame()->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + width, uprLft.y + height);
				pad->setuprleftx(getuprleft().x + 40);
				pad->draw();
			}
		}
		elaspT = static_cast<int>(s_time) / CLOCKS_PER_SEC / 60;
	}
}
