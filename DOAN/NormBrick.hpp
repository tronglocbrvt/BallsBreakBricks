#ifndef NormBrick_hpp
#define NormBrick_hpp

#include "Brick.hpp"
#include "Define_Header.h"
#include <math.h>

class NormBrick : public Brick
{
private: 
	sf::RectangleShape rectangle;

public:
    NormBrick(){}
	NormBrick(float posX, float posY, float width, float height, int type);
    
    void set(float posX, float posY, float width, float height, int type);
	void draw(sf::RenderWindow& window);
	int collision(sf::FloatRect& boundingBox);

	int typeBrick; // nhận biết gạch loại nào: -1 là chướng ngại vật, 0 là bình thường, 1 là chức năng
};

#endif

