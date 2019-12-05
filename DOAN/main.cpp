#include <iostream>
#include "PvsP.hpp"
#include "BackGround.hpp"
#include "Display.hpp"
#include "Menu.h"
int main(){
    
    /*
    hideCursor();    //ẩn con trỏ nhấp nháy
    OMG omg(right, bottom);    //khởi tạo game với biên phải và dưới
    int choice;    //biến lựa chọn
    omg.printMenu(choice);    //in ra menu lựa chọn
    
    //vòng lặp chơi game khi chưa chọn quit (choice != 3)
    do
    {
        omg.run(choice); // chơi game
        omg.reset();    //reset game
        omg.printMenu(choice);    //in menu
    } while (choice != 3);
     */
	
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
