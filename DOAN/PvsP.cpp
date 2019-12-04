#include "PvsP.hpp"

int play(sf::RenderWindow& window) {

    // khởi tạo sân, bóng, 2 thanh
	BackGround bg(1);
	ThePong ball;
	rewardItem test;
	test.zoomBall(ball);
    TheBar bar;
    buildStage stage(1);
    
//    const int number = 17;
//    const float dis = 1;
//    const float width = _WIDTH_TABLE_GAME_ * 1.0 / number - dis;
//    const float rateHei = _GOLDEN_RATIO_;
//    sf::RectangleShape square[number][number];
//	for (int i = 0; i < number; i++)
//	{
//		for (int j = 0; j < number; j++) {
//			square[i][j].setSize(sf::Vector2f(width, width / rateHei));
//			square[i][j].setPosition(_DIS_FROM_LEFT_ + i * (width + dis), _DIS_FROM_TOP_ + j * (width / rateHei + dis));
//			std::cout << (_DIS_FROM_LEFT_ + i * (width + dis)) << " = " << (_DIS_FROM_LEFT_ + i * (width)+width) << std::endl;
//		}
//
//	}
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
        stage.draw(window);
        
//        for (int i = 0; i < number; i++)
//			for (int j = 0; j < number; j++) {
//
//                if ((((i + 1)*(j + 1) + 1) / 3) % 2) {
//                    window.draw(square[i][j]);
//                }
//
//        }

		window.display();
	}
	return 0;
}

