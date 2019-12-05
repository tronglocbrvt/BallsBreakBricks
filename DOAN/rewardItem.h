#ifndef rewardItem_hpp
#define rewardItem_hpp

#include "Brick.hpp"
#include "Paddle.hpp"

class ThePong;
class TheBar;
class rewardItem
{
public:
	rewardItem();
	virtual ~rewardItem();

	//void doubleScore();
	//void separateScore();
	//void fireBall();
	void widenBar(TheBar&);
	void zoomBall(ThePong&);
};

#endif

