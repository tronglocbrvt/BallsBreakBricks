#ifndef Brick_hpp
#define Brick_hpp
#include "Object.hpp"
#include "Define_Header.h"
#include <math.h>

class Brick:public Object
{
private:
    sf::RectangleShape rectangle;   
    short score;

public:
    Brick(){}
	Brick(float posX, float posY, float width, float height, int type);
    
    virtual void set(float posX, float posY, float width, float height, int type);
	virtual void draw(sf::RenderWindow& window);
    virtual void move() {}
	virtual int collision(sf::FloatRect& boundingBox);
    virtual void destroy();
};

#endif

