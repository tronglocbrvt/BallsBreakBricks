#ifndef Gun_hpp
#define Gun_hpp

#include <SFML/Graphics.hpp>
#include "Define_Header.h"

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
    
    virtual void fire();
    virtual void rotateGun(float degree);
    
    virtual void draw(sf::RenderWindow &window);
};

#endif /* Gun_hpp */
