#ifndef Object_hpp
#define Object_hpp
#include <SFML/Graphics.hpp>

class Object
{
private:
    sf::Texture textureImg;
    sf::Sprite spriteImg;
public:
	virtual ~Object() {};
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void move() = 0;
	virtual int collision(sf::FloatRect&) = 0;

//	bool deleteObject = false; // gạch đã được va chạm chưa, nếu true thì xóa gạch
};
#endif
