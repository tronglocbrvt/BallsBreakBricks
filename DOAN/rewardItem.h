#ifndef rewardItem_hpp
#define rewardItem_hpp

#include "Ball.hpp"
#include "Paddle.hpp"

class BackGround;
class ThePong;
class TheBar;
class buildStage;
class rewardItem
{
public:
	rewardItem();
	virtual ~rewardItem();

	virtual void runItem(float& score, int i, int j, buildStage &stage);
	virtual void runItem(TheBar& bar);
	virtual void runItem(ThePong& ball);
	virtual void drawItem(BackGround& bg) = 0;
};

//===============================================================

class doubleScore :public rewardItem
{
public:
	doubleScore();
	virtual ~doubleScore();

	void runItem(float &score, int i, int j, buildStage& stage);
	void drawItem(BackGround& bg);
};

//===============================================================

class divideScore :public rewardItem
{
public:
	divideScore();
	virtual ~divideScore();

	void runItem(float& score, int i, int j, buildStage& stage);
	void drawItem(BackGround& bg);
};


//===============================================================

class widenBar :public rewardItem
{
public:
	widenBar();
	virtual ~widenBar();

	void runItem(TheBar& bar);
	void drawItem(BackGround& bg);
};

//===============================================================

class zoomBall :public rewardItem
{
public:
	zoomBall();
	virtual ~zoomBall();

	void runItem(ThePong& ball);
	void drawItem(BackGround& bg);
};

#endif

