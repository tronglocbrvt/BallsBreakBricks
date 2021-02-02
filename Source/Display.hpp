#ifndef Display_hpp
#define Display_hpp
///#include "Ball.hpp"
#include "TextClass.hpp"

class Display
{
protected:
	sf::Texture backgroundMenu;
	sf::Sprite bgMenu;
	sf::Font fontGameName;
	sf::Text gameName;

public:
	Display();
	Display(float, float);
	virtual ~Display();

	bool clickMouse(sf::Text Text, sf::RenderWindow& window);
	void setPositionText(sf::Text&, float);
	virtual void drawMenu(sf::RenderWindow& window);
};

#endif
