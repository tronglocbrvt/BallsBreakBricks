#ifndef RockBricks_hpp
#define RockBricks_hpp

#include "Brick.hpp"

class RockBrick : public Brick {
protected:
    sf::RectangleShape rectangle;
public:
    RockBrick();
    virtual ~RockBrick();
    
    virtual short getScore();
    virtual void destroy();
};

#endif /* RockBricks_hpp */
