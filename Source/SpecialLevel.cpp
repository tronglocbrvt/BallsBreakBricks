#include "SpecialLevel.hpp"


SpecialLevel::SpecialLevel(int stage) : bg(2), stage(std::string("SpecialStage") + std::to_string(stage) + std::string(".txt")){
    
    this->bg.setTurn(1);
    this->ball.setPosY(_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - ball.getHeight());
    
//    this->stage = 1;
    this->nameFile = std::string("SpecialStage") + std::to_string(stage) + std::string(".txt");
    this->health = 3;
	this->level = stage;

    this->wayOfBall[0] = sf::Vertex(sf::Vector2f(this->ball.middle().x, this->ball.middle().y), sf::Color::Red);
    this->wayOfBall[1] = sf::Vertex(sf::Vector2f(this->ball.middle().x, this->ball.middle().y), sf::Color::Red);
    
    
}
SpecialLevel::~SpecialLevel(){
    
}

void SpecialLevel::loadStage(int stage){
    
}

void SpecialLevel::showLoading(){
    
}
bool SpecialLevel::pauseGame(sf::RenderWindow& window, TextShow &text, sf::Keyboard::Key key){
    
	TheBar bar;
    // start ball when press space
    while (window.isOpen()) {
        sf::Event event;
        // bắt sự kiện
        
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyPressed:         // sự kiện nhấn phím
                if (sf::Keyboard::isKeyPressed(key))
                {
                    return true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
					return false;
                }
                break;
            case sf::Event::Closed: // sự kiện đóng cửa sổ
                window.close();
                break;
            default:
                continue;
            }
        }
        
        // in ra màn hình game
        window.clear();
        
        this->bg.draw(window);
//        bar.draw(window);
        this->ball.draw(window);
        this->stage.draw(window);
        this->gun.draw(window);
        text.drawText(window);
        
        window.display();
    }
    return true;
}

bool SpecialLevel::setLine(sf::Vector2i toward){
    
//    sf::Vector2f from = this->ball.middle();
    
    if (toward.x == 0) {
        return false;
    }
    
    float posiX0 = _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_/2;
    float posiY0 = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_;
    
    sf::Vector2f from = sf::Vector2f(posiX0, posiY0);
    sf::Vector2f to;
    
    float alp = 0;
    float bet = 0;

    if (toward.x == from.x) {
        // x = a
        to.x = from.x;
        to.y = _DIS_FROM_TOP_;
    }
    else
    {
        // y = alp * x + bet
        alp = (toward.y - from.y) / (toward.x - from.x);
        bet = from.y - alp * from.x;

        if (toward.x > from.x) {
            to.x = _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_;
        }
        else
        {
            to.x = _DIS_FROM_LEFT_;
        }

        to.y = alp * to.x + bet;

        if (to.y < _DIS_FROM_TOP_) {
            to.y = _DIS_FROM_TOP_;
            to.x = (to.y - bet) / alp;
        }
        
        if (to.y > _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _MIN_Y_) {
            to.y = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _MIN_Y_;
            to.x = (to.y - bet) / alp;
            if (to.x > _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_) {
                to.x = _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_;
            }
            else if (to.x < _DIS_FROM_LEFT_){
                to.x = _DIS_FROM_LEFT_;
            }
            
            alp = (to.y - from.y) / (to.x - from.x);
            bet = from.y - alp * from.x;
        }
    }

    // xoay ụ súng
    float degree = atan( (from.y - to.y) / (to.x - from.x) ) * 180 / M_PI;
    if (degree < 0) {
        degree = 180 + degree;
    }
    this->gun.rotateGun(degree);
    
    // xoay bóng
    float posiX;
    float posiY;
    if (from.x == to.x) {
        posiX = to.x;
        posiY = -sqrt(sqr(_RADIUS_) - sqr(posiX - (_WIDTH_TABLE_GAME_/2 + _DIS_FROM_LEFT_))) + (_HEIGH_TABLE_GAME_ + _DIS_FROM_TOP_);
        
    }
    else
    {

        float delta = sqr(alp * bet - posiX0 - posiY0 * alp) - (1 + sqr(alp)) * (sqr(bet) - 2 * posiY0 * bet + sqr(posiX0) + sqr(posiY0) - sqr(_RADIUS_));
        
        if (delta < 0) {
            return false;
        }

        if (alp > 0) {
            posiX = ((posiX0 + posiY0 * alp - alp * bet) - sqrt(delta)) / (1 + sqr(alp));
        }
        else
        {
            posiX = ((posiX0 + posiY0 * alp - alp * bet) + sqrt(delta)) / (1 + sqr(alp));
        }

        posiY = alp * posiX + bet;
    }
    
    
    ball.setPosX(posiX - ball.getWidth()/2);
    ball.setPosY(posiY - ball.getHeight()/2);
    
    
    this->wayOfBall[0] = sf::Vertex(sf::Vector2f(from.x, from.y), sf::Color::Red);
    this->wayOfBall[1] = sf::Vertex(sf::Vector2f(to.x, to.y), sf::Color::Red);

    // y = a * x + b;

    // set veloc of ball
    const float velocRate = 1.5;
    float lVec = sqrt(sqr(from.x - to.x) + sqr(from.y - to.y));
    ball.setVelocityXY(_VELOCITY_X_ * velocRate / lVec * (to.x - from.x), _VELOCITY_Y_ * velocRate / lVec * (to.y - from.y));
    
    return true;
    
}
sf::Vector2i SpecialLevel::chooseLineOfFire(sf::RenderWindow& window){
    while (window.isOpen()) {
        sf::Event event;
        // bắt sự kiện

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::MouseButtonPressed:         // sự kiện nhấn chuột
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        this->gun.fire(window, bg, stage, ball);
                        return sf::Mouse::getPosition(window);
                    }
                    break;
                case sf::Event::MouseMoved:
                    this->setLine(sf::Mouse::getPosition(window));
                    break;
                case sf::Event::KeyPressed:
                    return sf::Vector2i();
                    break;
                case sf::Event::Closed:             // sự kiện đóng cửa sổ
                    window.close();
                    break;
                default:
                    continue;
                }
        }

        // in ra màn hình game
        window.clear();

        this->bg.draw(window);
        this->ball.draw(window);
        this->stage.draw(window);
        window.draw(this->wayOfBall, 2, sf::Lines);
        this->gun.draw(window);
        
        window.display();
    }
    return sf::Vector2i();
}

