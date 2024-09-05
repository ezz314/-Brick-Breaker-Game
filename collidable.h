#pragma once
#include "drawable.h"

///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)


enum sideOfCollision { UPPER, LOWER, RIGHT, LEFT };
struct CollisionInfo
{
    bool isCollided = 0;
    sideOfCollision side;
};
class collidable :public drawable
{
protected:
    CollisionInfo col;
    double AngleOfCollison;

public:
    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);

    CollisionInfo Collided(const collidable* object1, const  collidable* object2);


    static point detect_collisions(collidable* c1, collidable* c2);
    virtual void collisionAction() = 0;    //action that should be performed upon collision
    double AngleCollision(collidable* object1, collidable* ball);

};



