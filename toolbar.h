#pragma once

//This file contains all classes related to toolbar (toolbar icon classes & toolbar class itself)
#include "drawable.h"

////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
//Base class for all toolbar icons 
class toolbarIcon :public drawable
{
public:
	toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() = 0;   //The action that should be taken when this icon is clicked
};

////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
class iconAddNormalBrick :public toolbarIcon
{
public:
	iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};

////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////
class iconAddHardBrick :public toolbarIcon
{
public:
	iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};
//////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////
class iconAddRockBrick :public toolbarIcon
{
public:
	iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};
//////////////////////////////////////////////////////  class iconAddBombBrick   //////////////////////////////////////////////
class iconAddBombBrick :public toolbarIcon
{
public:
	iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};

class iconAddCrossBombBrick :public toolbarIcon
{
public:
	iconAddCrossBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};

class iconDeleteBrick :public toolbarIcon
{
public:
	iconDeleteBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};

class iconAddPowerup :public toolbarIcon
{
public:
	iconAddPowerup(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};

class iconAddPowerdown :public toolbarIcon
{
public:
	iconAddPowerdown(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};






//////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
class iconExit :public toolbarIcon
{
public:
	iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};

//////////////////////////////////////////////////////  class iconStart_Pause   //////////////////////////////////////////////
class iconStart_Pause :public toolbarIcon
{
public:
	iconStart_Pause(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};
////////////////////////////////////////////////////  class iconSave   //////////////////////////////////////////////
class iconSave :public toolbarIcon
{
public:
	iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;
};

class iconLoad : public toolbarIcon {
public:
	iconLoad(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() override;

};

class iconStop :public toolbarIcon
{
public:
	iconStop(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};

////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
class toolbar :public drawable
{

	enum ICONS //The icons of the toolbar (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_ADD_NORM,		//add normal brick

		//TODO: Add more icons names here
		ICON_ADD_HARD,		//add Hard brick
		ICON_ADD_ROCK,
		ICON_ADD_BOMB,
		ICON_ADD_CROSSBOMB,
		ICON_ADD_POWERUP,
		ICON_ADD_POWERDOWN,
		ICON_DELETEBRICK,
		ICON_START_PAUSE,
		ICON_SAVE,
		ICON_LOAD,
		ICON_STOP,
		ICON_EXIT,       //Exit icon
		ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

private:
	toolbarIcon** iconsList; //an array of toolbarIcon pointers
	string iconsImages[ICON_COUNT];
	game* pGame;

public:
	toolbar(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~toolbar();
	void draw() const;
	bool handleClick(int x, int y);	//handles clicks on toolbar icons, returns true if exit is 
	toolbarIcon** geticonlst() const;
};