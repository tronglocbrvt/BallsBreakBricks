//
//  SpecialLevel.cpp
//  PongGame
//
//  Created by Thanh Phong Nguyen Dien on 12/11/19.
//  Copyright © 2019 Thanh Phong Nguyen Dien. All rights reserved.
//

#include "SpecialLevel.hpp"


SpecialLevel::SpecialLevel(int stage) : bg(2), stage(std::string("SpecialStage") + std::to_string(stage) + std::string(".txt")){
    
    this->bg.setTurn(1);
    this->ball.setPosY(_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - ball.getHeight());
    
//    this->stage = 1;
    this->nameFile = std::string("SpecialStage") + std::to_string(stage) + std::string(".txt");
    this->health = 3;
    
    this->wayOfBall[0] = sf::Vertex(sf::Vector2f(this->ball.middle().x, this->ball.middle().y), sf::Color::Red);
    this->wayOfBall[1] = sf::Vertex(sf::Vector2f(this->ball.middle().x, this->ball.middle().y), sf::Color::Red);
    
}
SpecialLevel::~SpecialLevel(){
    
}

void SpecialLevel::loadStage(int stage){
    
}

void SpecialLevel::showLoading(){
    
}
bool SpecialLevel::pauseGame(sf::RenderWindow& window, TextShow &text, sf::Keyboard::Key key){
    
    // start ball when press space
    while (window.isOpen()) {
        sf::Event event;
        // bắt sự kiện
        
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyPressed:         // sự kiện nhấn phím
                if (sf::Keyboard::isKeyPressed(key))
                {
                    return true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    return false;
                }
                break;
            case sf::Event::Closed:             // sự kiện đóng cửa sổ
                window.close();
                break;
            default:
                continue;
            }
        }
        
        // in ra màn hình game
        window.clear();
        
        this->bg.draw(window);
//        bar.draw(window);
        this->ball.draw(window);
        this->stage.draw(window);
        text.drawText(window);
        
        window.display();
    }
    return true;
}

void SpecialLevel::setLine(sf::Vector2i toward){
    
    sf::Vector2f from = this->ball.middle();
    sf::Vector2f to;

    if (toward.x == from.x) {
        // x = a
        to.x = from.x;
        to.y = _DIS_FROM_TOP_;
    }
    else
    {
        // y = alp * x + bet
        float alp = (toward.y - from.y) / (toward.x - from.x);
        float bet = from.y - alp * from.x;

        if (toward.x > from.x) {
            to.x = _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_;
        }
        else
        {
            to.x = _DIS_FROM_LEFT_;
        }

        to.y = alp * to.x + bet;

        if (to.y < _DIS_FROM_TOP_) {
            to.y = _DIS_FROM_TOP_;
            to.x = (to.y - bet) / alp;
        }
        
        if (to.y > _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _MIN_Y_) {
            to.y = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _MIN_Y_;
            to.x = (to.y - bet) / alp;
            if (to.x > _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_) {
                to.x = _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_;
            }
            else if (to.x < _DIS_FROM_LEFT_){
                to.x = _DIS_FROM_LEFT_;
            }
        }
    }

    
    float degree = atan( (from.y - to.y) / (to.x - from.x) ) * 180 / M_PI;
    if (degree < 0) {
        degree = 180 + degree;
    }
    this->gun.rotateGun(degree);
    
    
    this->wayOfBall[0] = sf::Vertex(sf::Vector2f(from.x, from.y), sf::Color::Red);
    this->wayOfBall[1] = sf::Vertex(sf::Vector2f(to.x, to.y), sf::Color::Red);


    // set veloc of ball
    const float velocRate = 1.5;
    float lVec = sqrt(sqr(from.x - to.x) + sqr(from.y - to.y));
    ball.setVelocityXY(_VELOCITY_X_ * velocRate / lVec * (to.x - from.x), _VELOCITY_Y_ * velocRate / lVec * (to.y - from.y));
    
}
sf::Vector2i SpecialLevel::chooseLineOfFire(sf::RenderWindow& window){
    while (window.isOpen()) {
        sf::Event event;
        // bắt sự kiện

        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::MouseButtonPressed:         // sự kiện nhấn phím
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    return sf::Mouse::getPosition(window);
                }
                break;
            case sf::Event::MouseMoved:
                this->setLine(sf::Mouse::getPosition(window));
                break;
            case sf::Event::Closed:             // sự kiện đóng cửa sổ
                window.close();
                break;
            default:
                continue;
            }
        }

        // in ra màn hình game
        window.clear();

        this->bg.draw(window);
//        bar.draw(window);
        this->ball.draw(window);
        this->stage.draw(window);
        window.draw(this->wayOfBall, 2, sf::Lines);
        this->gun.draw(window);
        
        window.display();
    }
    return sf::Vector2i();
}

short SpecialLevel::runGame(sf::RenderWindow &window){
    // khởi tạo sân, bóng, 2 thanh
    

    // khởi động chuỗi thông báo và tên
    TextShow textshow(std::string("Press Space to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
    textshow.scale(0.8);
    textshow.setOriginToMidle();
    textshow.setColor(4, 74, 194);

    float score = 0;

//    if (!this->pauseGame(window, textshow, sf::Keyboard::Space)) {
//        return 0;
//    }
    
    this->setLine(this->chooseLineOfFire(window));
    
    // start game

    stage.startClock();
    while (window.isOpen()) {
        sf::Event event;

        // bắt sự kiện
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    return 0;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                {

                    TextShow textshow(std::string("Press P to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
                    textshow.scale(0.8);
                    textshow.setOriginToMidle();
                    textshow.setColor(4, 74, 194);

                    this->pauseGame(window, textshow, sf::Keyboard::P);
                }
            }
//            if (event.type == sf::Event::MouseMoved){
//                static int count = 0;
//                std::cout << "Yasuo " << (count++) << std::endl;
//            }
            
        }
		float timeEnd = -1;
		int checkGift = 0;
		TheBar bar;
		short staticOfBall = ball.moveBall(copyPos(0,0,0,0), stage, score, timeEnd, checkGift, bar, window);
        //short staticOfBall = ball.moveBall(copyPos(0, 0, 0, 0), this->stage, score);
        this->stage.updateTime();

        if (staticOfBall == 1) {    // crashed into bottom line
            this->health--;
            if (!this->pauseGame(window, textshow, sf::Keyboard::Space)) {  // esc game
                return 0;
            }
            else {
                this->bg.setTurn(3 - this->health +1);
                if (this->health == 0) {        // hết mạng để chơi
                    // do something
                    return EndGame(window, this->stage, (this->ball.isGotTreasure() ? 100 : 0), this->level, ball.isGotTreasure());
                }
                else
                {
                    this->ball.resetPositionToMidBot();
                    this->setLine(this->chooseLineOfFire(window));
                }
            }
        }
        if (this->ball.isGotTreasure()) {
            EndGame(window, this->stage, 100, this->level, true);
        }


        // in ra màn hình game
        window.clear();

        this->bg.draw(window);
//        bar.draw(window);
        this->ball.draw(window);
        this->stage.draw(window);
        this->gun.draw(window);
//        window.draw(this->wayOfBall, 2, sf::Lines);
        
        window.display();
    }
    return 0;
}
