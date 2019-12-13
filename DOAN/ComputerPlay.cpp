#include "ComputerPlay.hpp"


int CPlay(sf::RenderWindow& window, int levelCur)   // máy
{
    // khởi tạo sân, bóng, 2 thanh
    BackGround bg(1);
    ThePong ball;
    TheBar bar;

    buildStage stage(levelCur);
    float score = 0;
    bool speepup = true;
    
    sf::Vertex lineAlp1[2];
    sf::Vertex lineAlp2[2];

    // khởi động chuỗi thông báo và tên
    TextShow textshow(std::string("Press Space to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
    textshow.scale(0.8);
    textshow.setOriginToMidle();
    textshow.setColor(4, 74, 194);

//    EndGame(window, stage, bar.getScores());
    
    if (!pauseGame(window, ball, bg, bar, stage, textshow, sf::Keyboard::Space, 0, levelCur)) {
        return 0;
    }
    // start game
    
    stage.startClock();
    while (window.isOpen()) {
        sf::Event event;
        
        // bắt sự kiện
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
				saveGame(ball, bar, 0, stage, levelCur);
                window.close();
            }
            else if (sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					saveGame(ball, bar, 0, stage, levelCur);
                    return 0;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                {
                    
                    TextShow textshow(std::string("Press P to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
                    textshow.scale(0.8);
                    textshow.setOriginToMidle();
                    textshow.setColor(4, 74, 194);
                    
                    pauseGame(window, ball, bg, bar, stage, textshow, sf::Keyboard::P, 0, levelCur);
                }
            }
        }
        
        if (ball.checkGoDown()) {
            sf::Vector2f futurePos = ball.posAtBotInFuture();

            // tăng tốc nếu cần
            if (speepup) {
                float rateDis = ((ball.distanceToPointFromCenter(futurePos)/ball.lengthOfVector()) / abs(bar.disToBar(futurePos)/bar.getSpeed()));
                if (0 < rateDis && rateDis < 1) {
                    bar.speedUp(rateDis);
                }
            }

            // test
            sf::Vector2f nearest = stage.nearestBrickToPoint(futurePos, ball.checkGoLeft());
            sf::Vector2f reflex = ball.getReflexInfut(nearest.y, futurePos);
            
            lineAlp1[0] = sf::Vertex(futurePos, sf::Color::Black);
            lineAlp1[1] = sf::Vertex(nearest, sf::Color::Black);

            lineAlp2[0] = sf::Vertex(futurePos, sf::Color::Blue);
            lineAlp2[1] = sf::Vertex(reflex, sf::Color::Blue);
            
            float rateOfChange = abs(nearest.x - (bar.getPosMidXOfPaddle())) / abs(reflex.x - (bar.getPosMidXOfPaddle()));
            
            if (rateOfChange > 2) {
                rateOfChange = 2;
            }
            
            if (futurePos.x < (_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_/2)) {
                bar.setCatchPoint(sf::Vector2f(bar.getPosMidXOfPaddle() - bar.getLongBar()/4 * rateOfChange, bar.getPosY()));
            }
            else
            {
                bar.setCatchPoint(sf::Vector2f(bar.getPosMidXOfPaddle() + bar.getLongBar()/4 * rateOfChange, bar.getPosY()));
            }
            
            
            // di chuyển thanh tới đón bóng
            if (bar.getCatchPoint().x < futurePos.x) {
                bar.moveBar(window, false, true);
            }
            else if (bar.getCatchPoint().x > futurePos.x)
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
        
		static float timeEnd = 1000;
		static int checkGift = 0;
		short staticOfBall = ball.moveBall(copyPos(bar.getPosX(), bar.getPosY(), bar.getWidth(), bar.getHeigh()), stage, score, timeEnd, checkGift, bar, bg);        
		stage.updateTime();
        
        if (staticOfBall == 1) {    // crashed into bottom line
            if (!pauseGame(window, ball, bg, bar, stage, textshow, sf::Keyboard::Space, 0, levelCur)) {  // esc game
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
            return EndGame(window, stage, bar.getScores(), levelCur, true);
        }
        
        bar.setScores(score);
        bg.setScore(score);
        
        // in ra màn hình game
        window.clear();
        
        bg.draw(window);
        bar.draw(window);
        ball.draw(window);
        stage.draw(window);
        
        window.draw(lineAlp1, 2, sf::Lines);
        window.draw(lineAlp2, 2, sf::Lines);

        window.display();
    }
    return 0;
}
