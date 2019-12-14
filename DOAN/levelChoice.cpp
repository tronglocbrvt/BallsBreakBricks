#include "levelChoice.hpp"

levelChoice::levelChoice()
{

}

levelChoice::~levelChoice()
{

}

levelChoice::levelChoice(float width, float height) :Display(width, height)
{
	if (!fontMode.loadFromFile("res/fnt/JerseyM54.ttf"))
	{
		std::cout << "Load font failed" << std::endl;
	}

	// set các dòng chữ level
	textMode[0].setFont(fontMode);
	textMode[0].setCharacterSize(60);
	textMode[0].setFillColor(sf::Color::White);
	textMode[0].setStyle(sf::Text::Bold);
	textMode[0].setString("LEVEL 1");
	setPositionText(textMode[0], 150);

	textMode[1].setFont(fontMode);
	textMode[1].setCharacterSize(40);
	textMode[1].setFillColor(sf::Color::Yellow);
	textMode[1].setStyle(sf::Text::Bold);
	textMode[1].setString("LEVEL 2");
	setPositionText(textMode[1], 220);

	textMode[2].setFont(fontMode);
	textMode[2].setCharacterSize(40);
	textMode[2].setFillColor(sf::Color::Yellow);
	textMode[2].setStyle(sf::Text::Bold);
	textMode[2].setString("SPECIAL 1");
	setPositionText(textMode[2],290);

	textMode[3].setFont(fontMode);
	textMode[3].setCharacterSize(40);
	textMode[3].setFillColor(sf::Color::Yellow);
	textMode[3].setStyle(sf::Text::Bold);
	textMode[3].setString("LEVEL 3");
	setPositionText(textMode[3], 360);

	textMode[4].setFont(fontMode);
	textMode[4].setCharacterSize(40);
	textMode[4].setFillColor(sf::Color::Yellow);
	textMode[4].setStyle(sf::Text::Bold);
	textMode[4].setString("LEVEL 4");
	setPositionText(textMode[4], 430);

	textMode[5].setFont(fontMode);
	textMode[5].setCharacterSize(40);
	textMode[5].setFillColor(sf::Color::Yellow);
	textMode[5].setStyle(sf::Text::Bold);
	textMode[5].setString("SPECIAL 2");
	setPositionText(textMode[5], 500);

	select = 0;
}

void levelChoice::drawMenu(sf::RenderWindow& window)
{
	Display::drawMenu(window); // vẽ lại Background trong Display
	for (int i = 0; i < 6; i++)
	{
		window.draw(textMode[i]); // vẽ các dòng chữ thể hiện chế độ chơi
	}
}

void levelChoice::moveUp() // nhấn phím UP
{
	if (select - 1 >= 0)
	{
		textMode[select].setFillColor(sf::Color::Yellow);
		textMode[select].setCharacterSize(40);

		// update position because changing size
		setPositionText(textMode[select], 150 + select * 70);

		select--;

		textMode[select].setFillColor(sf::Color::White);
		textMode[select].setCharacterSize(60);

		// update position because changing size
		setPositionText(textMode[select], 150 + select * 70);
	}
}

void levelChoice::moveDown() // nhấn phím Down
{
	if (select + 1 < 6)
	{
		textMode[select].setFillColor(sf::Color::Yellow);
		textMode[select].setCharacterSize(40);

		// update position because changing size
		setPositionText(textMode[select], 150 + select * 70);

		select++;
		textMode[select].setFillColor(sf::Color::White);
		textMode[select].setCharacterSize(60);

		// update position because changing size
		setPositionText(textMode[select], 150 + select * 70);
	}
}

