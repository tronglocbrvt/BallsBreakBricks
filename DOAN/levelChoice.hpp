#ifndef levelChoice_hpp
#define levelChoice_hpp
#include "Menu.hpp"

class levelChoice :public Display
{
private:
	sf::Text textMode[6];
	sf::Font fontMode;
	int select;
public:
	levelChoice();
	virtual ~levelChoice();
	levelChoice(float, float);

	void drawMenu(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void mouseMoved(sf::RenderWindow& windows);
	void mouseSelect(sf::RenderWindow& window);
	void runLevelChoice(sf::RenderWindow& window, int choice);
	int GetPressedItem();
};

#endif