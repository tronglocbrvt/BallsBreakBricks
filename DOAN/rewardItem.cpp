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

doubleScore::doubleScore()
{
}

doubleScore::~doubleScore()
{
}

void doubleScore::runItem(float& score, int i, int j, buildStage& stage)
{
	score += stage.getmStage(i, j)->getScore();
}

void doubleScore::drawItem(BackGround& bg)
{
	if (!bg.Giftimage.loadFromFile("res/img/x2score.png")) {
		std::cout << "Load file failed" << std::endl;
		return;
	}

	bg.Giftimage.setSmooth(true);
	bg.Giftsprite.setTexture(bg.Giftimage);
	bg.Giftsprite.scale(1/bg.Giftsprite.getScale().x, 1 / bg.Giftsprite.getScale().y);
	float width = (float)_WIDTH_GIFT_ / (float)bg.Giftsprite.getTexture()->getSize().x;
	float height = (float)_HEIGH_GIFT_ / (float)bg.Giftsprite.getTexture()->getSize().y;
	bg.Giftsprite.scale(width, height);
	bg.Giftsprite.setPosition(800, 300);
}

divideScore::divideScore()
{
	
}

divideScore::~divideScore()
{
}

void divideScore::runItem(float& score, int i, int j, buildStage& stage)
{
	score -= (float)stage.getmStage(i, j)->getScore()/2;
}

void divideScore::drawItem(BackGround& bg)
{
	if (!bg.Giftimage.loadFromFile("res/img/divide.png")) {
		std::cout << "Load file failed" << std::endl;
		return;
	}

	bg.Giftimage.setSmooth(true);
	bg.Giftsprite.setTexture(bg.Giftimage); 
	bg.Giftsprite.scale(1 / bg.Giftsprite.getScale().x, 1 / bg.Giftsprite.getScale().y);
	float width = (float)_WIDTH_GIFT_ / (float)bg.Giftsprite.getTexture()->getSize().x;
	float height = (float)_HEIGH_GIFT_ / (float)bg.Giftsprite.getTexture()->getSize().y;
	bg.Giftsprite.scale(width, height);
	bg.Giftsprite.setPosition(800, 300);
}

widenBar::widenBar()
{

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

void widenBar::drawItem(BackGround& bg)
{
	if (!bg.Giftimage.loadFromFile("res/img/widen.png")) {
		std::cout << "Load file failed" << std::endl;
		return;
	}

	bg.Giftimage.setSmooth(true);
	bg.Giftsprite.setTexture(bg.Giftimage);
	bg.Giftsprite.scale(1 / bg.Giftsprite.getScale().x, 1 / bg.Giftsprite.getScale().y);
	float width = (float)_WIDTH_GIFT_ / (float)bg.Giftsprite.getTexture()->getSize().x;
	float height = (float)_HEIGH_GIFT_ / (float)bg.Giftsprite.getTexture()->getSize().y;
	bg.Giftsprite.scale(width, height);
	bg.Giftsprite.setPosition(800, 300);
}

zoomBall::zoomBall()
{
	
}

zoomBall::~zoomBall()
{
}

void zoomBall::runItem(ThePong& ball)
{
	ball.scale(1.5, 1.5);

	// getter vị trí cuối cùng quả bóng
	ball.posXend = ball.imgSpr.getTexture()->getSize().x * ball.imgSpr.getScale().x;
	ball.posYend = ball.imgSpr.getTexture()->getSize().y * ball.imgSpr.getScale().y;
    
	// điều chỉnh vị trí
	ball.imgSpr.setPosition(ball.posX - ball.posXend * 1.0 / 2, ball.posY);
}

void zoomBall::drawItem(BackGround& bg)
{
	if (!bg.Giftimage.loadFromFile("res/img/zoomBall.jpg")) {
		std::cout << "Load file failed" << std::endl;
		return;
	}

	bg.Giftimage.setSmooth(true);
	bg.Giftsprite.setTexture(bg.Giftimage);
	bg.Giftsprite.scale(1 / bg.Giftsprite.getScale().x, 1 / bg.Giftsprite.getScale().y);
	float width = (float)_WIDTH_GIFT_ / (float)bg.Giftsprite.getTexture()->getSize().x;
	float height = (float)_HEIGH_GIFT_ / (float)bg.Giftsprite.getTexture()->getSize().y;
	bg.Giftsprite.scale(width, height);
	bg.Giftsprite.setPosition(800, 300);
}
