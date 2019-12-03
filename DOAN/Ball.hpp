//#pragma once
//#include "Console.h"
//
//
//enum BallDirection	//các di chuyển của ball
//{
//	STOP, 
//	UPLEFT, 
//	UPRIGHT,
//	DOWNLEFT,
//	DOWNRIGHT,
//};
//class Ball
//{
//private:
//	COORD current;	//vị trí hiện tại
//	COORD original;	//vị trí gốc
//	float speed;	//tốc độ
//	BallDirection direction;	//hướng di chuyển
//public:
//	Ball(int x, int y);
//	~Ball();
//	//trả về vị trí hiện tại
//	COORD getPosition();
//	//in quả bóng ra màn hình
//	void print();
//	//đưa về vị trí gốc
//	void reset();
//	//trả về hướng di chuyển
//	BallDirection getDirection();
//	//thay đổi hướng di chuyển
//	void changeDirection(BallDirection dir);
//	//lên phải
//	void moveUpRight();
//	//lên trái
//	void moveUpLeft();
//	//xuống phải
//	void moveDownRight();
//	//xuống trái
//	void moveDownLeft();
//	//tăng tốc độ
//	void speedUp();
//};
//


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
    void setPosY(float y);
    float getPosX();
    float getPosY();
    float getVelocityX();
    float getVelocityY();

    void updateVelocityX();
    void updateVelocityY();

    void resetPong(short toward); //     -1 - left ;     0 - random ;    1 - right

    void scale(float width, float heigh);
    short moveBall(sf::RenderWindow& window, Pos positionBar);
//    short moveBall(sf::RenderWindow& window);

    bool checkClashToBar(Pos position);
    void normalizePosX();
    void normalizePosY();

    void draw(sf::RenderWindow& window);
};



#endif /* Ball_hpp */
