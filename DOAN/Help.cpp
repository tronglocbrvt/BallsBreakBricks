#include "Help.hpp"

helpMenu::helpMenu()
{

}

helpMenu::helpMenu(float width, float height) :Display(width, height)
{

	// set thông số đồ họa cho tiêu đề
	if (!font.loadFromFile("res/fnt/venus.ttf"))
	{
		std::cout << "Load font failed" << std::endl;
	}

	helpHeadText.setFont(font);
	helpHeadText.setFillColor(sf::Color::Yellow);
	helpHeadText.setString("HELP");
	helpHeadText.setStyle(sf::Text::Underlined);
	helpHeadText.setCharacterSize(50);

	// set thông số đồ họa cho các dòng hướng dẫn
	setPositionText(helpHeadText, 140);

	if (!fontText.loadFromFile("res/fnt/JerseyM54.ttf"))
	{
		std::cout << "Load font failed" << std::endl;
	}

	setText(0, "GAME WITH PLAYER\n");
	helpText[0].setFillColor(sf::Color::Green);
	setPositionText(helpText[0], 220);

	setText(2, "SCORING METHOD\n");
	helpText[2].setFillColor(sf::Color::Green);
	setPositionText(helpText[2], 340);

	setText(5, "PRESS SPACE TO START, PRESS P TO PAUSE/CONTINUE GAME");
	helpText[5].setFillColor(sf::Color::Green);
	setPositionText(helpText[5], 490);

	setText(6, "PRESS ESC TO COME BACK MAIN MENU ANYTIME\n");
	helpText[6].setFillColor(sf::Color::Magenta);
	helpText[6].setStyle(sf::Text::Bold);
	setPositionText(helpText[6], 530);

	if (!fontText.loadFromFile("res/fnt/Truly.otf"))
	{
		std::cout << "Load font failed" << std::endl;
	}

	setText(1, "Press A or left-key to Move left\nPress D or right-key to Move right");
	helpText[1].setCharacterSize(25);
	setPositionText(helpText[1], 260);

	setText(3, "Red Brick: 1\t\tPurple Brick: 2\t\tBlue Brick: 3");
	helpText[3].setCharacterSize(25);
	setPositionText(helpText[3], 370);

	setText(7, "Gift Brick: Double Score, Divide Score, Fire Ball, Zoom Ball, Widen Bar, Become Rock");
	helpText[7].setCharacterSize(25);
	setPositionText(helpText[7], 400);

	setText(4, "LAST SCORE DEPENDS ON FINISHED TIME STAGE");
	helpText[4].setCharacterSize(25);
	setPositionText(helpText[4], 430);
}

helpMenu::~helpMenu()
{
}

void helpMenu::setText(int select, std::string nameOption)
{
	// set các thông số đồ họa cho Text
	helpText[select].setFont(fontText);
	helpText[select].setCharacterSize(40);
	helpText[select].setFillColor(sf::Color::White);
	helpText[select].setStyle(sf::Text::Regular);
	helpText[select].setString(nameOption);
}

void helpMenu::drawMenu(sf::RenderWindow& window)
{
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					return;
				}
			}
			window.clear();
			Display::drawMenu(window);
			window.draw(helpHeadText); // in tiêu đề "HELP"

			// in các dòng chữ hướng dẫn
			for (int i = 0; i < 10; i++)
				window.draw(helpText[i]);

			window.display();
		}
	}
}


