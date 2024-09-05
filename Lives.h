#pragma once
class Lives
{
	int numberLives;
public:
	Lives() { numberLives = 3; }
	 int getnumber_lives();
	 void livelost();
	 void livegained();
};

