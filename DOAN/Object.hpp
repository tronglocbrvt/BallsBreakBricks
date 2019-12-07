#ifndef Object_hpp
#define Object_hpp
#include <SFML/Graphics.hpp>

class Object
{
private:
    sf::Texture imgTex;
    sf::Sprite imgSpr;
public:
	virtual ~Object() {};
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void move() = 0;
	virtual int collision(sf::FloatRect&) = 0;
    virtual void destroy() = 0;
    
};
#endif
