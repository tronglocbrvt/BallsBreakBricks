#include "Ball.hpp"


// the pong class
ThePong::ThePong() {

    this->crashedIntoTreasure = false;
    this->pastTouchOnPaddle = sf::Vector2f(_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_/2, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_);
    
    // load file ảnh và cài đặt thông số cho quả bóng
    if (!this->textureBall.loadFromFile("res/img/pongball.png")) {
        std::cout << "Load file failed" << std::endl;
    }
    
    this->imgSpr.setTexture(this->textureBall);
    this->imgSpr.scale(_SIZE_PONG_ * 1.0 / this->imgSpr.getTexture()->getSize().x, _SIZE_PONG_ * 1.0 / this->imgSpr.getTexture()->getSize().y);

    // cài đặt tốc độ và gia tốc
    this->velocityX = _VELOCITY_X_;
    this->velocityY = _VELOCITY_Y_;
    this->acceleration = _ACCELERATION_;

    // getter vị trí cuối cùng quả bóng
    this->posXend = this->imgSpr.getTexture()->getSize().x * this->imgSpr.getScale().x;
    this->posYend = this->imgSpr.getTexture()->getSize().y * this->imgSpr.getScale().y;

    // khởi động vị trí quả bóng tạo vị trí chính giữa màn hình chơi
    this->resetPong(0);
    
    // điều chỉnh vị trí
    this->imgSpr.setPosition(this->posX, this->posY);
    
}
ThePong::ThePong(float x, float y, float veX, float veY) {
    // set vị trí theo điểm đầu
    this->posX = x;
    this->posY = y;

    // load file ảnh và cài đặt thông số bóng
    if (!this->textureBall.loadFromFile("res/img/pongball.png")) {
        std::cout << "Load file failed" << std::endl;
    }
    this->textureBall.setSmooth(true);
    this->imgSpr.setTexture(this->textureBall);
    this->imgSpr.scale(_SIZE_PONG_ * 1.0 / this->imgSpr.getTexture()->getSize().x, _SIZE_PONG_ * 1.0 / this->imgSpr.getTexture()->getSize().y);

    // cài đặt tốc độ và gia tốc
    this->velocityX = veX;
    this->velocityY = veY;
    this->acceleration = _ACCELERATION_;

    // lấy vị trí cuối cùng
    this->posXend = this->imgSpr.getTexture()->getSize().x * this->imgSpr.getScale().x;
    this->posYend = this->imgSpr.getTexture()->getSize().y * this->imgSpr.getScale().y;

    // chỉnh vị trí theo điểm tâm

	this->imgSpr.setPosition(this->posX - this->posXend * 1.0 / 2, this->posY);
	

}
ThePong::~ThePong() {

}

void ThePong::setter(){
    if (!this->textureBall.loadFromFile("res/img/pongball.png")) {
        std::cout << "Load file failed" << std::endl;
    }
    
    this->imgSpr.setTexture(this->textureBall);
    this->imgSpr.scale(_SIZE_PONG_ * 1.0 / this->imgSpr.getTexture()->getSize().x, _SIZE_PONG_ * 1.0 / this->imgSpr.getTexture()->getSize().y);

    // cài đặt tốc độ và gia tốc
    this->velocityX = _VELOCITY_X_;
    this->velocityY = _VELOCITY_Y_;
    this->acceleration = _ACCELERATION_;

    // getter vị trí cuối cùng quả bóng
    this->posXend = this->imgSpr.getTexture()->getSize().x * this->imgSpr.getScale().x;
    this->posYend = this->imgSpr.getTexture()->getSize().y * this->imgSpr.getScale().y;

    // khởi động vị trí quả bóng tạo vị trí chính giữa màn hình chơi
    this->resetPong(0);
    
    // điều chỉnh vị trí
    this->imgSpr.setPosition(this->posX - this->posXend * 1.0 / 2, this->posY);
}

void ThePong::setPosX(float x) {        // đặt vị trí x
    this->posX = x;
    this->imgSpr.setPosition(this->posX, this->posY);
}

void ThePong::setPosY(float y) {        // đặt vị trí y
    this->posY = y;
    this->imgSpr.setPosition(this->posX, this->posY);
}
void ThePong::setPosXend(float x)
{
	posXend = x;
}
void ThePong::setPosYend(float y)
{
	posYend = y;
}
void ThePong::setVelocityXY(float velocityX, float velocityY){
    this->velocityX = velocityX;
    this->velocityY = velocityY;
}

