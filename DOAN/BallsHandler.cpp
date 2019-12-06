#include "BallsHandler.h"

BallsHandler::BallsHandler()
{

}

BallsHandler::~BallsHandler()
{
}

void BallsHandler::moveBalls(sf::RenderWindow& window, TheBar& bar, int i)
{
	//for (int i = 0; i < aliveBalls(); i++)
	//{
		int check = myBalls[i].moveBall(window, copyPos(bar.getPosX(), bar.getPosY(), bar.getWidth(), bar.getHeigh()));

		if (aliveBalls() > 1 && check == -1)
		{
			myBalls.erase(myBalls.begin() + i);
			return;
		}
	//}
}

unsigned int BallsHandler::newBall()
{
	ThePong newBall;
	myBalls.push_back(newBall);
	return myBalls.size();

}

unsigned int BallsHandler::aliveBalls()
{
	return myBalls.size();
}

std::vector<ThePong>& BallsHandler::getBalls()
{
	return myBalls;
}

void BallsHandler::drawBalls(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < aliveBalls(); i++)
	{
		//draw the balls
		myBalls[i].draw(window);
	}
}