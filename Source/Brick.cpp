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

sf::Vector2f Brick::getCentroid(){
    sf::FloatRect obj = this->imgSpr.getGlobalBounds();
    return sf::Vector2f(obj.left + obj.width/2, obj.top + obj.height/2);
}

sf::FloatRect Brick::getBound(){
    return this->imgSpr.getGlobalBounds();
}

bool Brick::contain(sf::Vector2f point){
    sf::FloatRect bound = this->imgSpr.getGlobalBounds();
    return ((bound.left <= point.x) && (point.x <= bound.left + bound.width) && (bound.top <= point.y) && (point.y <= bound.top + bound.height));
}
float Brick::getTop(){
    return this->imgSpr.getGlobalBounds().top;
}
float Brick::getBot(){
    return (this->imgSpr.getGlobalBounds().top + this->imgSpr.getGlobalBounds().height);
}
float Brick::getLeft(){
    return this->imgSpr.getGlobalBounds().left;
}
float Brick::getRight(){
    return (this->imgSpr.getGlobalBounds().left + this->imgSpr.getGlobalBounds().width);
}
