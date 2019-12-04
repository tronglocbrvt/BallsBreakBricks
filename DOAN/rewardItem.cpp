#include "rewardItem.h"

rewardItem::rewardItem()
{

}

rewardItem::~rewardItem()
{
}

void rewardItem::zoomBall(ThePong& ball)
{
	ball.imgSpr.scale(2.0, 2.0);

	// getter vị trí cuối cùng quả bóng
	ball.posXend = ball.imgSpr.getTexture()->getSize().x * ball.imgSpr.getScale().x;
	ball.posYend = ball.imgSpr.getTexture()->getSize().y * ball.imgSpr.getScale().y;

	// điều chỉnh vị trí
	ball.imgSpr.setPosition(ball.posX - ball.posXend * 1.0 / 2, ball.posY);
}
