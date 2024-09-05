#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "grid.h"
#include"paddle.h"
#include"CMUgraphicsLib/auxil.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Ball.h"
#include"Lives.h"





//Main class that coordinates the game operation
class game
{
	enum MODE	//Game mode
	{
		MODE_DSIGN,	//Desing mode (startup mode)
		MODE_PLAY,	//Playing mode
		MODE_STOP,
		MODE_FINISH
		
	};

	MODE gameMode;

	/// Add more members if needed


	
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid;
	paddle* pad;
	Ball* GameBall;

	

public:
	game();
	~game();
	Lives* live;
	int score;
	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window


	void clearStatusBar() const;	//Clears the status bar


	void printMessage(string msg) const;	//Print a message on Status bar

	void go() ;

	window* getWind() const;		//returns a pointer to the graphics window

	paddle* getPaddle() const;		//returns a pointer to the paddle

	grid* getGrid() const;			//returns a pointer to the grid

	Ball* getBall() const;			//returns a pointer to the Ball

	brick*** getBrickMatrix() const;		//returns a pointer to the BrickMatrix

	void MovePaddle() const;

	string formatTime(int seconds) const;

	void switchGamemode(int GameModeChoice);

	void ResetGame();

	paddle* getpaddle() const;

	MODE getgameMode() { return gameMode; }
};

