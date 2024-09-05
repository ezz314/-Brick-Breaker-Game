#include "Ball.h"
#include"game.h"
#include"gameConfig.h"
#include<cmath>

Ball::Ball(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
	Xinc = 0, Yinc = config.BallRad;
	c = RED;

}

void Ball::draw(color c, window* pWind)
{
	pWind = pGame->getWind();
	pWind->SetPen(c);
	pWind->SetBrush(c);
	pWind->DrawCircle(this->uprLft.x, this->uprLft.y, config.BallRad);
}

void Ball::ball_Movement()
{

	collisionAction();
	this->uprLft.x -= Xinc / 2;
	this->uprLft.y -= Yinc / 2;
}


void Ball::collisionAction()
{
	if ((this->uprLft.x <= config.BallRad) || (this->uprLft.x >= config.windWidth - 2*config.BallRad) ||
		(Collided(pGame->getPaddle(), this).isCollided && ((Collided(pGame->getPaddle(), this).side == RIGHT) ||
			(Collided(pGame->getPaddle(), this).side == LEFT)))) {
		Xinc = -Xinc;
	}


	else if ((this->uprLft.y <= config.BallRad + config.toolBarHeight+config.wy) ||
		(Collided(pGame->getPaddle(), this).isCollided && ((Collided(pGame->getPaddle(), this).side == UPPER)))) {
		if (Collided(pGame->getPaddle(), this).isCollided) {
			if (Xinc < 0) {
				Xinc = config.BallRad;
			}
			else {
				Xinc = -config.BallRad;

			}

			if (Yinc < 0) {
				Yinc = -config.BallRad;
				/*this->uprLft.y -= 5;*/
			}
			else
			{
				Yinc = config.BallRad;
				/*this->uprLft.y += 5;*/
			}

			Xinc = -Xinc * abs(cos(AngleCollision(pGame->getPaddle(), this) * (3.14 / 180)));
			Yinc = -Yinc * abs(sin(AngleCollision(pGame->getPaddle(), this) * (3.14 / 180)));


		}
		else {
			Yinc = -Yinc;
		}
	}


	for (int i = 0; i < (config.gridHeight / config.brickHeight); i++) {

		for (int j = 0; j < (config.windWidth / config.brickWidth); j++)
		{
			if (pGame->getBrickMatrix()[i][j] && Collided(pGame->getBrickMatrix()[i][j], this).isCollided &&
				(Collided(pGame->getBrickMatrix()[i][j], this).side == LOWER ||
					Collided(pGame->getBrickMatrix()[i][j], this).side == UPPER)) {
				Yinc = -Yinc;
				pGame->getBrickMatrix()[i][j]->collisionAction();
				break;
			}
			else if (pGame->getBrickMatrix()[i][j] && Collided(pGame->getBrickMatrix()[i][j], this).isCollided &&
				(Collided(pGame->getBrickMatrix()[i][j], this).side == LEFT ||
					Collided(pGame->getBrickMatrix()[i][j], this).side == RIGHT)) {
				Xinc = -Xinc;
				pGame->getBrickMatrix()[i][j]->collisionAction();
				break;
			}
		}

	}

}


void Ball::resetcenter()
{
	this->uprLft.x = config.Ballx0;
	this->uprLft.y = config.Bally0;
	/*this->draw();*/
	Xinc = 0;
	Yinc = config.BallRad;
}
