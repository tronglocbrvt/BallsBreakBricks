#ifndef Object_hpp
#define Object_hpp
#include <SFML/Graphics.hpp>
#include "Define_Header.h"
#include <math.h>

class Object
{
protected:
    sf::Texture imgTex;
    sf::Sprite imgSpr;
public:
	virtual ~Object() {};
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void move() = 0;
	virtual short collision(sf::FloatRect) = 0;
    virtual void destroy() = 0;
    
    static float DisBet2Point(sf::Vector2f point1, sf::Vector2f point2);
    
};
#endif
