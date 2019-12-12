#ifndef buildStage_hpp
#define buildStage_hpp

#include "Define_Header.h"
#include "NormalBrick.hpp"
#include "SpecBricks.hpp"
#include "RockBricks.hpp"
#include "Ball.hpp"
#include "rewardItem.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


class buildStage
{
private: 
	std::vector<Object*> listObject;
    float timeLimit;
    int maxScore;
    
    int mSignBricks[_NUMBER_OF_BRICKS_PER_LINE_][_NUMBER_OF_BRICKS_PER_LINE_];
    
    Brick* mStage[_NUMBER_OF_BRICKS_PER_LINE_][_NUMBER_OF_BRICKS_PER_LINE_];
    
//    rewardItem *mItem;
    
    sf::Clock clock;
    sf::Time time;
    
public:
	buildStage();
    buildStage(int stage);
    
    //void breakTheBrick(const sf::FloatRect& ballBound);
	void setTime(float);
    void startClock();
    void draw(sf::RenderWindow &window);
	int getmSignBricks(int i, int j);
	Brick* getmStage(int i, int j);
    float getTimeLimit();
    float getTimePlaying();
    void updateTime();
    int getMaxScore();
    friend class ThePong;
	friend class continueGame;
};

#endif
