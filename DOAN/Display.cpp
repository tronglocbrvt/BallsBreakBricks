#include "Display.hpp"

Display::Display()
{
}

Display::Display(float width, float height)
{
	// load file background image
	if (!backgroundMenu.loadFromFile("res/img/Menu_DoAn2_3D.jpg"))
	{
		std::cout << "Load file failed" << std::endl;
	}

	bgMenu.setTexture(backgroundMenu);
	bgMenu.scale(0.8, 0.8);
	bgMenu.setPosition(0, 0);

	// font Game Name: PONG GAME
	if (!fontGameName.loadFromFile("res/fnt/venus.ttf"))
	{
		std::cout << "Load font failed" << std::endl;
	}

	// set gameName
	gameName.setFont(fontGameName);
	gameName.setFillColor(sf::Color::Yellow);
	gameName.setString("BALLS BREAK BRICKS");
	gameName.setStyle(sf::Text::Bold);
	gameName.setCharacterSize(50);

	// set gameName position
	// center Ox
	sf::FloatRect textRect(gameName.getLocalBounds());
	gameName.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2);
	gameName.setPosition(sf::Vector2f((width / 2), 70));

}

Display::~Display()
{
}

bool Display::clickMouse(sf::Text Text, sf::RenderWindow& window) // kiểm tra chuôt có click không
{
	sf::IntRect rect(Text.getPosition().x, Text.getPosition().y, Text.getGlobalBounds().width, Text.getGlobalBounds().height);

	if (rect.contains(sf::Mouse::getPosition(window)))
	{
		return true;
	}

	return false;
}

void Display::setPositionText(sf::Text& text, float height)
{
	// căn chỉnh giữa (center)
	sf::FloatRect textRect(text.getLocalBounds());
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2);
	text.setPosition(sf::Vector2f(_WIDTH_SCREEN / 2, height));
}

void Display::drawMenu(sf::RenderWindow& window)
{
	window.draw(bgMenu); // vẽ background menu
	window.draw(gameName); // vẽ tiêu đề "PONG GAME"
}
