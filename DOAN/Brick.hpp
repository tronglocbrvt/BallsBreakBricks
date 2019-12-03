#ifndef Brick_hpp
#define Brick_hpp
#include "Object.hpp"

class Brick:public Object
{
private: 
	sf::RectangleShape rectangle;

public:
	Brick(float posX, float posY, float width, float height, char check, sf::Color color);

	char special; // nhận biết gạch loại nào
};

#endif

