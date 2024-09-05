#include "paddle.h"
#include"game.h"

paddle::paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) : collidable(r_uprleft, r_width, r_height, r_pGame)
{
	image = "images\\paddle.jpg";
	setImageName(image);
}

void paddle::movepaddleleft() {
	if (this->uprLft.x  >= config.wx ){
		pGame->getWind()->SetPen(LAVENDER, 1);
		pGame->getWind()->SetBrush(LAVENDER);
		pGame->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + width, uprLft.y + height);
		this->uprLft.x = uprLft.x - 20;
		this->draw();
	}
	
}

void paddle::movepaddleright()
{
	if(this->uprLft.x+config.paddleWidth<=config.wx+config.windWidth-20){
		pGame->getWind()->SetPen(LAVENDER, 1);
		pGame->getWind()->SetBrush(LAVENDER);
		pGame->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + width, uprLft.y + height);
		this->uprLft.x = uprLft.x + 20;
		this->draw();
	}
	
}

void paddle::collisionAction()
{
}