float ThePong::getHeight(){
    return this->posYend;
}
float ThePong::getWidth(){
    return this->posXend;
}
float ThePong::getPosX() {              // lấy vị trí x
    return this->posX;
}
float ThePong::getPosY() {              // lấy vị trí y
    return this->posY;
}
float ThePong::getVelocityX()           // lấy tốc độ theo x
{
    return velocityX;
}

float ThePong::getVelocityY()           // lấy tốc độ theo y
{
    return velocityY;
}

void ThePong::updateVelocityX() {       // cập nhật tốc độ của x
    this->velocityX *= this->acceleration;
}
void ThePong::updateVelocityY() {       // cập nhật tốc độ của x
    this->velocityY *= this->acceleration;
}
void ThePong::resetPong(short toward) { // đặt lại vị trí ban đầu cho bóng, và đặt hướng đi ngẫu nhiên hay về một hướng
    // đưa bóng về giữa sân
    this->posX = _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_ - this->posXend/2;
    this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - this->posYend - _HEIGH_BAR_;

    // đặt ngẫu nhiên tốc độ bóng
    srand(time(nullptr));
    this->velocityY = -_VELOCITY_Y_ * ((rand() % 100) * 1.0 / 100 + 1) * _HEIGH_TABLE_GAME_ / (_WIDTH_TABLE_GAME_);
    this->velocityX = _VELOCITY_X_ * (((rand() % 100) * 1.0 / 50 - 1) >= 0 ? 1 : -1) * (_VELOCITY_X_ / sqrt(sqr(_VELOCITY_X_) + sqr(this->velocityY)));
//    this->velocityX = 0.005;
    
    // điều hướng bóng
    if (toward != 0) {
        this->velocityX = toward * myMath::absFloat(this->velocityX);
    }

    // reset gia tốc
    this->acceleration = _ACCELERATION_;
}
void ThePong::resetPositionToMidBot(){
    this->posX = _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_;
    this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - this->posYend - _HEIGH_BAR_;
    this->imgSpr.setPosition(this->posX, this->posY);
}

