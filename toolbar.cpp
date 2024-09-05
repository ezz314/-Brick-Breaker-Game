#include "toolbar.h"
#include "game.h"
#include "grid.h"
#include "gameConfig.h"
#include <fstream>


////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
toolbarIcon::toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_uprleft, r_width, r_height, r_pGame)
{}




////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
iconAddNormalBrick::iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddNormalBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Normal Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_NRM, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}
//_______________My Work______________//
////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////

iconAddHardBrick::iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddHardBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Hard Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_HRD, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////

iconAddRockBrick::iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddRockBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Rock Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_ROCK, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

////////////////////////////////////////////////////  class iconAddBombBrick   //////////////////////////////////////////////

iconAddBombBrick::iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddBombBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Bomb Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_BOMB, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}


iconAddPowerup::iconAddPowerup(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddPowerup::onClick()
{
	pGame->printMessage("Click on empty cells to add Power Up Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_PUP, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}
iconAddPowerdown::iconAddPowerdown(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddPowerdown::onClick()
{
	pGame->printMessage("Click on empty cells to add Power Down Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_PDOWN, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}




iconStart_Pause::iconStart_Pause(point r_uprleft, int r_width, int r_height, game* r_pGame) : //playfunc
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame) {}

void iconStart_Pause::onClick()
{
	int CurrentMode = pGame->getgameMode();
	if (CurrentMode == 0) { pGame->switchGamemode(1); }
	else if (CurrentMode == 1)pGame->switchGamemode(2);
	else if (CurrentMode == 2)pGame->switchGamemode(1);
}


iconSave::iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame) {}

void iconSave::onClick()
{
	ofstream save_file;
	save_file.open("save_load\\saveGame.txt");

	grid* gameGrid = pGame->getGrid();
	brick*** brickMatrix = gameGrid->getbrickMatrix();
	for (int i = 0; i < gameGrid->getrows(); i++)
		for (int j = 0; j < gameGrid->getcols(); j++)
			if (brickMatrix[i][j]) {
				save_file << i << "\t" << j << "\t" << brickMatrix[i][j]->getBrickType() << "\t" << brickMatrix[i][j]->getstrength() << endl;
			}


	save_file.close();
	pGame->printMessage("SAVED!!!");
	Pause(1000);

}

iconLoad::iconLoad(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame) {}

void iconLoad::onClick()
{

	ifstream load_file;
	load_file.open("save_load\\saveGame.txt");
	grid* gameGrid = pGame->getGrid();

	//we have only one file if we have multiple it will be useful 
	if (!load_file)
	{
		pGame->printMessage("NO FILES ARE THERE!!  ==> Right-Click to Continue <==");
		int x, y;
		clicktype t = pGame->getMouseClick(x, y);
		while (t == LEFT_CLICK)
		{
			point clicked;
			clicked.x = x;
			clicked.y = y;
			gameGrid->draw();
			t = pGame->getMouseClick(x, y);
		}
	}
	else {
		int colindex, rowindex, type, strength;
		while (load_file >> rowindex >> colindex >> type >> strength) {
			BrickType Modifiedtype = (BrickType)type;
			// cout << rowindex << "\t" << colindex << "\t" << type << endl; / //check
			gameGrid->addBrick(Modifiedtype, rowindex, colindex, strength);
		}
	}
	gameGrid->draw();
	load_file.close();
	pGame->printMessage("LOADED!!!");
	Pause(1000);
}


//_____________________________//
////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
iconExit::iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconExit::onClick()
{
	//TO DO: add code for cleanup and game exit here
}


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(point r_uprleft, int wdth, int hght, game* pG) :
	drawable(r_uprleft, wdth, hght, pG)
{

	height = hght;
	pGame = pG;

	//First prepare List of images for each icon
	//To control the order of these images in the menu, reoder them in enum ICONS above	
	iconsImages[ICON_ADD_NORM] = "images\\ToolbarIcons\\NormalBrickIcon.jpg";
	iconsImages[ICON_EXIT] = "images\\ToolbarIcons\\ExitIcon.jpg";
	iconsImages[ICON_ADD_HARD] = "images\\ToolbarIcons\\HardBrickIcon.jpg";
	iconsImages[ICON_ADD_ROCK] = "images\\ToolbarIcons\\RockBrickIcon.jpg";
	iconsImages[ICON_ADD_BOMB] = "images\\ToolbarIcons\\BombBrickIcon.jpg";
	iconsImages[ICON_ADD_CROSSBOMB] = "images\\ToolbarIcons\\CrossBombBrickIcon.jpg";
	iconsImages[ICON_DELETEBRICK] = "images\\ToolbarIcons\\DeleteBrickIcon.jpg";
	iconsImages[ICON_SAVE] = "images\\ToolbarIcons\\SaveIcon.jpg";
	iconsImages[ICON_START_PAUSE] = "images\\ToolbarIcons\\Start_Pause.jpg";
	iconsImages[ICON_LOAD] = "images\\ToolbarIcons\\LoadIcon.jpg";
	iconsImages[ICON_ADD_POWERUP] = "images\\ToolbarIcons\\PowerUpIcon.jpg";
	iconsImages[ICON_ADD_POWERDOWN] = "images\\ToolbarIcons\\PowerDownIcon.jpg";
	iconsImages[ICON_STOP] = "images\\ToolbarIcons\\StopIcon.jpg";


	point p;
	p.x = 0;
	p.y = 0;

	iconsList = new toolbarIcon * [ICON_COUNT];

	//For each icon in the tool bar
	//	1- Create an object setting its upper left corner, width and height
	iconsList[ICON_ADD_NORM] = new iconAddNormalBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_HARD] = new iconAddHardBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_ROCK] = new iconAddRockBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_BOMB] = new iconAddBombBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_CROSSBOMB] = new iconAddCrossBombBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_POWERUP] = new iconAddPowerup(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_POWERDOWN] = new iconAddPowerdown(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_DELETEBRICK] = new iconDeleteBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_START_PAUSE] = new iconStart_Pause(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_SAVE] = new iconSave(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_LOAD] = new iconLoad(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_STOP] = new iconStop(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;

	iconsList[ICON_EXIT] = new iconExit(p, config.iconWidth, height, pGame);


	//	2-Set its image (from the above images list)
	for (int i = 0; i < ICON_COUNT; i++)
	{
		iconsList[i]->setImageName(iconsImages[i]);

	}
}

