//#pragma once
//#include "Console.h"
//
//class Paddle
//{
//private:
//	COORD current;	//vị trí hiện tại
//	COORD original;	//vị trí gốc
//
//public:
//	
//	Paddle(int x, int y);
//	~Paddle();
//	//trả về vị trí hiện tại
//	COORD getPosition();
//	//in thanh trượt
//	void print();
//	//đưa về vị trí gốc
//	void reset();
//	//di chuyển thanh lên
//	void moveUp();
//	//di chuyển thanh xuống
//	void moveDown();
//};
//


#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "BackGround.hpp"
#include "Ball.hpp"

class TheBar {
protected:
    float posX;
    float posY;
    sf::Texture textureBar;
    sf::Sprite imgSpr;
    
    float longBar;
    float heigBar;
    
    float velocityX;
    float acceleration;
    
    std::string namePlayer;
    int scores;
    
public:
    TheBar();
    TheBar(bool, float, int, int, std::string);
    virtual ~TheBar();
    
    void setNamePlayer(std::string name);
    int getScores();
    std::string getNameplayer();
    
    void setScores(int score);
	void setLongBar(float length);
	void setHeightBar(float height);
    void setPosY(float y);
    float getPosX();
    float getPosY();
	sf::Sprite getImgSpr();
    float getWidth();
    float getHeigh();
    float getLongBar();
    
    void scale(float width, float heigh);
    void moveBar(sf::RenderWindow &window, bool Left, bool Right);
    void draw(sf::RenderWindow &window);
    
    void haveScore(short score);
};


#endif