void ThePong::scale(float width, float heigh) {     // thay đổi kích thước bóng kiểu co giãn
    this->imgSpr.scale(width, heigh);
}
short ThePong::moveBall(Pos positionBar, buildStage& stage, float& score, float& timeEnd, int& checkGift, TheBar& bar, BackGround& bg) {
    
//    std::cout << "Veloc: " << this->getVecloc() << std::endl;

	if (timeEnd <= stage.getTimePlaying())
	{
		if (checkGift == 3) // thay đổi size ball
        {
            scale(_SIZE_PONG_ / this->getWidth(), _SIZE_PONG_ / this->getHeight());
            this->posXend = _SIZE_PONG_;
            this->posYend = _SIZE_PONG_;
        }

		else if (checkGift == 4) // thay đổi size bar
        {
            bar.scale(_WIDTH_BAR_ / bar.getLongBar(), _HEIGH_BAR_ / bar.getHeigh());
            bar.setLongBar(_WIDTH_BAR_);
        }

		bg.Giftimage.~Texture();
		bg.Giftsprite.setPosition(0, 0);
		bg.Giftsprite.setRotation(0.1);
		timeEnd = 1000;
		checkGift = 0; // het vat pham

	}
	
	float pastPosX = this->posX;
	float pastPosY = this->posY;

	this->pastBall = this->imgSpr.getGlobalBounds();

	// di chuyển bóng

	// thay đổi vị trí bóng
	posX += velocityX;
	posY += velocityY;
    
    this->adjustIfGoThroughBricks(stage);

	// điều chỉnh bóng vượt biên
	normalizePosX();
	normalizePosY();

	if ((this->posX <= _DIS_FROM_LEFT_) || (this->posX + this->posXend >= _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_)) {

		this->velocityX *= -1;
	}

//    std::cout << this->getVecloc() << std::endl;
	// kiểm tra chạm thanh
    if (this->checkClashToBar(positionBar)) {
//		std::cout << getVelocityX() << " " << getVelocityY() << std::endl;
        this->updateVelocityX();
        this->updateVelocityY();
        
        this->pastTouchOnPaddle = sf::Vector2f(this->posX + this->posXend/2, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_);
        
        this->posX = pastPosX + (this->posX - pastPosX) * (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_ - this->posYend - pastPosY) / (this->posY - pastPosY);
        this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_ - this->posYend;

        // cập nhật vận tốc trên trục nếu có thay đổi
        if ((this->posX > positionBar.x + positionBar.endX) || (this->posX + this->posXend < positionBar.x)) {
            this->velocityX *= -1;
        }
        else{
            this->velocityY *= -1;
            
            // cơ chế làm thay đổi hướng bóng khi chạm thanh
            float lengthVector = this->getVecloc();
            float rateCh = bar.rateOfChange(this->getBoundBall());
            
            if (rateCh < 0.5) {
                this->velocityX *= 0.5;
            }
            else this->velocityX *= rateCh;

            if (abs(this->velocityX) < 0.01) {
                if (this->velocityX >= 0) {
                    this->velocityX = (this->velocityX / lengthVector + 0.005);
                }
                else this->velocityX = -(this->velocityX / lengthVector + 0.005);
            }

            if (abs(this->velocityX) > lengthVector * cos(20 * M_PI / 180)) {
                this->velocityX = lengthVector * cos(20 * M_PI / 180) * (this->velocityX / abs(this->velocityX));

            }
            this->velocityY = -sqrt(sqr(lengthVector) - sqr(this->velocityX));
        }
		updateVelocityX();
		updateVelocityY();
    }

	// kiểm tra chạm gạch

	float middleX = this->posX + posXend / 2;
	float middleY = this->posY + posYend / 2;

	short startX = (int)((middleX - _DIS_FROM_LEFT_) / (_WIDTH_BRICK_ + _DIS_BETWEEN_BRICKS_)) - 1;  // -1 -> 15
	short startY = (int)((middleY - _DIS_FROM_TOP_) / (_WIDTH_BRICK_ / _GOLDEN_RATIO_ + _DIS_BETWEEN_BRICKS_)) - 1;     // -1 -> 16

	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;

	if (startX < _NUMBER_OF_BRICKS_PER_LINE_ && startY < _NUMBER_OF_BRICKS_PER_LINE_) {

		unsigned short toX, toY;
		switch (startX) {
		case _NUMBER_OF_BRICKS_PER_LINE_ - 2:    // 15
		case _NUMBER_OF_BRICKS_PER_LINE_ - 3:    // 14
			toX = _NUMBER_OF_BRICKS_PER_LINE_ - 1;
			break;
		default:
			toX = startX + 2;
			break;
		}
		switch (startY) {
		case _NUMBER_OF_BRICKS_PER_LINE_ - 1:    // 16
		case _NUMBER_OF_BRICKS_PER_LINE_ - 2:    // 15
		case _NUMBER_OF_BRICKS_PER_LINE_ - 3:    // 14
			toY = _NUMBER_OF_BRICKS_PER_LINE_ - 1;
			break;
		default:
			toY = startY + 2;
			break;
		}

		
		bool crashed = false;
		sf::FloatRect presentBall;
		sf::FloatRect rectBrick;
    
        
        
		for (unsigned short i = startY; i <= toY; i++) {
			for (unsigned short j = startX; j <= toX; j++) {
        
//        for (unsigned short i = _NUMBER_OF_BRICKS_PER_LINE_-1; i >= 0; i--) {
//            for (unsigned short j = 0; j < _NUMBER_OF_BRICKS_PER_LINE_; j++) {
				// kiểm tra thật sự
				sf::Vector2f ve;
				if (stage.mSignBricks[i][j] != 0 && stage.mStage[i][j]->collision(this->imgSpr.getGlobalBounds())) {
                    
                    this->pastTouchOnPaddle = sf::Vector2f(this->posX + this->posXend/2, this->posY);

					if (!crashed) {
						rectBrick = stage.mStage[i][j]->getBound();

						//==================================

						presentBall = sf::FloatRect(this->posX, this->posY, this->posXend, this->posYend);

						ve = returnPosOnBorder(rectBrick, presentBall, this->pastBall);

						this->posX = ve.x;
						this->posY = ve.y;

					}

					crashed = true;
					stage.mStage[i][j]->destroy();
					score += stage.mStage[i][j]->getScore();
					if (checkGift == 1)
					{
						rewardItem* gift = new doubleScore;
						gift->runItem(score, i, j, stage);
						delete gift;
					}
					else if (checkGift == 2)
					{
						rewardItem* gift = new divideScore;
						gift->runItem(score, i, j, stage);
						delete gift;
					}
					if (stage.mSignBricks[i][j] != -1) {
						if (stage.mSignBricks[i][j] == 8)
						{
							this->crashedIntoTreasure = true;
						}
						else if (1 <= stage.mSignBricks[i][j] && stage.mSignBricks[i][j] <= 3) {
							stage.availableBricks--;
						}

						if (stage.mSignBricks[i][j] == 9 && checkGift != 0)
						{
							stage.mSignBricks[i][j] = -1;
//							delete stage.mStage[i][j];
							stage.mStage[i][j] = new RockBrick;
							stage.mStage[i][j]->set(_DIS_FROM_LEFT_ + j * (_WIDTH_BRICK_ + _DIS_BETWEEN_BRICKS_), _DIS_FROM_TOP_ + i * (_WIDTH_BRICK_ / _GOLDEN_RATIO_ + _DIS_BETWEEN_BRICKS_), _WIDTH_BRICK_, _WIDTH_BRICK_ / _GOLDEN_RATIO_, stage.mSignBricks[i][j]);
							continue;
						}

						else if (stage.mSignBricks[i][j] == 9 && checkGift == 0)
						{
							timeEnd = stage.getTimePlaying() + 10; // time cua moi vat pham la 10s
							srand((int)time(0));
							checkGift = 1 + rand() % 4; // random ngau nhien vat pham
							/*
							1. Double Score
							2. Divide Score
							3. Zoom Ball
							4. Widen Bar

							 */
							if (checkGift == 1)
							{
								rewardItem* gift = new doubleScore;
								gift->drawItem(bg);
								delete gift;
							}
							else if (checkGift == 2)
							{
								rewardItem* gift = new divideScore;
								gift->drawItem(bg);
								delete gift;
							}
							else if (checkGift == 3)
							{
								rewardItem* gift = new zoomBall;
								gift->runItem(*this);
								gift->drawItem(bg);
								delete gift;
							}
							else if (checkGift == 4)
							{
								rewardItem* gift = new widenBar;
								gift->runItem(bar);
								gift->drawItem(bg);
								delete gift;
							}
						}
						stage.mSignBricks[i][j] = 0;
//						delete stage.mStage[i][j];
					}

				}

			}

		}
	}
	// nếu chạm biên trên sẽ điều ngược lại trục tung
	if (this->posY <= _DIS_FROM_TOP_) {
        this->pastTouchOnPaddle = sf::Vector2f(this->posX + this->posXend/2, _DIS_FROM_TOP_);
        
		this->velocityY *= -1;
	}

	if (this->posY + this->posYend >= (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_)) {
		stage.time += stage.clock.getElapsedTime();
		stage.clock.~Clock();
		this->velocityX = 0;
		this->velocityY = 0;
		return 1; // crashed
	}

	this->imgSpr.setPosition(this->posX, this->posY);

	return 0;  // did not crash

}
bool ThePong::checkClashToBar(Pos position) {        // bắt sự kiện va vào thanh trượt
    
    if (this->posY + this->posYend > position.y) {
        // phần dưới trái của bóng chạm thanh
        if ((position.x <= this->posX) && (this->posX <= position.x + position.endX))
        {
            return true;
        }
        
        else if ((position.x <= this->posX + this->posXend) && (this->posX + this->posXend <= position.x + position.endX))
        {
            return true;
        }
        // phần dưới phải của bóng chạm thanh
    }
    
    return false;
}

