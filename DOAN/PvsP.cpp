#include "PvsP.hpp"

int play(sf::RenderWindow& window) {

    // khởi tạo sân, bóng, 2 thanh
	BackGround bg(1);
	ThePong ball;
//    ball.setPosX(225);
//    ball.setPosY(150);
//	std::vector<ThePong> Balls;
//	ThePong ball1, ball2;
	//ThePong ball2(200, 400, _VELOCITY_X_, _VELOCITY_Y_);
//	Balls.push_back(ball1);
//	Balls.push_back(ball2);

//	BallsHandler balls;
//	balls.newBall();
//	balls.newBall();
//
//	balls.getBalls().at(0).setPosX(200);
//	balls.getBalls().at(1).setPosY(400);
    TheBar bar;

	rewardItem test;
	//test.widenBar(bar);

    buildStage stage(1);
    int score = 0;

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

//		std::thread thread1(&BallsHandler::moveBalls, &balls, std::ref(window), std::ref(bar), std::ref(stage), 0);
//		std::thread thread2(&BallsHandler::moveBalls, &balls, std::ref(window), std::ref(bar), std::ref(stage), 1);

//		Pos posBar = copyPos(bar.getPosX(), bar.getPosY(), bar.getWidth(), bar.getHeigh());

//		int m, n;
//		for (int i = 0; i < Balls.size(); i++)
//		{
//			auto p = std::async(&ThePong::moveBall, &Balls[i], std::ref(posBar), std::ref(stage), std::ref(bar));
//			auto p1 = std::async(&ThePong::moveBall, &Balls[i], std::ref(posBar), std::ref(stage), std::ref(bar));
//			m = p.get();
//			n = p1.get();
//			if ((m == -1 || n == -1) && (Balls.size() > 1)) // chết bóng và số bóng > 1 ->xóa bóng
//			{
//				Balls.erase(Balls.begin() + i);
//			}
//		}
		/*std::thread thread1(&ThePong::moveBall, &ball, std::ref(posBar), std::ref(stage));
		std::thread thread2(&ThePong::moveBall, &ball1, std::ref(posBar), std::ref(stage));*/
        ball.moveBall(copyPos(bar.getPosX(), bar.getPosY(), bar.getWidth(), bar.getHeigh()), stage, score);
        
        
        bar.setScores(score);
        bg.setScore(score);
        
        // in ra màn hình game
		window.clear();
        
		bg.draw(window);
        bar.draw(window);
//		balls.drawBalls(window);
		ball.draw(window);
		
//		for (int i = 0; i < Balls.size(); i++)
//		{
//			Balls[i].draw(window);
//		}

        stage.draw(window);
        
		/*if (thread1.joinable())
			thread1.join();

		if (thread2.joinable())
			thread2.join();*/

		window.display();
	}
	return 0;
}

