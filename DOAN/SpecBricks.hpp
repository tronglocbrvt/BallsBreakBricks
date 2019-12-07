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
