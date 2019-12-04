#ifndef Brick_hpp
#define Brick_hpp
#include "Object.hpp"
#include "Define_Header.h"
#include <math.h>

class Brick:public Object
{
private: 
	sf::RectangleShape rectangle;

public:
    Brick(){}
	Brick(float posX, float posY, float width, float height, int type, sf::Color color);
    
    void set(float posX, float posY, float width, float height, int type);
	void draw(sf::RenderWindow& window);
	int collision(sf::FloatRect& boundingBox);

	int typeBrick; // nhận biết gạch loại nào: -1 là chướng ngại vật, 0 là bình thường, 1 là chức năng
};

#endif