void levelChoice::mouseMoved(sf::RenderWindow& windows) // di chuyển chuột
{
	/*  khi di chuyển chuột đên một dòng chữ nào đó
		dòng chữ đó sẽ đổi sang màu trắng và size lớn hơn bình thường
		các dòng chữ còn lại màu đỏ và size bình thường
		cập nhật là select
	*/
	if (clickMouse(textMode[0], windows))
	{
		select = 0;

		textMode[0].setFillColor(sf::Color::White);
		textMode[1].setFillColor(sf::Color::Yellow);
		textMode[2].setFillColor(sf::Color::Yellow);
		textMode[3].setFillColor(sf::Color::Yellow);
		textMode[4].setFillColor(sf::Color::Yellow);
		textMode[5].setFillColor(sf::Color::Yellow);

		textMode[0].setCharacterSize(60);
		textMode[1].setCharacterSize(40);
		textMode[2].setCharacterSize(40);
		textMode[3].setCharacterSize(40);
		textMode[4].setCharacterSize(40);
		textMode[5].setCharacterSize(40);
	
		// update position because changing size
		setPositionText(textMode[0], 150);
		setPositionText(textMode[1], 220);
		setPositionText(textMode[2], 290);
		setPositionText(textMode[3], 360);
		setPositionText(textMode[4], 430);
		setPositionText(textMode[5], 500);
		
	}

	if (clickMouse(textMode[1], windows))
	{
		select = 1;

		textMode[0].setFillColor(sf::Color::Yellow);
		textMode[1].setFillColor(sf::Color::White);
		textMode[2].setFillColor(sf::Color::Yellow);
		textMode[3].setFillColor(sf::Color::Yellow);
		textMode[4].setFillColor(sf::Color::Yellow);
		textMode[5].setFillColor(sf::Color::Yellow);

		textMode[0].setCharacterSize(40);
		textMode[1].setCharacterSize(60);
		textMode[2].setCharacterSize(40);
		textMode[3].setCharacterSize(40);
		textMode[4].setCharacterSize(40);
		textMode[5].setCharacterSize(40);

		// update position because changing size
		setPositionText(textMode[0], 150);
		setPositionText(textMode[1], 220);
		setPositionText(textMode[2], 290);
		setPositionText(textMode[3], 360);
		setPositionText(textMode[4], 430);
		setPositionText(textMode[5], 500);
	}

	if (clickMouse(textMode[2], windows))
	{
		select = 2;

		textMode[0].setFillColor(sf::Color::Yellow);
		textMode[1].setFillColor(sf::Color::Yellow);
		textMode[2].setFillColor(sf::Color::White);
		textMode[3].setFillColor(sf::Color::Yellow);
		textMode[4].setFillColor(sf::Color::Yellow);
		textMode[5].setFillColor(sf::Color::Yellow);

		textMode[0].setCharacterSize(40);
		textMode[1].setCharacterSize(40);
		textMode[2].setCharacterSize(60);
		textMode[3].setCharacterSize(40);
		textMode[4].setCharacterSize(40);
		textMode[5].setCharacterSize(40);

		// update position because changing size
		setPositionText(textMode[0], 150);
		setPositionText(textMode[1], 220);
		setPositionText(textMode[2], 290);
		setPositionText(textMode[3], 360);
		setPositionText(textMode[4], 430);
		setPositionText(textMode[5], 500);
	}
	if (clickMouse(textMode[3], windows))
	{
		select = 3;

		textMode[0].setFillColor(sf::Color::Yellow);
		textMode[1].setFillColor(sf::Color::Yellow);
		textMode[2].setFillColor(sf::Color::Yellow);
		textMode[3].setFillColor(sf::Color::White);
		textMode[4].setFillColor(sf::Color::Yellow);
		textMode[5].setFillColor(sf::Color::Yellow);

		textMode[0].setCharacterSize(40);
		textMode[1].setCharacterSize(40);
		textMode[2].setCharacterSize(40);
		textMode[3].setCharacterSize(60);
		textMode[4].setCharacterSize(40);
		textMode[5].setCharacterSize(40);

		// update position because changing size
		setPositionText(textMode[0], 150);
		setPositionText(textMode[1], 220);
		setPositionText(textMode[2], 290);
		setPositionText(textMode[3], 360);
		setPositionText(textMode[4], 430);
		setPositionText(textMode[5], 500);
	}
	if (clickMouse(textMode[4], windows))
	{
		select = 4;

		textMode[0].setFillColor(sf::Color::Yellow);
		textMode[1].setFillColor(sf::Color::Yellow);
		textMode[2].setFillColor(sf::Color::Yellow);
		textMode[3].setFillColor(sf::Color::Yellow);
		textMode[4].setFillColor(sf::Color::White);
		textMode[5].setFillColor(sf::Color::Yellow);

		textMode[0].setCharacterSize(40);
		textMode[1].setCharacterSize(40);
		textMode[2].setCharacterSize(40);
		textMode[3].setCharacterSize(40);
		textMode[4].setCharacterSize(60);
		textMode[5].setCharacterSize(40);

		// update position because changing size
		setPositionText(textMode[0], 150);
		setPositionText(textMode[1], 220);
		setPositionText(textMode[2], 290);
		setPositionText(textMode[3], 360);
		setPositionText(textMode[4], 430);
		setPositionText(textMode[5], 500);
	}
	if (clickMouse(textMode[5], windows))
	{
		select = 5;

		textMode[0].setFillColor(sf::Color::Yellow);
		textMode[1].setFillColor(sf::Color::Yellow);
		textMode[2].setFillColor(sf::Color::Yellow);
		textMode[3].setFillColor(sf::Color::Yellow);
		textMode[4].setFillColor(sf::Color::Yellow);
		textMode[5].setFillColor(sf::Color::White);

		textMode[0].setCharacterSize(40);
		textMode[1].setCharacterSize(40);
		textMode[2].setCharacterSize(40);
		textMode[3].setCharacterSize(40);
		textMode[4].setCharacterSize(40);
		textMode[5].setCharacterSize(60);

		// update position because changing size
		setPositionText(textMode[0], 150);
		setPositionText(textMode[1], 220);
		setPositionText(textMode[2], 290);
		setPositionText(textMode[3], 360);
		setPositionText(textMode[4], 430);
		setPositionText(textMode[5], 500);
	}
}