short SpecialLevel::runGame(sf::RenderWindow &window){
    // khởi tạo sân, bóng, 2 thanh
	float timeEnd = 1000;
	int checkGift = 0;
    // khởi động chuỗi thông báo và tên
    TextShow textshow(std::string("Press Space to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
    textshow.scale(0.8);
    textshow.setOriginToMidle();
    textshow.setColor(4, 74, 194);

    float score = 0;

    if (!this->pauseGame(window, textshow, sf::Keyboard::Space)) {
        return 0;
    }
    
    if (!this->setLine(this->chooseLineOfFire(window))) {
        return 0;
    }
    
    
    // start game
    TheBar bar;

    stage.startClock();
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
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
				{

					TextShow textshow(std::string("Press P to continue"), std::string("HACKED.ttf"), _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_, _HEIGH_TABLE_GAME_ * 3 / 4 + _DIS_FROM_TOP_);
					textshow.scale(0.8);
					textshow.setOriginToMidle();
					textshow.setColor(4, 74, 194);

					this->pauseGame(window, textshow, sf::Keyboard::P);
				}
			}

		}

		short staticOfBall = ball.moveBall(copyPos(0,0,0,0), stage, score, timeEnd, checkGift, bar, bg);
        this->stage.updateTime();

        if (staticOfBall == 1) {    // crashed into bottom line
            this->health--;
            if (!this->pauseGame(window, textshow, sf::Keyboard::Space)) {  // esc game
//                return 0;
            }
            else {
                this->bg.setTurn(3 - this->health +1);
                if (this->health == 0) {        // hết mạng để chơi
                    // do something
                    return EndGame(window, this->stage, (this->ball.isGotTreasure() ? 100 : 0), this->level, ball.isGotTreasure(), 0);
                }
                else
                {
                    this->ball.resetPositionToMidBot();
                    if (!this->setLine(this->chooseLineOfFire(window))) {
                        return 0;
                    }
                }
            }
        }
        if (this->ball.isGotTreasure()) {
            return EndGame(window, this->stage, 100, this->level, true, 0);
        }


        // in ra màn hình game
        window.clear();

        this->bg.draw(window);
        this->ball.draw(window);
        this->stage.draw(window);
        this->gun.draw(window);
        
        window.display();
    }
    return 0;
}
