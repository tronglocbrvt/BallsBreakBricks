#include "Brick.hpp"

void Brick::set(float posX, float posY, float width, float height, int type){
    
    this->score = type;
    this->imgSpr.setScale(width * 1.0 / this->imgTex.getSize().x, height * 1.0 / this->imgTex.getSize().y);
    this->imgSpr.setPosition(posX, posY);

}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(this->imgSpr);
}

short Brick::collision(sf::FloatRect ballRect)
{
	if (this->imgSpr.getGlobalBounds().intersects(ballRect)) {
        return 1;
	}
	return 0; // không va chạm
}

sf::FloatRect Brick::getBound(){
    return this->imgSpr.getGlobalBounds();
}