void levelChoice::mouseSelect(sf::RenderWindow& window) // bắt sự kiện click chuột
{
	if (clickMouse(textMode[0], window))
	{
		if (select == 2 || select == 5)
		{
			SpecialLevel SStage(select + 1);
			SStage.runGame(window);

		}
		else
			play(window, select + 1); // chạy chế độ player
	}
	if (clickMouse(textMode[1], window))
	{
		if (select == 2 || select == 5)
		{
			TextShow textshow(std::string("Level only with player"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
			textshow.scale(0.9);
			textshow.setPosition(810, 300);
			textshow.setColor(151, 255, 255);
			textshow.drawText(window);
			window.display();
			sf::sleep(sf::seconds(3));
		}
		else
			CPlay(window, select + 1); // chạy chế độ tự động
	}
}

void levelChoice::runLevelChoice(sf::RenderWindow& window, int choice)
{
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				mouseMoved(window); // di chuyển chuột
				break;
			case sf::Event::MouseButtonPressed:
			{
				mouseSelect(window); // click chuột
				break;
			}

			case sf::Event::KeyPressed:

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					moveUp(); // di chuyển lên
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					moveDown(); // di chuyển xuống
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					return;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
					switch (choice)
					{
					case 0:
					{
						if (select == 2 || select == 5)
						{
							SpecialLevel SStage(select + 1);
							SStage.runGame(window);

						}
						else
							play(window, select + 1); //  chạy player

						break;
					}	
					case 1:
					{
						if (select == 2 || select == 5)
						{
							TextShow textshow(std::string("Level only with player"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
							textshow.scale(0.9);
							textshow.setPosition(810, 300);
							textshow.setColor(151, 255, 255);
							textshow.drawText(window);
							window.display();
							sf::sleep(sf::seconds(3));
						}
						else
							CPlay(window, select + 1); //  chạy player

						break;
					}
					}
					break;
			default:
				break;
				}
			}
		}
		window.clear();
		drawMenu(window);
		window.display();
	}
}

int levelChoice::GetPressedItem() // lấy giá trị select
{
	return select;
}
