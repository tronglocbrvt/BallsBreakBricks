#include "PvsP.hpp"

int play(sf::RenderWindow& window) {

    // khởi tạo sân, bóng, 2 thanh
	BackGround bg(1);
    ThePong ball;
    TheBar bar;
    
    const int number = 18;
    const float dis = 1;
    const float width = _WIDTH_TABLE_GAME_ * 1.0 / number - dis;
//    const int width = 21.9;
    sf::RectangleShape square[number];
    for (int i = 0; i < number; i++) {
        square[i].setSize(sf::Vector2f(width, width/3));
        square[i].setPosition(_DIS_FROM_LEFT_ + i * (width + dis), _DIS_FROM_TOP_);
        std::cout << (_DIS_FROM_LEFT_ + i * (width + dis)) << " = " << (_DIS_FROM_LEFT_ + i * (width) + width) << std::endl;
    }

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			bar.moveBar(window, true, false);
			bar.draw(window);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			bar.moveBar(window, false, true);
			bar.draw(window);
		}
		
        ball.moveBall(window, copyPos(bar.getPosX(), bar.getPosY(), bar.getWidth(), bar.getHeigh()));
        
        // in ra màn hình game
		window.clear();
        
		bg.draw(window);
        bar.draw(window);
        ball.draw(window);
        
        for (int i = 0; i < number; i++) {

            window.draw(square[i]);
        }

		window.display();
	}
	return 0;
}

