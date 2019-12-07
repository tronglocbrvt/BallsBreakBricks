#include "rewardItem.h"

rewardItem::rewardItem()
{

}

rewardItem::~rewardItem()
{
}

void rewardItem::fireBall()
{
}

void rewardItem::widenBar(TheBar& bar)
{
	bar.setHeightBar(bar.getImgSpr().getTexture()->getSize().y);     // lấy kích thước theo chiều dài Oy
	bar.setLongBar(bar.getImgSpr().getTexture()->getSize().x);     // lấy kích thước theo chiều rộng Ox

	bar.scale(1.5, 1);      // scale để có kích thước chính xác là (_WIDTH_BAR_, _HEIGH_BAR_)

	bar.setHeightBar(bar.getHeigh() * bar.getImgSpr().getScale().y);
	bar.setLongBar(bar.getLongBar() * bar.getImgSpr().getScale().x);
}

void rewardItem::zoomBall(ThePong& ball)
{
	ball.scale(2.0, 2.0);

	// getter vị trí cuối cùng quả bóng
	ball.posXend = ball.imgSpr.getTexture()->getSize().x * ball.imgSpr.getScale().x;
	ball.posYend = ball.imgSpr.getTexture()->getSize().y * ball.imgSpr.getScale().y;

	// điều chỉnh vị trí
	ball.imgSpr.setPosition(ball.posX - ball.posXend * 1.0 / 2, ball.posY);
}
