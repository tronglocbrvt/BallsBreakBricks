#ifndef buildStage_hpp
#define buildStage_hpp

#include "Define_Header.h"
#include "Brick.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


class buildStage
{
private: 
	std::vector<Object*> listObject;
    
    int mSignBricks[_NUMBER_OF_BRICKS_PER_LINE_][_NUMBER_OF_BRICKS_PER_LINE_];
    
//    sf::RectangleShape mStage[_NUMBER_OF_BRICKS_PER_LINE_][_NUMBER_OF_BRICKS_PER_LINE_];
    Brick* mStage[_NUMBER_OF_BRICKS_PER_LINE_][_NUMBER_OF_BRICKS_PER_LINE_];
protected:
public:
    buildStage(int stage);
    
    void breakTheBrick(const sf::FloatRect& ballBound);
    
    void draw(sf::RenderWindow &window);
};

#endif