void ThePong::normalizePosX() {         // điều chỉnh bóng không vượt biên trên Ox
    if (this->posX < _DIS_FROM_LEFT_) {
        this->posX = _DIS_FROM_LEFT_;
    }
    if (this->posX + this->posXend > _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_) {
        this->posX = _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_ - this->posXend;
    }
}
void ThePong::normalizePosY() {         // điều chỉnh bóng không vượt biên trên Oy
    if (this->posY < _DIS_FROM_TOP_) {
        this->posY = _DIS_FROM_TOP_;
    }
    if (this->posY + this->posYend > _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_) {
        this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - this->posYend;
    }
}

sf::FloatRect ThePong::getBoundBall(){
    return this->imgSpr.getGlobalBounds();
}
sf::Vector2f ThePong::returnPosOnBorder(sf::FloatRect brick, sf::FloatRect presentBall, sf::FloatRect pastBall){

    sf::Vector2f vect;
    
    if (presentBall.top != pastBall.top) {
        if (presentBall.top - pastBall.top > 0) {          // go down
            vect.y = brick.top - presentBall.height;
        }
        else                                                // go up
        {
            vect.y = brick.top + brick.height;
        }
        
        vect.x = pastBall.left + (presentBall.left - pastBall.left) * (vect.y - pastBall.top) / (presentBall.top - pastBall.top);
        
        if ((vect.x + presentBall.width < brick.left) || (vect.x > brick.left + brick.width )) {
            // chạm vào biên dọc của thanh
            if (presentBall.left > pastBall.left) {         // go right
                vect.x = brick.left - presentBall.width;
            }
            else                                            // go left
            {
                vect.x = brick.left + brick.width;
            }
            
            vect.y = pastBall.top + (presentBall.top - pastBall.top) * (vect.x - pastBall.left) / (presentBall.left - pastBall.left);
            this->velocityX *= -1;
        }
        else
        {
			this->velocityY *= -1;
        }
        
    }
    
    return vect;
}
bool ThePong::checkGoDown(){
    return (this->velocityY > 0);
}
bool ThePong::checkGoLeft(){
    return (this->velocityX < 0);
}
sf::Vector2f ThePong::posAtBotInFuture(){
    
    if (abs(this->velocityX) < 0.001) {
        return sf::Vector2f(this->posX, (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_));
    }
    
    float alp = (this->velocityY / this->velocityX);
    float bet = (this->posY + this->posYend/2) - alp * (this->posX + this->posXend/2);
    
//    float x = 0;
//    float y = alp * x + bet;
    
//    this->lineBall[0] = sf::Vertex(sf::Vector2f((this->posX + this->posXend/2), (this->posY + this->posYend/2)), sf::Color::Blue);
//    this->lineBall[1] = sf::Vertex(sf::Vector2f(((_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_) - bet) / alp, (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_)), sf::Color::Blue);

    float posXInFut = ((_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_) - bet) / alp;

    while (true) {

        if (_DIS_FROM_LEFT_ + this->posXend/2 <= posXInFut && posXInFut <= _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_ - this->posXend/2) {
            return sf::Vector2f(posXInFut, (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_));
        }

        else
        {
            float posXCen;
            float posYCen;

            if (posXInFut < _DIS_FROM_LEFT_ + this->posXend/2) {

                posXCen = _DIS_FROM_LEFT_ + this->posXend/2;
                posYCen = alp * posXCen + bet;

            }
            else
            {

                posXCen = _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_ - this->posXend/2;
                posYCen = alp * posXCen + bet;

            }

            alp *= -1;
            bet = (posYCen) - alp * (posXCen);

            posXInFut = ((_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_) - bet) / alp;
        }
    }
    
    return sf::Vector2f(_DIS_FROM_LEFT_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_);
}
float ThePong::lengthOfVector(){
    return sqrt(sqr(this->velocityX) + sqr(this->velocityY));
}
float ThePong::distanceToPointFromCenter(sf::Vector2f point){
    return sqrt(sqr(this->posX - point.x) + sqr(this->posY - point.y));
}
sf::Vector2f ThePong::middle(){
    return sf::Vector2f(this->posX + this->posXend/2, this->posY + this->posYend/2);
}


