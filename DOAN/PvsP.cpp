#include "PvsP.hpp"


bool pauseGame(sf::RenderWindow& window, ThePong &ball, BackGround &bg, TheBar &bar, buildStage &stage, TextShow &text, sf::Keyboard::Key key, bool mode, int level){
    bool cont = true;
    // start ball when press space
    while (window.isOpen() && cont) {
        sf::Event event;
        // bắt sự kiện
        
        while (window.pollEvent(event) && cont) {
            switch (event.type) {
            case sf::Event::KeyPressed:         // sự kiện nhấn phím
                if (sf::Keyboard::isKeyPressed(key))
                {
                    cont = false;
                    //if (key == sf::Keyboard::Space) {
                    //    ball.resetPong(0);
                    //}
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
					saveGame(ball, bar, mode, stage, level);
                    return false;
                }
                break;
            case sf::Event::Closed: // sự kiện đóng cửa sổ
				saveGame(ball, bar, mode, stage, level);
                window.close();
                break;
            default:
                continue;
            }
        }
        
        // in ra màn hình game
        window.clear();
        
        bg.draw(window);
        bar.draw(window);
        ball.draw(window);
        stage.draw(window);
        text.drawText(window);
        
        window.display();
    }
    return true;
}

int play(sf::RenderWindow& window, int levelCur) {

    // khởi tạo sân, bóng, thanh
	BackGround bg(0);
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

    buildStage stage(levelCur);
    float score = 0;

    // khởi động chuỗi thông báo và tên
	TextShow textshow(std::string("Press Space to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
    textshow.scale(0.8);
    textshow.setOriginToMidle();
    textshow.setColor(4, 74, 194);

//    EndGame(window, stage, bar.getScores());
    
    if (!pauseGame(window, ball, bg, bar, stage, textshow, sf::Keyboard::Space, 1, levelCur)) {
        return 0;
    }
	// start game
    
    stage.startClock();
	while (window.isOpen()) {
		sf::Event event;
        
        // bắt sự kiện
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				saveGame(ball, bar, 1, stage, levelCur);
				window.close();
			}
			else if (sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					saveGame(ball, bar, 1, stage, levelCur);
					return 0;
				}
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                {
                    
                    TextShow textshow(std::string("Press P to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
                    textshow.scale(0.8);
                    textshow.setOriginToMidle();
                    textshow.setColor(4, 74, 194);
                    
					pauseGame(window, ball, bg, bar, stage, textshow, sf::Keyboard::P, 1, levelCur);
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
//			auto p = std::async(&ThePong::moveBall, &Balls[i], std::ref(posBar), std::ref(stage));
//			auto p1 = std::async(&ThePong::moveBall, &Balls[i], std::ref(posBar), std::ref(stage));
//			m = p.get();
//			n = p1.get();
//			if ((m == -1 || n == -1) && (Balls.size() > 1)) // chết bóng và số bóng > 1 ->xóa bóng
//			{
//				Balls.erase(Balls.begin() + i);
//			}
//		}
		/*std::thread thread1(&ThePong::moveBall, &ball, std::ref(posBar), std::ref(stage));
		std::thread thread2(&ThePong::moveBall, &ball1, std::ref(posBar), std::ref(stage));*/
        short staticOfBall = ball.moveBall(copyPos(bar.getPosX(), bar.getPosY(), bar.getWidth(), bar.getHeigh()), stage, score);
        stage.updateTime();
        
        if (staticOfBall == 1) {    // crashed into bottom line
            if (!pauseGame(window, ball, bg, bar, stage, textshow, sf::Keyboard::Space, 1, levelCur)) {  // esc game
                return 0;
            }
            else {
                if (1) {        // hết mạng để chơi
                    // do something
                    return EndGame(window, stage, bar.getScores(), levelCur, (stage.getAvailableBricks() == 0));
                }
            }
        }
        if (stage.getAvailableBricks() == 0) {
            EndGame(window, stage, bar.getScores(), levelCur, true);
        }
        
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

void saveGame(ThePong ball, TheBar bar, bool mode, buildStage stage, int level)
{
	std::ofstream fo;

	fo.open("res/file/saveGame.txt");
	if (fo.fail())
	{
		std::cout << "Open file failed\n";
		return;
	}

	fo << ball.getPosX() << " ";
	fo << ball.getPosY() << " ";
	fo << ball.getVelocityX() << " ";
	fo << ball.getVelocityY() << " ";

	fo << bar.getPosX() << " ";
	fo << bar.getPosY() << " ";

	fo << bar.getScores() << " ";

	fo << mode << " "; // lưu chế độ chơi, 0 = PvsC, 1 = PvsP

	fo << level << " ";
	fo << stage.getTimeLimit() << " ";
	fo << stage.getTimePlaying() << std::endl;

	for (int i = 0; i < _NUMBER_OF_BRICKS_PER_LINE_; i++) {
		for (int j = 0; j < _NUMBER_OF_BRICKS_PER_LINE_; j++) {
			fo <<  stage.getmSignBricks(i, j) << " ";
		}
		fo << std::endl;
	}

	fo.close();
}

void fileEmpty() // làm cho file rỗng
{
	std::ofstream fo;

	fo.open("res/file/saveGame.txt");
	if (fo.fail())
	{
		std::cout << "Open file failed\n";
		return;
	}

	fo.close();
}

int EndGame(sf::RenderWindow& window, buildStage &stage, float score, int level, bool isWinner){
    
	fileEmpty();
    sf::Texture imgTx;
    imgTx.loadFromFile("res/img/endgame.png");
    sf::Sprite imgSpr;
    imgSpr.setTexture(imgTx);
    imgSpr.scale(_WIDTH_SCREEN * 1.0 / imgTx.getSize().x, _HEIGH_SCREEN * 1.0 / imgTx.getSize().y);
    
    window.clear();
    
    const float sizeText = 0.06 * _HEIGH_SCREEN; // 6%
    const float disToBelowText = sizeText * 0.5;
    
    TextShow tScore(std::string("Score:           ") + std::to_string(int(score)), std::string("HACKED.ttf"), _WIDTH_SCREEN / 2 - 5 * sizeText, (_HEIGH_SCREEN - 4 * (sizeText + disToBelowText)) / 2);
    tScore.setSize(sizeText);
    tScore.setOriginToTopHead();
    tScore.setColor(148, 235, 19);
    
    float time;
    
    time = stage.getTimePlaying();
    TextShow tTimePlay(std::string("Time Playing: ") + std::to_string(int(time / 60)) + std::string("' ") + std::string(std::to_string(time - int(time / 60) * 60)).substr(0,4) + std::string("''"), std::string("HACKED.ttf"), _WIDTH_SCREEN / 2 - 5 * sizeText, tScore.getBottom() + disToBelowText);
    tTimePlay.setSize(sizeText);
    tTimePlay.setOriginToTopHead();
    tTimePlay.setColor(148, 235, 19);
    
    time = stage.getTimeLimit();
    TextShow tTimeLimit(std::string("Time Limited:   ") + std::to_string(int(time / 60)) + std::string("' ") + std::string(std::to_string(time - int(time / 60) * 60)).substr(0,4) + std::string("''"), std::string("HACKED.ttf"), _WIDTH_SCREEN / 2 - 5 * sizeText, tTimePlay.getBottom() + disToBelowText);
    tTimeLimit.setSize(sizeText);
    tTimeLimit.setOriginToTopHead();
    tTimeLimit.setColor(148, 235, 19);
    
    int total;
    if (isWinner) {
        total =  int(score *(1 + (stage.getTimeLimit() - stage.getTimePlaying()) / (stage.getTimeLimit()) ));
    }
    else
    {
        total = int(score);
    }
    
    TextShow tScoreAtEnd(std::string("Total Score:  ") + std::string(std::to_string(total)), std::string("HACKED.ttf"), _WIDTH_SCREEN / 2 - 5 * sizeText, tTimeLimit.getBottom() + disToBelowText);
    tScoreAtEnd.setSize(sizeText);
    tScoreAtEnd.setOriginToTopHead();
    tScoreAtEnd.setColor(148, 235, 19);
    
    
//	listHighScore HighScore(window.getSize().x, window.getSize().y);
//	highScore scoreNew(score, level);
//	HighScore.compareScore(scoreNew);

    while (window.isOpen()) {
        sf::Event event;
        // bắt sự kiện
        
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyPressed:         // sự kiện nhấn phím
				return 0;
			case sf::Event::Closed:             // sự kiện đóng cửa sổ
                window.close();
                break;
            default:
                continue;
            }
        }
        
        // in ra màn hình game
        window.clear();
        
        window.draw(imgSpr);
        tScore.drawText(window);
        tTimePlay.drawText(window);
        tTimeLimit.drawText(window);
        tScoreAtEnd.drawText(window);
        
        window.display();
    }
    
    return 0;
}
