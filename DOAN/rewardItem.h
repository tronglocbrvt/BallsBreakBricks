#ifndef rewardItem_hpp
#define rewardItem_hpp

#include "Ball.hpp"
#include "Paddle.hpp"


class ThePong;
class TheBar;
class buildStage;
class rewardItem
{
protected:
	sf::Texture textSpecial;
	sf::Sprite imgSpecial;

public:
	rewardItem();
	virtual ~rewardItem();

	virtual void runItem(float& score, int i, int j, buildStage &stage);
	virtual void runItem(TheBar& bar);
	virtual void runItem(ThePong& ball);
	void drawItem(sf::RenderWindow& window);
};

//===============================================================

class doubleScore :public rewardItem
{
public:
	doubleScore();
	virtual ~doubleScore();

	void runItem(float &score, int i, int j, buildStage& stage);
};

//===============================================================

class divideScore :public rewardItem
{
public:
	divideScore();
	virtual ~divideScore();

	void runItem(float& score, int i, int j, buildStage& stage);
};


//===============================================================

class widenBar :public rewardItem
{
public:
	widenBar();
	virtual ~widenBar();

	void runItem(TheBar& bar);
};

//===============================================================

class zoomBall :public rewardItem
{
public:
	zoomBall();
	virtual ~zoomBall();

	void runItem(ThePong& ball);
};

#endif

