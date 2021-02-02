//
//  LinearLine.cpp
//  PongGame
//
//  Created by Thanh Phong Nguyen Dien on 12/15/19.
//  Copyright © 2019 Thanh Phong Nguyen Dien. All rights reserved.
//

#include "LinearLine.hpp"


LinearLine::LinearLine(sf::Vector2f from, sf::Vector2f to){
    
    this->alp = 0;
    this->bet = 0;
    this->isVerticalLine = false;
    this->isHorizontalLine = false;
    
    if (from.x == to.x) {
        this->isVerticalLine = true;
        
        this->line[0] = sf::Vertex(sf::Vector2f(from.x, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_), sf::Color::Black);
        this->line[1] = sf::Vertex(sf::Vector2f(to.x, _DIS_FROM_TOP_), sf::Color::Black);
        
        return;
    }
    else if (from.y == to.y){
        this->isHorizontalLine = true;
        
        this->line[0] = sf::Vertex(sf::Vector2f(_DIS_FROM_LEFT_, from.y), sf::Color::Black);
        this->line[1] = sf::Vertex(sf::Vector2f(_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_, to.y), sf::Color::Black);
        
        return;
    }
    else
    {
        this->alp = (from.y - to.y) / (from.x - to.x);
        this->bet = from.y - this->alp * from.x;
        
        this->line[0] = sf::Vertex(sf::Vector2f(_DIS_FROM_LEFT_, this->alp * (_DIS_FROM_LEFT_) + this->bet), sf::Color::Black);
        this->line[1] = sf::Vertex(sf::Vector2f(_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_, this->alp * (_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_) + this->bet), sf::Color::Black);
    }
    
}

void LinearLine::set(sf::Vector2f from, sf::Vector2f to){
    this->alp = 0;
    this->bet = 0;
    this->isVerticalLine = false;
    this->isHorizontalLine = false;
    
    if (from.x == to.x) {
        this->isVerticalLine = true;
        
        this->line[0] = sf::Vertex(sf::Vector2f(from.x, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_), sf::Color::Black);
        this->line[1] = sf::Vertex(sf::Vector2f(to.x, _DIS_FROM_TOP_), sf::Color::Black);
        
        return;
    }
    else if (from.y == to.y){
        this->isHorizontalLine = true;
        
        this->line[0] = sf::Vertex(sf::Vector2f(_DIS_FROM_LEFT_, from.y), sf::Color::Black);
        this->line[1] = sf::Vertex(sf::Vector2f(_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_, to.y), sf::Color::Black);
        
        return;
    }
    else
    {
        this->alp = (from.y - to.y) / (from.x - to.x);
        this->bet = from.y - this->alp * from.x;
        
        this->line[0] = sf::Vertex(sf::Vector2f(_DIS_FROM_LEFT_, this->alp * (_DIS_FROM_LEFT_) + this->bet), sf::Color::Black);
        this->line[1] = sf::Vertex(sf::Vector2f(_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_, this->alp * (_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_) + this->bet), sf::Color::Black);
    }
}

float LinearLine::getX(float y){
//    if (this->isHorizontalLine) {
//        return 0;
//    }
//    if (this->isVerticalLine) {
//        <#statements#>
//    }
//
    return (y - this->bet) / this->alp;
}
float LinearLine::getY(float x){
    return (this->alp * x + this->bet);
}

bool LinearLine::checkHorizontal(){
    return this->isHorizontalLine;
}
bool LinearLine::checkVertial(){
    return this->isVerticalLine;
}

void LinearLine::draw(sf::RenderWindow &window){
    window.draw(this->line, 2, sf::Lines);
}

float LinearLine::getAlp(){
    return this->alp;
}
