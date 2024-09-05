#include "Bricks.h"
#include "game.h"
#include "Collectables.h"
#include "FireBall.h"
#include "gameConfig.h"
#include "WindGlide.h"
#include "ReverseDirection.h"
#include <iostream>
////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame, BrickType t, int s) :
	collidable(r_uprleft, r_width, r_height, r_pGame), type(t), strength(s)
{
}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame, BRK_NRM, 1)
{
	imageName = "images\\bricks\\NormalBrick.jpg";
}


void normalBrick::collisionAction()
{

	pGame->score += 1;
	grid* pGrid = pGame->getGrid(); pGrid->RemoveBrick(this->uprLft);

}

hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame, BRK_HRD, 3)
{
	imageName = "images\\bricks\\HardBrick.jpg";
}

void hardBrick::collisionAction()
{
	strength -= 1;
	pGame->score += 1;
	if (strength == 0) { grid* pGrid = pGame->getGrid(); pGrid->RemoveBrick(this->uprLft); }
}

RockBrick::RockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame, BRK_ROCK, 0)
{
	imageName = "images\\bricks\\RockBrick.jpg";
}

void RockBrick::collisionAction()
{
	strength += 1;
}

BombBrick::BombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame, BRK_BOMB, 1)
{
	imageName = "images\\bricks\\BombBrick.jpg";
}

void BombBrick::collisionAction()
{
	pGame->score += 4;
	grid* pGrid = pGame->getGrid();
	int rowIndex = (this->uprLft.y - pGrid->getuprleft().y) / config.brickHeight;
	int colIndex = this->uprLft.x / config.brickWidth;
	brick*** Bmatrix = pGrid->getbrickMatrix();
	pGrid->RemoveBrick(this->uprLft);
	pGrid->RemoveBrick(Bmatrix[rowIndex - 1][colIndex]->getuprleft());
	pGrid->RemoveBrick(Bmatrix[rowIndex + 1][colIndex]->getuprleft());
	pGrid->RemoveBrick(Bmatrix[rowIndex][colIndex - 1]->getuprleft());
	pGrid->RemoveBrick(Bmatrix[rowIndex][colIndex + 1]->getuprleft());

}

CrossBombBrick::CrossBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame, BRK_CROSSBOMB, 1)
{
	imageName = "images\\bricks\\CrossBombBrick.jpg";
}

void CrossBombBrick::collisionAction()
{
	pGame->score += 10;
	grid* pGrid = pGame->getGrid();
	int rowIndex = (this->uprLft.y - pGrid->getuprleft().y) / config.brickHeight;
	int colIndex = this->uprLft.x / config.brickWidth;
	brick*** Bmatrix = pGrid->getbrickMatrix();

	for (int i = 0; i < pGrid->getcols(); i++) {
		if (Bmatrix[rowIndex][i] != nullptr) {
			pGrid->RemoveBrick(Bmatrix[rowIndex][i]->getuprleft());
			Bmatrix[rowIndex][i] = nullptr;
		}
	}
	for (int i = 0; i < pGrid->getrows(); i++) {
		if (Bmatrix[i][colIndex] != nullptr) {
			pGrid->RemoveBrick(Bmatrix[i][colIndex]->getuprleft());
			Bmatrix[i][colIndex] = nullptr;
		}
	}

	Collectables* RandomCollectable = nullptr;
	int RandomColNum = Collectables::PickRandomCollectable(UP);
	if (RandomColNum == 1) { RandomCollectable = new FireBall(this->uprLft, config.collecSide, config.collecSide, pGame, pGame->getpaddle()); }
	else if (RandomColNum == 2) { RandomCollectable = new WindGlide(this->uprLft, config.collecSide, config.collecSide, pGame, pGame->getpaddle()); }

}


PowerUpBrick::PowerUpBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame, BRK_PUP, 1)
{
	imageName = "images\\bricks\\PowerUp.jpg";
}

void PowerUpBrick::collisionAction()
{
	pGame->score += 1;
	Collectables* RandomCollectable = nullptr;
	int RandomColNum = RandomCollectable->PickRandomCollectable(UP);
	if (RandomColNum == 1) { RandomCollectable = new FireBall(this->uprLft, config.collecSide, config.collecSide, pGame, pGame->getpaddle()); }
	else if (RandomColNum == 2) { RandomCollectable = new WindGlide(this->uprLft, config.collecSide, config.collecSide, pGame, pGame->getpaddle()); }
	// should be deleted in paddle collision 


	grid* pGrid = pGame->getGrid(); pGrid->RemoveBrick(this->uprLft);
}


PowerDownBrick::PowerDownBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame, BRK_PDOWN, 1)
{
	imageName = "images\\bricks\\PowerDown.jpg";
}

void PowerDownBrick::collisionAction()
{
	pGame->score += 1;
	Collectables* RandomCollectable = nullptr;
	int RandomColNum = RandomCollectable->PickRandomCollectable(DOWN);
	if (RandomColNum == 1) { RandomCollectable = new ReverseDirection(this->uprLft, config.collecSide, config.collecSide, pGame, pGame->getpaddle()); }
	// should be deleted in paddle collision 


	grid* pGrid = pGame->getGrid(); pGrid->RemoveBrick(this->uprLft);

}