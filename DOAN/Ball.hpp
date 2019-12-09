#ifndef Ball_hpp
#define Ball_hpp

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


#define _NAME_GAME_ "The Pong Game"


class buildStage;
class ThePong {
private:
    float posX;
    float posY;

    sf::Texture textureBall;
    sf::Sprite imgSpr;

    float posXend;  // width
    float posYend;  // heigh

    float velocityX;
    float velocityY;
    float acceleration;

    TextShow point1;
    TextShow point2;
    TextShow point3;
    TextShow point4;
    
    TextShow pointX[9];

public:
    ThePong();
    ThePong(float, float, float, float);
    virtual ~ThePong();

    void setter();
    
    void setPosX(float x);
    void setPosY(float y);
	void setPosXend(float x);
	void setPosYend(float y);

    float getPosX();
    float getPosY();
    float getVelocityX();
    float getVelocityY();

    void updateVelocityX();
    void updateVelocityY();

    void resetPong(short toward); //     -1 - left ;     0 - random ;    1 - right

    void scale(float width, float heigh);
    short moveBall(Pos positionBar, buildStage &stage, int &score);

    bool checkClashToBar(Pos position);
    void normalizePosX();
    void normalizePosY();
    
    sf::FloatRect getBoundBall();
    sf::Vector2f returnPosOnBorder(sf::FloatRect brick, sf::FloatRect presentBall, sf::FloatRect pastBall);

    void draw(sf::RenderWindow& window);
	friend class zoomBall;
};

#endif /* Ball_hpp */
