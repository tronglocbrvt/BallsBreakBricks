#include "SpecBricks.hpp"


SpecBricks::SpecBricks(){
    this->score = 9;
	veloc = 0.5;
    if (!this->imgTex.loadFromFile("res/img/specBrick.png")) {
        std::cout << "Load file failed" << std::endl;
        return;
    }
    this->imgTex.setSmooth(true);
    
    this->imgSpr.setTexture(this->imgTex);

	srand(time(NULL));
	typeGift = rand() % 5 + 1;
	if (typeGift == 1)
	{
		if (!this->textSpecial.loadFromFile("res/img/x2score.png")) {
			std::cout << "Load file failed" << std::endl;
			return;
		}
	}
	else if (typeGift == 2)
	{
		if (!this->textSpecial.loadFromFile("res/img/divide.png")) {
			std::cout << "Load file failed" << std::endl;
			return;
		}
	}
	else if (typeGift == 3)
	{
		if (!this->textSpecial.loadFromFile("res/img/fireball.jpg")) {
			std::cout << "Load file failed" << std::endl;
			return;
		}
	}
	else if (typeGift == 4)
	{
		if (!this->textSpecial.loadFromFile("res/img/zoomBall.jpg")) {
			std::cout << "Load file failed" << std::endl;
			return;
		}
	}
	else if (typeGift == 5)
	{
		if (!this->textSpecial.loadFromFile("res/img/widen.png")) {
			std::cout << "Load file failed" << std::endl;
			return;
		}
	}
	this->textSpecial.setSmooth(true);
	this->imgSpecial.setTexture(this->textSpecial);
	this->imgSpecial.setScale(imgTex.getSize().x * 1.0 / this->textSpecial.getSize().x, imgTex.getSize().y * 1.0 / this->textSpecial.getSize().y);
	this->imgSpecial.setPosition(imgSpr.getPosition().x, imgSpr.getPosition().y);
}
SpecBricks::~SpecBricks(){
    
}

short SpecBricks::getScore(){
    return 0;
}

void SpecBricks::destroy()
{
}

void SpecBricks::dropGift(ThePong& ball, TheBar& bar, Pos positionBar)
{
	this->imgSpecial.setPosition(imgSpr.getPosition().x + veloc, imgSpr.getPosition().y + veloc); // cập nhật vị trí rơi
	if (checkClashBar(positionBar))
	{
		switch (typeGift)
		{
		case 1:
		{
			Gift.doubleScore();
			break;
		}
		case 2:
		{
			Gift.separateScore();
			break;
		}
		case 3:
		{
			Gift.fireBall();
			break;

		}
		case 4:
		{
			Gift.zoomBall(ball);
			break;

		}
		case 5:
		{
			Gift.widenBar(bar);
			break;

		}
		default:
			break;
		}
	}
}

bool SpecBricks::checkClashBar(Pos position)
{
	float posY = imgSpecial.getPosition().y;
	float posYend = textSpecial.getSize().y;
	float posX = imgSpecial.getPosition().x;
	float posXend = textSpecial.getSize().x;
	if (posY + posYend > position.y) {
		// phần dưới trái của bóng chạm thanh
		if ((position.x <= posX) && (posX <= position.x + position.endX))
		{
			return true;
		}

		else if ((position.x <= posX + posXend) && (posX + posXend <= position.x + position.endX))
		{
			return true;
		}
		// phần dưới phải của bóng chạm thanh
	}

	return false;
}

void SpecBricks::drawGift(sf::RenderWindow& window)
{
	window.draw(imgSpecial);
}