#include "Brick.hpp"

Brick::Brick(float posX, float posY, float width, float height, int type, sf::Color color):rectangle(sf::Vector2f(width, height)), typeBrick(type)
{
	rectangle.setPosition(posX, posY);

	if (typeBrick == -1) // chướng ngại vật
		rectangle.setFillColor(PREVENT_BRICK);
	else if (typeBrick == 1) //  chức năng
		rectangle.setFillColor(SPECIAL_BRICK);
	else
		rectangle.setFillColor(color);
}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
}

int Brick::collision(sf::FloatRect& boundingBox)
{

	return 0;
}

