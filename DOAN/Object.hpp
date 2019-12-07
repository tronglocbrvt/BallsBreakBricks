#ifndef Object_hpp
#define Object_hpp
#include <SFML/Graphics.hpp>

class Object
{
protected:
    sf::Texture imgTex;
    sf::Sprite imgSpr;
public:
	virtual ~Object() {};
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void move() = 0;
	virtual bool collision(sf::FloatRect) = 0;
    virtual void destroy() = 0;
    
};
#endif
