#ifndef Brick_hpp
#define Brick_hpp
#include "Object.hpp"
#include "Define_Header.h"
#include <math.h>

#include <iostream>

class Brick:public Object
{
protected:
    short score;

public:
    Brick(){}
    
    virtual void set(float posX, float posY, float width, float height, int type);
	virtual void draw(sf::RenderWindow& window);
    virtual void move() {}
	virtual int collision(sf::FloatRect& boundingBox);
    
    virtual short getScore();
};

#endif

