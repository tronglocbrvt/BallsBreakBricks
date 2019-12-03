#include "PvsP.hpp"

int play(sf::RenderWindow& window) {

    // khởi tạo sân, bóng, 2 thanh
	BackGround bg(1);

    // khởi động chuỗi thông báo và tên
	TextShow textshow(std::string("Press Space to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + 50, _HEIGH_TABLE_GAME_ - 2 * _DIS_FROM_TOP_);


	// start game
	while (window.isOpen()) {
		sf::Event event;
        // bắt sự kiện
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					return 0;
				}
			}
		}
        
        // sự kiện nhấn di chuyển thanh
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//			barA.moveBar(window, true, false);
//			barA.draw(window);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//			barA.moveBar(window, false, true);
//			barA.draw(window);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//			barB.moveBar(window, true, false);
//			barB.draw(window);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//			barB.moveBar(window, false, true);
//			barB.draw(window);
		}
		

        
        // in ra màn hình game
		window.clear();
        
		bg.draw(window);

		window.display();
	}
	return 0;
}

