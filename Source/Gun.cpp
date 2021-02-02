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
    
    this->texDais.loadFromFile("res/img/Dais.png");
    this->texGun.loadFromFile("res/img/Gun.png");
    
    this->sprDais.setTexture(this->texDais);
    this->sprGun.setTexture(this->texGun);
//    this->sprGun.rotate(-90);
    
    sf::FloatRect bound = this->sprGun.getGlobalBounds();
    this->sprGun.scale(0.7, 0.5);
    this->sprGun.setOrigin(bound.left + bound.width/2, bound.top + bound.height*3/4);
    this->sprGun.setPosition(_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_ * 1.0 / 2, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_);
    this->sprGun.setOrigin(bound.left + bound.width/2, bound.top + bound.height*3/4);
    
    
    bound = this->sprDais.getGlobalBounds();
    this->sprDais.scale(0.5, 0.5);
    this->sprDais.setOrigin(bound.left + bound.width/2, bound.top + bound.height);
    this->sprDais.setPosition(_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_ * 1.0 / 2, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_);
    this->sprDais.setOrigin(bound.left + bound.width/2, bound.top + bound.height);
}
Gun::~Gun(){
    
}

void Gun::fire(sf::RenderWindow &window, BackGround &bg, buildStage &stage, ThePong &ball){
  
}
void Gun::rotateGun(float degree){
    this->sprGun.rotate(this->lastRotate - degree);
    this->lastRotate = degree;
}
sf::Vector2f Gun::getOrigin(){
    return this->sprGun.getOrigin();
}

void Gun::draw(sf::RenderWindow &window){
    window.draw(this->sprDais);
    window.draw(this->sprGun);
    
}
