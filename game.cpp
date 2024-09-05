#include "game.h"
#include "gameConfig.h"
#include"CMUgraphicsLib/auxil.h"
#include <iostream>
#include<chrono>

using namespace chrono;
using namespace std;
int elapsedTime = 0;
string game::formatTime(int seconds) const {
	int hours = seconds / 3600;
	int minutes = (seconds % 3600) / 60;
	int secs = seconds % 60;

	stringstream ss;
	ss << setfill('0') << setw(2) << hours << ":"
		<< setfill('0') << setw(2) << minutes << ":"
		<< setfill('0') << setw(2) << secs;

	return ss.str();
}

void game::switchGamemode(int GameModeChoice)
{
	if (GameModeChoice == 0) { gameMode = MODE_DSIGN ; }
	else if (GameModeChoice == 1) { gameMode = MODE_PLAY; }
	else if (GameModeChoice == 2) { gameMode = MODE_STOP; }
	else if (GameModeChoice == 3) { gameMode = MODE_FINISH; }
}


game::game()
{
	//Initialize playgrond parameters
	gameMode = MODE_DSIGN;
	live = new Lives;
	score = 0;
	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new toolbar(toolbarUpperleft,0,config.toolBarHeight, this);
	gameToolbar->draw();

	//3 - create and draw the grid
	point gridUpperleft;
	gridUpperleft.x = 0;
	gridUpperleft.y = config.toolBarHeight;
	bricksGrid = new grid(gridUpperleft, config.windWidth, config.gridHeight, this);
	bricksGrid->draw();
	
	//4- Create the Paddle
	point paddleUpperleft;
	paddleUpperleft.x = (config.windWidth / 2) + config.wx - (config.paddleWidth / 2);
	paddleUpperleft.y = config.windHeight - 2 * config.paddleHeight;
	pad = new paddle(paddleUpperleft, config.paddleWidth, config.paddleHeight, this);
	pad->draw();

	//5- Create the ball
	point BallUpperleft;
	BallUpperleft.x = config.Ballx0;
	BallUpperleft.y = config.Bally0; /////modification
	GameBall = new Ball(BallUpperleft, 2 * config.BallRad, 2 * config.BallRad, this);
	
	//6- Create and clear the status bar
	clearStatusBar();
	
	
}

game::~game()
{
	delete pWind;
	delete gameToolbar;
	delete bricksGrid;
	delete pad;
}



clicktype game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
//////////////////////////////////////////////////////////////////////////////////////////
window* game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}

paddle* game::getPaddle() const
{
	return pad;
}

Ball* game::getBall() const
{
	return GameBall;
}

brick*** game::getBrickMatrix() const
{
	return bricksGrid->getbrickMatrix();
}


void game::MovePaddle() const
{
	char press;
	pWind->GetKeyPress(press);
	if (press == 6) {
		pad->movepaddleright();
	}
	else if (press == 4) {
		pad->movepaddleleft();
	}
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return bricksGrid;
}

void game::ResetGame()
{
	if ((GameBall->getuprleft().y >= pWind->GetHeight() - (2 * config.BallRad) - 45)) {
		if ((live->getnumber_lives()) != 0)
			GameBall->resetcenter();
		else gameMode=MODE_DSIGN;
		live->livelost();
	}
}

paddle* game::getpaddle() const
{
	return pad;
}



////////////////////////////////////////////////////////////////////////
void game::go() 
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	keytype ktype;
	char Key;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");

	// Draw the game content


	do
	{

		if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{
			printMessage("Ready...");
			getMouseClick(x, y);		//Get the coordinates of the user click
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick(x, y);
			}
		}


		window* pWind1 = getWind();
		clock_t start_time = clock();


		if (gameMode == MODE_PLAY) {


			bool Space_isPressed = false;
			printMessage("You can play now  ==> Press space bar to start <==");
			pWind->FlushKeyQueue();
			ktype = pWind->GetKeyPress(Key);
			if (Key == 32) {
				Space_isPressed = true;
			}

			if (Space_isPressed = true)
			{
				pWind->FlushKeyQueue();
				GameBall->draw(LAVENDER, pWind);
				getGrid();

				printMessage(" Lives : " + to_string(live->getnumber_lives()) + " | Score : " + to_string(score) + " | Timer : " + formatTime(elapsedTime));
				GameBall->ball_Movement();
				GameBall->draw(RED, pWind);

				pWind->UpdateBuffer();
				Pause(10);
				ResetGame();

				pWind->GetMouseClick(x, y);
				MovePaddle();
				if (y >= 0 && y < config.toolBarHeight)
				{
					isExit = gameToolbar->handleClick(x, y);
				}
				elapsedTime = (static_cast<int>(start_time) + 32) / CLOCKS_PER_SEC;


			}



		}


		if (gameMode == MODE_STOP)
		{
			/*getMouseClick(x, y);*/
			pWind->GetMouseClick(x, y);
			if (y >= 0 && y < config.toolBarHeight && x > config.iconWidth * 12)
			{
				isExit = gameToolbar->handleClick(x, y);
			}
		}


	} while (!isExit);
	
}