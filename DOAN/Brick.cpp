#include "Brick.hpp"

void Brick::set(float posX, float posY, float width, float height, int type){
    
    this->score = type;
    this->imgSpr.setScale(width * 1.0 / this->imgTex.getSize().x, height * 1.0 / this->imgTex.getSize().y);
    this->imgSpr.setPosition(posX, posY);

}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(this->imgSpr);
//    window.draw(this->rectangle);
}

short Brick::collision(sf::FloatRect ballRect)
{
//	sf::FloatRect bounds = this->imgSpr.getGlobalBounds();
//	sf::Vector2f center(ballRect.left + ballRect.width / 2, ballRect.top + ballRect.height / 2);

//	float radius = ballRect.width / 2;
    
	// xét tương quan giữa boundingBox (bóng) và bounds (gạch)
	if (this->imgSpr.getGlobalBounds().intersects(ballRect)) {
    
//    if (bounds.contains(ballRect.left, ballRect.top) || bounds.contains(ballRect.left + ballRect.width, ballRect.top) || bounds.contains(ballRect.left, ballRect.top + ballRect.height) || bounds.contains(ballRect.left + ballRect.width, ballRect.top + ballRect.height)){
        
        return 1;
        /*
		// va chạm vào các cạnh
		if (bounds.contains(center.x, ballRect.top) || bounds.contains(center.x, ballRect.top + ballRect.height)) {

			return 1;     // va chạm vào chiều dài của gạch (top và bottom)
		}

		else if (bounds.contains(ballRect.left, center.y) || bounds.contains(ballRect.left + ballRect.width, center.y)) {

			return 1;     // va chạm vào chiều rộng của gạch (left và right)
		}
//
//		// va chạm góc trên trái
//		// bounding.left: lưu vị trí x của góc tác động
//		// bounding.top: lưu vị trí y của góc tác động
		else if (pow(pow(center.x - bounds.left, 2) + pow(center.y - bounds.top, 2), 0.5) < radius) {

			// lưu vị trí bóng
			ballRect.left = bounds.left;
			ballRect.top = bounds.top;
			return 2;
		}
//
//		// va chạm góc trên phải
		else if (pow(pow(center.x - (bounds.left + bounds.width), 2) + pow(center.y - bounds.top, 2), 0.5) < radius) {

			// lưu vị trí bóng
			ballRect.left = bounds.left + bounds.width;
			ballRect.top = bounds.top;
			return 2;
		}
//
//		// va chạm góc dưới phải
		else if (pow(pow(center.x - (bounds.left + bounds.width), 2)
			+ pow(center.y - (bounds.top + bounds.height), 2), 0.5) < radius) {

			// lưu vị trí bóng
			ballRect.left = bounds.left + bounds.width;
			ballRect.top = bounds.top + bounds.height;
			return 2;
		}

//		// va chạm góc dưới trái
		else if (pow(pow(center.x - bounds.left, 2) + pow(center.y - (bounds.top + bounds.height), 2), 0.5) < radius) {

			// lưu vị trí bóng
			ballRect.left = bounds.left;
			ballRect.top = bounds.top + bounds.height;
			return 2;
		}*/
	}


	return 0; // không va chạm
}


short Brick::getScore(){
    return this->score;
}

sf::FloatRect Brick::getBound(){
    return this->imgSpr.getGlobalBounds();
}
