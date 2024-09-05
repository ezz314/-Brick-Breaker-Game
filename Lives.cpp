#include "Lives.h"

int Lives::getnumber_lives()
{
    return numberLives;
}



void Lives::livelost()
{
    numberLives--;
}

void Lives::livegained()
{
    numberLives--;
}
