#include "collidable.h"
#include "gameConfig.h"

collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_uprleft, r_width, r_height, r_pGame) {}


CollisionInfo collidable::Collided(const collidable* object1, const collidable* ball)
{
	col.isCollided = false;

	double xMax = object1->uprLft.x + object1->width;
	double xMin = object1->uprLft.x;
	double yMax = object1->uprLft.y + object1->height;
	double yMin = object1->uprLft.y;

	if (
		(xMax <= (ball->uprLft.x - ball->width) ||
		yMax <= (ball->uprLft.y - ball->height)) ||
		(xMin >= (ball->uprLft.x + ball->width) ||
			yMin >= (ball->uprLft.y + ball->height))
		)
	{
		//no collision is possible
		return col;
	}

	col.isCollided = true;

	// Check for specific collision sides
	if (yMin <= ball->uprLft.y &&
		ball->uprLft.x + ball->width  >= xMin &&
		ball->uprLft.x - ball->width  <= xMax)
	{
		col.side = UPPER;
	}
	else if (yMax > ball->uprLft.y &&
		ball->uprLft.x + ball->width >= xMin &&
		ball->uprLft.x + ball->width <= xMax)
	{
		col.side = LOWER;
	}
	else if (xMin > ball->uprLft.x + 2*ball->width &&
		ball->uprLft.y + ball->width >= yMin &&
		ball->uprLft.y + ball->width <= yMax)
	{
		col.side = LEFT;
	}
	else if (xMax <= ball->uprLft.x  &&
		ball->uprLft.y + ball->width >= yMin &&
		ball->uprLft.y + ball->width <= yMax)
	{
		col.side = RIGHT;
	}

	return col;
}


point collidable::detect_collisions(collidable* c1, collidable* c2)
{
	point p;
	if (c1->getuprleft().y == c2->getuprleft().y - config.brickHeight) {
		if (c1->getuprleft().x >= c2->getuprleft().x && c1->getuprleft().x < c2->getuprleft().x + config.brickWidth) {
			p.x = (c2->getuprleft().x + config.brickWidth - c1->getuprleft().x) / 2 + c1->getuprleft().x;
			p.y = c1->getuprleft().y;
			return p;
		}
		else if (c1->getuprleft().x == c2->getuprleft().x + config.brickWidth) {
			p = c1->getuprleft();
			return p;
		}
		else if (c1->getuprleft().x < c2->getuprleft().x && c1->getuprleft().x > c2->getuprleft().x - config.brickWidth) {
			p.x = (c1->getuprleft().x + config.brickWidth - c2->getuprleft().x) / 2 + c2->getuprleft().x;
			p.y = c1->getuprleft().y;
			return p;
		}
		else if (c1->getuprleft().x == c2->getuprleft().x - config.brickWidth) {
			p.x = c1->getuprleft().x + config.brickWidth;
			p.y = c1->getuprleft().y;
			return p;
		}
	}
	else if (c1->getuprleft().y == c2->getuprleft().y + config.brickHeight) {
		if (c1->getuprleft().x >= c2->getuprleft().x && c1->getuprleft().x < c2->getuprleft().x + config.brickWidth) {
			p.x = (c2->getuprleft().x + config.brickWidth - c1->getuprleft().x) / 2 + c1->getuprleft().x;
			p.y = c1->getuprleft().y - config.brickHeight;
			return p;
		}
		else if (c1->getuprleft().x == c2->getuprleft().x + config.brickWidth) {
			p.x = c1->getuprleft().x;
			p.y = c1->getuprleft().y - config.brickHeight;
			return p;
		}
		else if (c1->getuprleft().x < c2->getuprleft().x && c1->getuprleft().x > c2->getuprleft().x - config.brickWidth) {
			p.x = (c1->getuprleft().x + config.brickWidth - c2->getuprleft().x) / 2 + c2->getuprleft().x;
			p.y = c1->getuprleft().y - config.brickHeight;
			return p;
		}
		else if (c1->getuprleft().x == c2->getuprleft().x - config.brickWidth) {
			p = c2->getuprleft();
			return p;
		}
	}
	else if (c1->getuprleft().x == c2->getuprleft().x + config.brickWidth) {
		if (c1->getuprleft().y >= c2->getuprleft().y && c1->getuprleft().y < c2->getuprleft().y + config.brickHeight) {
			p.x = c1->getuprleft().x;
			p.y = (c2->getuprleft().y - (c1->getuprleft().y - config.brickHeight)) / 2 + c1->getuprleft().y - config.brickHeight;
			return p;
		}
		else if (c1->getuprleft().y == c2->getuprleft().y + config.brickHeight) {
			p.x = c1->getuprleft().x;
			p.y = c1->getuprleft().y - config.brickHeight;
			return p;
		}
		else if (c1->getuprleft().y < c2->getuprleft().y && c1->getuprleft().y > c2->getuprleft().y - config.brickHeight) {
			p.x = c1->getuprleft().x;
			p.y = (c1->getuprleft().y - (c2->getuprleft().y - config.brickHeight)) / 2 + c2->getuprleft().y - config.brickHeight;
			return p;
		}
		else if (c1->getuprleft().y == c2->getuprleft().y - config.brickHeight) {
			p = c1->getuprleft();
			return p;

		}
		else if (c1->getuprleft().x == c2->getuprleft().x - config.brickWidth) {
			if (c1->getuprleft().y >= c2->getuprleft().y && c1->getuprleft().y < c2->getuprleft().y + config.brickHeight) {
				p.x = c1->getuprleft().x + config.brickWidth;
				p.y = (c2->getuprleft().y - (c1->getuprleft().y - config.brickHeight)) / 2 + c1->getuprleft().y - config.brickHeight;
				return p;
			}
			else if (c1->getuprleft().y - config.brickHeight == c2->getuprleft().y) {
				p.x = c1->getuprleft().x + config.brickWidth;
				p.y = c1->getuprleft().y - config.brickHeight;
				return p;
			}
			else if (c1->getuprleft().y < c2->getuprleft().y && c1->getuprleft().y > c2->getuprleft().y - config.brickHeight) {
				p.x = c1->getuprleft().x + config.brickWidth;
				p.y = (c1->getuprleft().y - (c2->getuprleft().y - config.brickHeight)) / 2 + c2->getuprleft().y - config.brickHeight;
				return p;
			}
			else if (c1->getuprleft().y == c2->getuprleft().y - config.brickHeight) {
				p.x = c1->getuprleft().x + config.brickWidth;
				p.y = c1->getuprleft().y;
				return p;
			}

		}
	}
	p.x = -1;
	p.y = -1;
	return p;
}



double collidable::AngleCollision(collidable* object1, collidable* ball)
{
	double deflectedDistance = ((object1->uprLft.x) + ((object1->width) / 2.0)) - (ball->uprLft.x);

	AngleOfCollison = 90 - (45.0 * (deflectedDistance / (object1->width / 2)));

	return AngleOfCollison;
}

