
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

#define _NAME_GAME_ "The Pong Game"



class ThePong {
private:
    float posX;
    float posY;

    sf::Texture textureBall;
    sf::Sprite imgSpr;

    float posXend;
    float posYend;

    float velocityX;
    float velocityY;
    float acceleration;

    TextShow point1;
    TextShow point2;
    TextShow point3;
    TextShow point4;

public:
    ThePong();
    ThePong(float, float, float, float);
    virtual ~ThePong();

    void setPosX(float x);
	void setImgSpr(float);
    void setPosY(float y);
	void setPosXend(float x);
	void setPosYend(float y);
	void setPositionImgSpr(float x, float y);

    float getPosX();
    float getPosY();
    float getVelocityX();
    float getVelocityY();
	sf::Sprite getImgSpr();

    void updateVelocityX();
    void updateVelocityY();

    void resetPong(short toward); //     -1 - left ;     0 - random ;    1 - right

    void scale(float width, float heigh);
    short moveBall(sf::RenderWindow& window, Pos positionBar);
//    short moveBall(sf::RenderWindow& window);

    bool checkClashToBar(Pos position);
    void normalizePosX();
    void normalizePosY();
    
    sf::FloatRect getBoundBall();

    void draw(sf::RenderWindow& window);
	friend class rewardItem;
};



#endif /* Ball_hpp */
