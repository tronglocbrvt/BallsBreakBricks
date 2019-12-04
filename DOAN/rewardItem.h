#ifndef rewardItem_hpp
#define rewardItem_hpp

#include "Paddle.hpp"
#include "Brick.hpp"

class ThePong;
class rewardItem
{
public:
	rewardItem();
	virtual ~rewardItem();

	//void doubleScore();
	//void separateScore();
	//void fireBall();
	//void widenBar();
	void zoomBall(ThePong&);

};

#endif

