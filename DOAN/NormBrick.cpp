#include "NormBrick.hpp"

NormBrick::NormBrick(float posX, float posY, float width, float height, int type):rectangle(sf::Vector2f(width, height)), typeBrick(type)
{
	rectangle.setPosition(posX, posY);

	rectangle.setFillColor(sf::Color(203, 15, 245));
}

void NormBrick::set(float posX, float posY, float width, float height, int type){
    
    this->rectangle.setSize(sf::Vector2f(width, height));

    this->rectangle.setPosition(posX, posY);

    rectangle.setFillColor(sf::Color(203, 15, 245));
        
}

void NormBrick::draw(sf::RenderWindow& window)
{
//	window.draw(rectangle);
}

int NormBrick::collision(const sf::FloatRect& boundingBox)
{
	sf::FloatRect bounds = rectangle.getGlobalBounds();
	sf::Vector2f center(boundingBox.left + boundingBox.width / 2, boundingBox.top + boundingBox.height / 2);

	float radius = boundingBox.width / 2;

	// xét tương quan giữa boundingBox (bóng) và bounds (gạch)
	if (bounds.intersects(boundingBox)) {

		// va chạm vào các cạnh
		if (bounds.contains(center.x, boundingBox.top) || bounds.contains(center.x, boundingBox.top + boundingBox.height)) {

			return 0;     // va chạm vào chiều dài của gạch (top và bottom)
		}

		else if (bounds.contains(boundingBox.left, center.y) || bounds.contains(boundingBox.left + boundingBox.width, center.y)) {

			return 1;     // va chạm vào chiều rộng của gạch (left và right)
		}

		// va chạm góc trên trái
		// bounding.left: lưu vị trí x của góc tác động
		// bounding.top: lưu vị trí y của góc tác động
		else if (pow(pow(center.x - bounds.left, 2) + pow(center.y - bounds.top, 2), 0.5) < radius) {

			// lưu vị trí bóng
//			boundingBox.left = bounds.left;
//			boundingBox.top = bounds.top;
			return 2;
		}

		// va chạm góc trên phải
		else if (pow(pow(center.x - (bounds.left + bounds.width), 2) + pow(center.y - bounds.top, 2), 0.5) < radius) {

			// lưu vị trí bóng
//			boundingBox.left = bounds.left + bounds.width;
//			boundingBox.top = bounds.top;
			return 2;
		}

		// va chạm góc dưới phải
		else if (pow(pow(center.x - (bounds.left + bounds.width), 2)
			+ pow(center.y - (bounds.top + bounds.height), 2), 0.5) < radius) {

			// lưu vị trí bóng
//			boundingBox.left = bounds.left + bounds.width;
//			boundingBox.top = bounds.top + bounds.height;
			return 2;
		}

		// va chạm góc dưới trái
		else if (pow(pow(center.x - bounds.left, 2) + pow(center.y - (bounds.top + bounds.height), 2), 0.5) < radius) {

			// lưu vị trí bóng
//			boundingBox.left = bounds.left;
//			boundingBox.top = bounds.top + bounds.height;
			return 2;
		}
	}


	return -1; // không va chạm
}