toolbar::~toolbar()
{
	for (int i = 0; i < ICON_COUNT; i++)
		delete iconsList[i];
	delete iconsList;
}

void toolbar::draw() const
{
	for (int i = 0; i < ICON_COUNT; i++)
		iconsList[i]->draw();
	window* pWind = pGame->getWind();
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, height, pWind->GetWidth(), height);

}

//handles clicks on toolbar icons, returns true if exit is clicked
bool toolbar::handleClick(int x, int y)
{
	if (x > ICON_COUNT * config.iconWidth)	//click outside toolbar boundaries
		return false;


	//Check whick icon was clicked
	//==> This assumes that menu icons are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

	int clickedIconIndex = (x / config.iconWidth);
	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon

	if (clickedIconIndex == ICON_EXIT) return true;

	return false;


}

toolbarIcon** toolbar::geticonlst() const
{
	return iconsList;
}


iconStop::iconStop(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}

void iconStop::onClick()
{
	pGame->switchGamemode(3);
}


iconDeleteBrick::iconDeleteBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconDeleteBrick::onClick()
{
	pGame->printMessage("Click on a Brick to Delete ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->RemoveBrick(clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

iconAddCrossBombBrick::iconAddCrossBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddCrossBombBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Cross Bomb Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_CROSSBOMB, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}