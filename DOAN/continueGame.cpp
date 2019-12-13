#include "continueGame.hpp"

continueGame::continueGame()
{
	std::ifstream fi;

	fi.open("res/file/saveGame.txt");

	if (fi.fail())
	{
		std::cout << "Read file failed\n";
		return;
	}

	fi.seekg(0, std::ios::end); // di chuyển con trỏ từ đầu file đến cuối file
	if (fi.tellg() == 0) // nếu số lượng đọc được là 0
	{
		ballPosX = -1; // set lại hoành độ bóng < 0
		return; // empty file 
	}

	fi.seekg(0); // di chuyển con trỏ về đầu file


	// đọc các thông số về bóng
	fi >> ballPosX;
	fi >> ballPosY;
	fi >> ballVelocX;
	fi >> ballVelocY;

	// đọc thông số về thanh
	fi >> barPosX;
	fi >> barPosY;

	// đọc thông số về điểm
	fi >> score;

	// đọc chế độ chơi
	fi >> mode;
	fi >> level;

	float temp;

	// đọc timelimit
	fi >> stage.timeLimit;

	// đọc time
	fi >> temp;
	stage.setTime(temp);

	for (int i = 0; i < _NUMBER_OF_BRICKS_PER_LINE_; i++) {
		for (int j = 0; j < _NUMBER_OF_BRICKS_PER_LINE_; j++) {
			fi >> stage.mSignBricks[i][j];
		}
	}
	fi.close();

	for (int i = 0; i < _NUMBER_OF_BRICKS_PER_LINE_; i++) {
		for (int j = 0; j < _NUMBER_OF_BRICKS_PER_LINE_; j++) {
			switch (stage.mSignBricks[i][j]) {
			case 1: // brick
			case 2:
			case 3:
				stage.mStage[i][j] = new NormalBrick(stage.mSignBricks[i][j]);
				stage.availableBricks++;
				break;
			case -1:    // rock
				stage.mStage[i][j] = new RockBrick();
				break;
			case 9:
				stage.mStage[i][j] = new SpecBricks();
				break;
			default:
				continue;
				break;
			}

			stage.mStage[i][j]->set(_DIS_FROM_LEFT_ + j * (_WIDTH_BRICK_ + _DIS_BETWEEN_BRICKS_), _DIS_FROM_TOP_ + i * (_WIDTH_BRICK_ / _GOLDEN_RATIO_ + _DIS_BETWEEN_BRICKS_), _WIDTH_BRICK_, _WIDTH_BRICK_ / _GOLDEN_RATIO_, stage.mSignBricks[i][j]);

		}
	}
}

continueGame::~continueGame()
{

}

int continueGame::runContinueGame(sf::RenderWindow& window)
{

	if (ballPosX == -1) // file rỗng
		return 0;

	// thiết lập game với các thông số đã đọc từ file
	ThePong ball(ballPosX, ballPosY, ballVelocX, ballVelocY);
	BackGround bg(mode);
	TheBar bar(true, barPosX, barPosY, score);
	bool speepup = true;

	// khởi động chuỗi thông báo và tên
	TextShow textshow(std::string("Press P to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
	textshow.scale(0.8);
	textshow.setOriginToMidle();
	textshow.setColor(4, 74, 194);

	bool cont = true;

	////start ball when press space
	//while (window.isOpen() && cont) {
	//	sf::Event event;

	//	while (window.pollEvent(event) && cont) {
	//		switch (event.type) {
	//		case sf::Event::KeyPressed:
	//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	//			{
	//				cont = false;
	//			}
	//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	//			{
	//				saveGame(ball, bar, mode, stage);
	//				return 0;
	//			}
	//			break;
	//		case sf::Event::Closed:
	//			saveGame(ball, bar, mode, stage);
	//			window.close();
	//			break;
	//		default:
	//			continue;
	//		}
	//	}

	//	bg.setScore(score);

	//	// in ra màn hình game
	//	window.clear();

	//	bg.draw(window);
	//	bar.draw(window);
	//	ball.draw(window);
	//	stage.draw(window);

	//	window.display();

	if (!pauseGame(window, ball, bg, bar, stage, textshow, sf::Keyboard::P, mode, level)) {
		return 0;
	}

	// start game

	stage.startClock();

	while (window.isOpen()) {
		sf::Event event;

		// bắt sự kiện
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				saveGame(ball, bar, mode, stage, level);
				window.close();
			}
			else if (sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					saveGame(ball, bar, mode, stage, level);
					return 0;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
				{

					TextShow textshow(std::string("Press P to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
					textshow.scale(0.8);
					textshow.setOriginToMidle();
					textshow.setColor(4, 74, 194);

					pauseGame(window, ball, bg, bar, stage, textshow, sf::Keyboard::P, mode, level);
				}
			}
		}
		if (mode == 1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				bar.moveBar(window, true, false);
				bar.draw(window);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				bar.moveBar(window, false, true);
				bar.draw(window);
			}
		}
		else if (mode == 0)
		{
			if (ball.checkGoDown()) {
				sf::Vector2f futurePos = ball.posAtBotInFuture();

				if (speepup) {
					float rateDis = ((ball.distanceToPointFromCenter(futurePos) / ball.lengthOfVector()) / abs(bar.disToBar(futurePos) / bar.getSpeed()));
					if (0 < rateDis && rateDis < 1) {
						bar.speedUp(rateDis);
					}
				}

				if (bar.getPosMidXOfPaddle() < futurePos.x) {
					bar.moveBar(window, false, true);
				}
				else if (bar.getPosMidXOfPaddle() > futurePos.x)
				{
					bar.moveBar(window, true, false);
				}
				speepup = false;
			}
			else
			{
				speepup = true;

				bar.moveToMidTabGame();
			}
		}
		float timeEnd = 1000;
		int checkGift = 0;
		short staticOfBall = ball.moveBall(copyPos(bar.getPosX(), bar.getPosY(), bar.getWidth(), bar.getHeigh()), stage, score, timeEnd, checkGift, bar, window);		stage.updateTime();

		if (staticOfBall == 1) {    // crashed into bottom line
			if (!pauseGame(window, ball, bg, bar, stage, textshow, sf::Keyboard::Space, mode, level)) {  // esc game
				return 0;
			}
			else {
				if (1) {        // hết mạng để chơi
					return EndGame(window, stage, bar.getScores(), level, (stage.getAvailableBricks() == 0));
				}
			}
		}
		if (stage.getAvailableBricks() == 0) {
			EndGame(window, stage, bar.getScores(), level, true);
		}

		bar.setScores(score);
		bg.setScore(score);

		// in ra màn hình game
		window.clear();

		bg.draw(window);
		bar.draw(window);
		ball.draw(window);
		stage.draw(window);

		window.display();
	}
	return 0;
}


