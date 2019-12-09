#ifndef BallsHandler_hpp
#define BallsHandler_hpp
#include "Ball.hpp"
#include "Paddle.hpp"


class BallsHandler
{
private:
	std::vector<ThePong> myBalls; /*Balls array*/
public:
	BallsHandler();
	~BallsHandler();
	void moveBalls(TheBar& bar, buildStage &stage, int, float&);
	unsigned int newBall();
	unsigned int aliveBalls();
	void drawBalls(sf::RenderWindow&);
	std::vector<ThePong>& getBalls();
};

#endif
