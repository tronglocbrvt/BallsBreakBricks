#ifndef modeGame_hpp
#define modeGame_hpp
#include "Menu.hpp"
#include "levelChoice.hpp"

class modeGame:public Display
{
private:
	sf::Text textMode[2]; 
	sf::Font fontMode;
	int select;
public:
	modeGame();
	virtual ~modeGame();
	modeGame(float, float);

	void drawMenu(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void mouseMoved(sf::RenderWindow& windows);
	int mouseSelect(sf::RenderWindow& window);
	int mouseSelectHigh(sf::RenderWindow& window);
	void runModeGame(sf::RenderWindow& window);
	void runModeHigh(sf::RenderWindow& window);
	int GetPressedItem();
};

#endif