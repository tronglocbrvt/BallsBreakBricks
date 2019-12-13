#ifndef Ball_hpp
#define Ball_hpp
#define _USE_MATH_DEFINES
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BackGround.hpp"
#include "DataPos.hpp"
#include "TextClass.hpp"
#include <string>
#include <ctime>
#include <math.h>
#include "rewardItem.h"
#include "buildStage.hpp"


#define _MAX_RAD_BET_VEC_Ox_ 10

class TheBar;
class buildStage;
class ThePong {
private:
    
    sf::FloatRect pastBall;
    
    float posX;
    float posY;

    sf::Texture textureBall;
    sf::Sprite imgSpr;

    float posXend;  // width
    float posYend;  // heigh

    float velocityX;
    float velocityY;
    float acceleration;
    
    bool crashedIntoTreasure;

    TextShow point1;
    TextShow point2;
    TextShow point3;
    TextShow point4;
    
    TextShow pointX[9];
    
    sf::Vertex lineBall[2];

public:
    ThePong();
    ThePong(float, float, float, float);
    virtual ~ThePong();

    void setter();
    
    void setPosX(float x);
    void setPosY(float y);
	void setPosXend(float x);
	void setPosYend(float y);
    void setVelocityXY(float velocityX, float velocityY);
    void setMidBot();

    float getHeight();
    float getWidth();
    float getPosX();
    float getPosY();
    float getVelocityX();
    float getVelocityY();

    void updateVelocityX();
    void updateVelocityY();

    void resetPong(short toward); //     -1 - left ;     0 - random ;    1 - right
    void resetPositionToMidBot();

    void scale(float width, float heigh);
    short moveBall(Pos positionBar, buildStage &stage, float &score, float &timeEnd, int& checkGift, TheBar& bar, BackGround& bg);

    bool checkClashToBar(Pos position);
    void normalizePosX();
    void normalizePosY();
    
    sf::FloatRect getBoundBall();
    sf::Vector2f returnPosOnBorder(sf::FloatRect brick, sf::FloatRect presentBall, sf::FloatRect pastBall);
    
    bool checkGoDown();
    bool checkGoLeft();
    
    sf::Vector2f posAtBotInFuture();
    float lengthOfVector();
    float distanceToPointFromCenter(sf::Vector2f point);
    sf::Vector2f middle();
    
    bool isNearlyVertical();
    bool isGotTreasure();
    float getVecloc();
    sf::Vector2f getReflexInfut(float posYFut, sf::Vector2f from);

    void draw(sf::RenderWindow& window);
	friend class zoomBall;
};

#endif /* Ball_hpp */
