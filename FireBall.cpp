#include "FireBall.h"

FireBall::FireBall(point r_uprleft, int r_width, int r_height, game* r_pGame, paddle* p) :Collectables(r_uprleft, r_width, r_height, r_pGame, p)
{
	image = "images\\Collectables\\FireBall.jpg";
	setImageName(image);
}

void FireBall::collisionAction()
{
	
}
