//
//  SpecBricks.hpp
//  PongGame
//
//  Created by Thanh Phong Nguyen Dien on 12/7/19.
//  Copyright © 2019 Thanh Phong Nguyen Dien. All rights reserved.
//

#ifndef SpecBricks_hpp
#define SpecBricks_hpp

#include "Brick.hpp"

class SpecBricks : public Brick {
protected:
    sf::RectangleShape rectangle;
public:
    SpecBricks();
    virtual ~SpecBricks();
    
    virtual void destroy();
};

#endif /* SpecBricks_hpp */
