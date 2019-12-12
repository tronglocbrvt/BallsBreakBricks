//
//  SpecialLevel.hpp
//  PongGame
//
//  Created by Thanh Phong Nguyen Dien on 12/11/19.
//  Copyright © 2019 Thanh Phong Nguyen Dien. All rights reserved.
//

#ifndef SpecialLevel_hpp
#define SpecialLevel_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include "PvsP.hpp"
#include "buildStage.hpp"

#define _MIN_RADIAN_ 40
#define _MIN_Y_ (((_WIDTH_TABLE_GAME_ * 1.0) / 2) * tan(_MIN_RADIAN_ * M_PI / 180))

class SpecialLevel{
protected:
    std::string nameFile;
    int level;
    short health;
    
    ThePong ball;
    buildStage stage;
    BackGround bg;
    
    sf::Mouse mouse;
    sf::Vertex wayOfBall[2];
    
public:
    SpecialLevel(int stage);
    virtual ~SpecialLevel();
    
    virtual void loadStage(int stage);
    
    virtual void showLoading();
    virtual bool pauseGame(sf::RenderWindow& window, TextShow &text, sf::Keyboard::Key key);
    
    virtual void setLine(sf::Vector2i toward);
    virtual sf::Vector2i chooseLineOfFire(sf::RenderWindow& window);
    virtual short runGame(sf::RenderWindow &window);
    
};

#endif /* SpecialLevel_hpp */
