//
//  Object.cpp
//  PongGame
//
//  Created by Thanh Phong Nguyen Dien on 12/5/19.
//  Copyright © 2019 Thanh Phong Nguyen Dien. All rights reserved.
//

#include "Object.hpp"

float Object::DisBet2Point(sf::Vector2f point1, sf::Vector2f point2){
    return sqrt(sqr(point1.x - point2.x) + sqr(point2.y - point2.y));
}
