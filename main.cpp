#include "game.h"
//#include"CMUgraphicsLib/CMUgraphics.h"
//#include"CMUgraphicsLib/auxil.h"
#include <iostream>
//#include <iomanip>
//#include <ctime>
//#include <iomanip>
//#include <sstream>
//#include <cstdlib>
#include"Collectables.h"
#include"FireBall.h"
#include "ReverseDirection.h"
#include<cmath>
using namespace std;


Collectables* test1(game* G, paddle* P) {
	point p;
	p.x = 100;
	p.y = 100;
	Collectables* c = new ReverseDirection(p, 20, 20, G, P);
	return c;

}


int main()
{
	game Game;
	// test function for collectables 
	/*paddle* p = Game.getpaddle();
	Collectables* fb = test1(&Game, p);

	while (true) {
		fb->moveCollectable();
		Pause(100);
	}*/
	Game.go();
	
	return 0;
}