void ThePong::adjustIfGoThroughBricks(buildStage &stage){
    this->normalizePosY();
    this->normalizePosX();
    
    this->line.set(sf::Vector2f(this->pastBall.left + this->pastBall.width/2, this->pastBall.top + this->pastBall.height/2), sf::Vector2f(this->posX + this->posXend/2, this->posY + this->posYend/2));
    
    short rowFrom = int((this->pastBall.top + this->pastBall.height/2 - _DIS_FROM_TOP_) / (_HEIGHT_BRICK_ + _DIS_BETWEEN_BRICKS_));
    short rowTo = int((this->posY + this->posYend/2 - _DIS_FROM_TOP_) / (_HEIGHT_BRICK_ + _DIS_BETWEEN_BRICKS_));
    
    if (rowFrom >= _NUMBER_OF_BRICKS_PER_LINE_ && rowTo >= _NUMBER_OF_BRICKS_PER_LINE_) {
        return;
    }
    
    if (rowFrom >= _NUMBER_OF_BRICKS_PER_LINE_) {
        rowFrom = _NUMBER_OF_BRICKS_PER_LINE_ -1;
    }
    else if (rowTo >= _NUMBER_OF_BRICKS_PER_LINE_) {
        rowTo = _NUMBER_OF_BRICKS_PER_LINE_ -1;
    }
    
    short colFrom = int((this->pastBall.left + this->pastBall.width/2 - _DIS_FROM_LEFT_) / (_WIDTH_BRICK_ + _DIS_BETWEEN_BRICKS_));
    short colTo = int((this->posX + this->posXend/2 - _DIS_FROM_LEFT_) / (_WIDTH_BRICK_ + _DIS_BETWEEN_BRICKS_));
    
    if (abs(rowTo - rowFrom) <= 1  && abs(colTo - colFrom) <= 1) {
        return;
    }
    
    short incrI = int(this->velocityY / abs(this->velocityY));
    short incrJ = int(this->velocityX / abs(this->velocityX));
    
//    std::cout << "--------------||--------------" << std::endl;
//    std::cout << rowFrom << " |>> I: " << rowTo << " = " << incrI << std::endl;
//    std::cout << colFrom << " |>> J " << colTo << " = " << incrJ << std::endl;
//
//    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    
    for (short i = rowFrom; (incrI > 0 ? i <= rowTo : i >= rowTo); i += incrI) {
        for (short j = colFrom; (incrJ > 0 ? j <= colTo : j >= colTo); j += incrJ) {
            
            if (stage.mSignBricks[i][j] != 0) {
                
//                std::cout << i << " - " << j << std::endl;
                
                if (line.checkVertial()) {  // bong di chuyen theo chieu doc
                    
                    if (stage.mStage[i][j]->contain(sf::Vector2f(this->posX + this->posXend/2, stage.mStage[i][j]->getBot()))) {    // bóng chạm ngay biên dươi
                        
                        this->posY = stage.mStage[i][j]->getBot();
                        
                        return;
                        
                    }
                    else if (stage.mStage[i][j]->contain(sf::Vector2f(this->posX + this->posXend/2, stage.mStage[i][j]->getTop()))){
                        
                        this->posY = stage.mStage[i][j]->getTop() - this->posYend;
                        
                        return;
                    }
                    
                }
                else
                {
                    float x_bot = line.getX(stage.mStage[i][j]->getBot());
                    float x_top = line.getX(stage.mStage[i][j]->getTop());
                    
                    float x_change_bot = line.getX(stage.mStage[i][j]->getBot()) - this->posYend/2 / line.getAlp() - this->posXend/2;
                    
                    if (stage.mStage[i][j]->contain(sf::Vector2f(x_bot, stage.mStage[i][j]->getBot())) || (stage.mStage[i][j]->contain(sf::Vector2f(x_change_bot, stage.mStage[i][j]->getBot()))) || (stage.mStage[i][j]->contain(sf::Vector2f(x_change_bot + this->posXend, stage.mStage[i][j]->getBot()))) ) {    // bóng chạm ngay biên dươi
                        
                        this->posY = stage.mStage[i][j]->getBot();
                        this->posX = x_change_bot;
                        
                        return;
                        
                    }
                    else if (stage.mStage[i][j]->contain(sf::Vector2f(x_top, stage.mStage[i][j]->getTop()))){
                        
                        if (this->line.getAlp() > 0) { // bóng sẽ đi theo hướng chếch lên
                            this->posX = stage.mStage[i][j]->getLeft() - this->posXend;
                            this->posY = this->line.getY(stage.mStage[i][j]->getLeft());
                        }
                        else
                        {
                            this->posX = stage.mStage[i][j]->getRight();
                            this->line.getY(stage.mStage[i][j]->getRight());
                            // posY is not change
                        }
                        
                        return;
                    }
                    
                }
            }
        }
    }
//    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    
}

bool ThePong::isNearlyVertical(){
    return (abs(this->pastTouchOnPaddle.x - this->posX) <= 5);
}
bool ThePong::isGotTreasure(){
    return this->crashedIntoTreasure;
}
float ThePong::getVecloc(){
    return sqrt(sqr(this->velocityX) + sqr(this->velocityY));
}

sf::Vector2f ThePong::getReflexInfut(float posYFut, sf::Vector2f from){
    sf::Vector2f futPoint;
    
    if (this->posX == this->pastBall.left) {
        return sf::Vector2f(this->pastBall.left + pastBall.width/2, posYFut);
    }
    
    // y = alp * x + bet
    
    float alp = - this->velocityY / this->velocityX;
    float bet = from.y - alp * from.x;
    
    futPoint.y = posYFut;
    futPoint.x = (futPoint.y - bet) / alp;
    
    return futPoint;
}
void ThePong::draw(sf::RenderWindow& window) {      // vẽ bóng
    window.draw(this->imgSpr);
    
//    this->line.draw(window);
//    window.draw(this->lineBall, 2, sf::Lines);
    
//    window.draw(this->vertop, 2, sf::Lines);
//    window.draw(this->verbot, 2, sf::Lines);
    
    
}
