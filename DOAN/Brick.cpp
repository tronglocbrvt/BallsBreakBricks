#include "Brick.hpp"

Brick::Brick(float posX, float posY, float width, float height, char check, sf::Color color):rectangle(sf::Vector2f(width, height)), special(check)
{
	rectangle.setPosition(posX, posY);
}
