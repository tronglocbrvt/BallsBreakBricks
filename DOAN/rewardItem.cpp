#include "rewardItem.h"

rewardItem::rewardItem()
{

}

rewardItem::~rewardItem()
{
}

void rewardItem::runItem(float& score, int i, int j, buildStage& stage)
{
}

void rewardItem::runItem(TheBar& bar)
{
}

void rewardItem::runItem(ThePong& ball)
{
}

void rewardItem::drawItem(sf::RenderWindow& window)
{
	window.draw(imgSpecial);
}


doubleScore::doubleScore()
{
	if (!this->textSpecial.loadFromFile("res/img/x2score.png")) {
		std::cout << "Load file failed" << std::endl;
		return;
	}

	this->textSpecial.setSmooth(true);
	this->imgSpecial.setTexture(this->textSpecial);
	imgSpecial.setPosition(600, 300);
}

doubleScore::~doubleScore()
{
}

void doubleScore::runItem(float& score, int i, int j, buildStage& stage)
{
	std::cout << "haha";
	score += stage.getmStage(i, j)->getScore();
}

divideScore::divideScore()
{
	if (!this->textSpecial.loadFromFile("res/img/divide.png")) {
		std::cout << "Load file failed" << std::endl;
		return;
	}

	this->textSpecial.setSmooth(true);
	this->imgSpecial.setTexture(this->textSpecial);
	imgSpecial.setPosition(600, 300);
}

divideScore::~divideScore()
{
}

void divideScore::runItem(float& score, int i, int j, buildStage& stage)
{
	score -= stage.getmStage(i, j)->getScore()/2;
}

widenBar::widenBar()
{
	if (!this->textSpecial.loadFromFile("res/img/widen.png")) {
		std::cout << "Load file failed" << std::endl;
		return;
	}

	this->textSpecial.setSmooth(true);
	this->imgSpecial.setTexture(this->textSpecial);
	imgSpecial.setPosition(400, 300);
}

widenBar::~widenBar()
{
}

void widenBar::runItem(TheBar& bar)
{
	bar.setHeightBar(bar.getImgSpr().getTexture()->getSize().y);     // lấy kích thước theo chiều dài Oy
	bar.setLongBar(bar.getImgSpr().getTexture()->getSize().x);     // lấy kích thước theo chiều rộng Ox

	bar.scale(1.5, 1);      // scale để có kích thước chính xác là (_WIDTH_BAR_, _HEIGH_BAR_)

	bar.setHeightBar(bar.getHeigh() * bar.getImgSpr().getScale().y);
	bar.setLongBar(bar.getLongBar() * bar.getImgSpr().getScale().x);
}

zoomBall::zoomBall()
{
	if (!this->textSpecial.loadFromFile("res/img/zoomBall.jpg")) {
		std::cout << "Load file failed" << std::endl;
		return;
	}

	this->textSpecial.setSmooth(true);
	this->imgSpecial.setTexture(this->textSpecial);
	imgSpecial.setPosition(400, 300);
}

zoomBall::~zoomBall()
{
}

void zoomBall::runItem(ThePong& ball)
{
	ball.scale(2.0, 2.0);

	// getter vị trí cuối cùng quả bóng
	ball.posXend = ball.imgSpr.getTexture()->getSize().x * ball.imgSpr.getScale().x;
	ball.posYend = ball.imgSpr.getTexture()->getSize().y * ball.imgSpr.getScale().y;

	// điều chỉnh vị trí
	ball.imgSpr.setPosition(ball.posX - ball.posXend * 1.0 / 2, ball.posY);
}
