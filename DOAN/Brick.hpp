#ifndef Brick_hpp
#define Brick_hpp
#include "Object.hpp"
#include "Define_Header.h"
#include <math.h>

class Brick:public Object
{
protected: 
	int typeBrick; // nhận biết gạch loại nào: -1 là chướng ngại vật, 0 là bình thường, 1 là chức năng
	sf::RectangleShape rectangle;
public:
    Brick(){}
	Brick(float posX, float posY, float width, float height, int type, sf::Color color);
    
    void set(float posX, float posY, float width, float height, int type);
	virtual void draw(sf::RenderWindow& window);
	int collision(sf::FloatRect& boundingBox);
	virtual void destroy() = 0;
};

#endif

