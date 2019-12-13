//
//  Gun.hpp
//  PongGame
//
//  Created by Thanh Phong Nguyen Dien on 12/12/19.
//  Copyright © 2019 Thanh Phong Nguyen Dien. All rights reserved.
//

#ifndef Gun_hpp
#define Gun_hpp

#include <SFML/Graphics.hpp>
#include "Define_Header.h"

#include "BackGround.hpp"
#include "Ball.hpp"
#include "buildStage.hpp"

class Gun {
protected:
    sf::Texture texDais;
    sf::Texture texGun;
    
    sf::Sprite sprDais;
    sf::Sprite sprGun;
    
    float lastRotate;
    
public:
    Gun();
    virtual ~Gun();
    
    virtual void fire(sf::RenderWindow &window, BackGround &bg, buildStage &stage, ThePong &ball);
    virtual void rotateGun(float degree);
    virtual sf::Vector2f getOrigin();
    
    virtual void draw(sf::RenderWindow &window);
};

#endif /* Gun_hpp */
