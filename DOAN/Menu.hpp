#ifndef Menu_hpp
#define Menu_hpp
#define _MAX_CHOICE_MENU 5

#include "Ball.hpp"
#include "listHighScore.hpp"
//#include "continueGame.hpp"
#include "Help.hpp"
#include "PvsP.hpp"
#include "Display.hpp"
#include "modeGame.hpp"
#include <string>

class Menu :public Display
{
private:
	int selectOption;
	sf::Font font;
	sf::Text text[_MAX_CHOICE_MENU];

public:
	Menu();
	Menu(float, float);
	virtual ~Menu();

	void setText(int, std::string nameOption);
	void drawMenu(sf::RenderWindow& window);
	void moveUp();
	void moveDown();

	void mouseMoved(sf::RenderWindow& windows);
	void mouseSelect(sf::RenderWindow& window);

	int GetPressedItem();
};

#endif /* Menu_hpp */