#ifndef continueGame_hpp
#define continueGame_hpp
#include "Ball.hpp"
#include "TextClass.hpp"
#include "ComputerPlay.hpp"
#include "highScore.hpp"
#include <string>
#include <fstream>
#include "buildStage.hpp"

class buildStage;
class continueGame
{
private:
	float ballPosX;
	float ballPosY;
	float ballVelocX;
	float ballVelocY;

	float barPosX;
	float barPosY;

	float score;
	
	bool mode; // 0: person; 1: computer
	int level;
	buildStage stage;

	int checkGift;
	float timeEnd;
public:
	continueGame();
	virtual ~continueGame();
	int runContinueGame(sf::RenderWindow& window);
};
#endif
