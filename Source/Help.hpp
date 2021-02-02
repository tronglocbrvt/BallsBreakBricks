#ifndef Help_hpp
#define Help_hpp
#include "Ball.hpp"
#include "Display.hpp"

class helpMenu:public Display
{
private:
	sf::Text helpHeadText;
	sf::Font font;

	sf::Text helpText[10];
	sf::Font fontText;
public:
	helpMenu();
	helpMenu(float, float);
	virtual ~helpMenu();

	void setText(int, std::string nameOption);
	void drawMenu(sf::RenderWindow& window);
};
#endif


