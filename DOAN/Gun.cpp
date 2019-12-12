//
//  Gun.cpp
//  PongGame
//
//  Created by Thanh Phong Nguyen Dien on 12/12/19.
//  Copyright © 2019 Thanh Phong Nguyen Dien. All rights reserved.
//

#include "Gun.hpp"


Gun::Gun(){
    
    this->lastRotate = 90.0;
    
    this->texDais.loadFromFile("res/img/Dais.png", sf::IntRect(34, 31, 130, 68));
    this->texGun.loadFromFile("res/img/Gun.png", sf::IntRect(43,71,129,41));
    
    this->sprDais.setTexture(this->texDais);
    this->sprGun.setTexture(this->texGun);
//    this->sprGun.rotate(-90);
    
    sf::FloatRect bound = this->sprGun.getGlobalBounds();
    this->sprGun.rotate(-90);
    this->sprGun.scale(0.5, 0.7);
    this->sprGun.setOrigin(bound.left + bound.width/4, bound.top + bound.height/2);
    this->sprGun.setPosition(_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_ * 1.0 / 2, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_);
    
    
    bound = this->sprDais.getGlobalBounds();
    this->sprDais.scale(0.5, 0.5);
    this->sprDais.setOrigin(bound.left + bound.width/2, bound.top + bound.height);
    this->sprDais.setPosition(_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_ * 1.0 / 2, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_);
    
}
Gun::~Gun(){
    
}

void Gun::fire(){
    
}
void Gun::rotateGun(float degree){
    this->sprGun.rotate(this->lastRotate - degree);
    this->lastRotate = degree;
}

void Gun::draw(sf::RenderWindow &window){
    window.draw(this->sprDais);
    window.draw(this->sprGun);
    
}
