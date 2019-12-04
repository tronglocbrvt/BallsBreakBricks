
#include <iostream>
#include "PvsP.hpp"
#include "BackGround.hpp"
#include "Display.hpp"
#include "Menu.h"
int main(){
    
    
	
    sf::RenderWindow window(sf::VideoMode(_WIDTH_SCREEN, _HEIGH_SCREEN), "Balls Break Bricks", sf::Style::Close);

	/*Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;

                default:
                    break;
            }
        }
		window.clear();
		menu.drawMenu(window);
		window.display();

    }  */

    play(window);
    
    return 0;
}
