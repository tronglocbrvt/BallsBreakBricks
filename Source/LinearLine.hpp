//
//  LinearLine.hpp
//  PongGame
//
//  Created by Thanh Phong Nguyen Dien on 12/15/19.
//  Copyright © 2019 Thanh Phong Nguyen Dien. All rights reserved.
//

#ifndef LinearLine_hpp
#define LinearLine_hpp

#include "Define_Header.h"

class LinearLine {
protected:
    // y = ax + b
    
    float alp;
    float bet;
    
    bool isHorizontalLine;
    bool isVerticalLine;
    
    sf::Vertex line[2];
    
public:
    LinearLine(){}
    LinearLine(sf::Vector2f from, sf::Vector2f to);
    
    void set(sf::Vector2f from, sf::Vector2f to);
    
    float getX(float y);
    float getY(float x);
    float getAlp();
    
    bool checkHorizontal();
    bool checkVertial();
    
    void draw(sf::RenderWindow &window);
};

#endif /* LinearLine_hpp */
