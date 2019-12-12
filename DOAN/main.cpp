#include <iostream>
#include "PvsP.hpp"
#include "ComputerPlay.hpp"
#include "BackGround.hpp"
#include "Display.hpp"
#include "Menu.hpp"
#include "SpecialLevel.hpp"

int main(int argc, const char* argv[]) {

	sf::RenderWindow window(sf::VideoMode(_WIDTH_SCREEN, _HEIGH_SCREEN), _NAME_GAME_, sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(FRAME);
	window.setKeyRepeatEnabled(true);

//    play(window, 1);
//    CPlay(window, 1);
    
    SpecialLevel SStage(1);
    SStage.runGame(window);

//	Menu menu(window.getSize().x, window.getSize().y);
//	helpMenu help(window.getSize().x, window.getSize().y);
//	modeGame mode(window.getSize().x, window.getSize().y);
//	listHighScore high(window.getSize().x, window.getSize().y);
//
//	//    play(window, 1);
//	   // play(window, 1);
//
//
//	while (window.isOpen()) {
//
//		sf::Event event;
//
//		while (window.pollEvent(event)) {
//			switch (event.type) {
//
//			case sf::Event::Closed:
//				window.close();
//				break;
//			case sf::Event::MouseMoved:
//				menu.mouseMoved(window);
//				break;
//			case sf::Event::MouseButtonPressed:
//			{
//				menu.mouseSelect(window);
//				break;
//			}
//
//			case sf::Event::KeyPressed:
//
//				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//					menu.moveUp();
//				}
//				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//					menu.moveDown();
//				}
//				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
//					switch (menu.GetPressedItem())
//					{
//					case 0:
//						mode.runModeGame(window);
//						break;
//					case 1:
//					{
//						continueGame cont;
//						cont.runContinueGame(window);
//						break;
//					}
//					case 2:
//						high.drawMenu(window);
//						break;
//					case 3:
//						help.drawMenu(window);
//						break;
//					case 4:
//						window.close();
//						break;
//					}
//					break;
//			default:
//				break;
//				}
//			}
//		}
//		window.clear();
//		menu.drawMenu(window);
//		window.display();
//
//	}
	return 0;
}
