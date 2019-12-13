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
    float maxSpeed;
    sf::Vector2f catchPoint;
    
    std::string namePlayer;
    int scores;
    
    TextShow points;
    
public:
    TheBar();
    TheBar(bool, float, float, int);
    virtual ~TheBar();
    
    void setNamePlayer(std::string name);
    int getScores();
    std::string getNameplayer();
    
    void setScores(int score);
	void setLongBar(float length);
	void setHeightBar(float height);
    void setPosY(float y);
    void setCatchPoint(sf::Vector2f point);
    
    sf::Vector2f getCatchPoint();
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
    
    float getPosMidXOfPaddle();
    
    void speedUp(float rate);
    float getSpeed();
    bool checkAbove(sf::Vector2f point);
    float disToBar(sf::Vector2f point);
    void moveToMidTabGame();
    
    float rateOfChange(sf::FloatRect rect);
    
};


#endif
