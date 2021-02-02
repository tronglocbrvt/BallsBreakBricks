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
	virtual short collision(sf::FloatRect ballRect);
    
    virtual short getScore() = 0;
    virtual sf::Vector2f getCentroid();
    
    virtual sf::FloatRect getBound();
    virtual bool contain(sf::Vector2f point);
    virtual float getTop();
    virtual float getBot();
    virtual float getLeft();
    virtual float getRight();
};

class NoneBrick : public Brick {
protected:
    
public:
    NoneBrick(){}
    virtual short getScore(){return 0;}
    virtual void draw(sf::RenderWindow&){}
    virtual void move(){}
    virtual short collision(sf::FloatRect){return false;}
    virtual void destroy(){}
};

#endif

