#include "Ball.hpp"


// the pong class
ThePong::ThePong() {

    this->crashedIntoTreasure = false;
    
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
    
//    this->velocityX = -0.3;
//    this->velocityY = 0.2;
    
    /*
     
     
     
     */
    
    // điều chỉnh vị trí
    this->imgSpr.setPosition(this->posX, this->posY);
    
    this->point1.set(".", std::string("HACKED.ttf"), 0, 0);
//    this->point1.scale(0.5);
    this->point1.setColor(15, 15, 15);

    this->point2.set(".", std::string("HACKED.ttf"), 0, 0);
//    this->point2.scale(0.2);
    this->point2.setColor(240, 40, 115);
    
    this->point3.set(".", std::string("HACKED.ttf"), 0, 0);
//    this->point3.scale(0.2);
    this->point3.setColor(80, 180, 80);
    
    this->point4.set(".", std::string("HACKED.ttf"), 0, 0);
//    this->point4.scale(0.2);
    this->point4.setColor(015, 105, 215);
    
    for (int i=0; i<9; i++) {
        this->pointX[i].set(".", std::string("HACKED.ttf"), 0, 0);
        this->pointX[i].setColor(25, 25, 135);
    }

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
    this->imgSpr.setPosition(this->posX - this->posXend * 1.0 / 2, this->posY - this->posYend * 1.0 / 2);

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
}

void ThePong::setPosY(float y) {        // đặt vị trí y
    this->posY = y;
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
    this->posX = _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_;
    this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - this->posYend - _HEIGH_BAR_;

    // đặt ngẫu nhiên tốc độ bóng
    srand(time(nullptr));
    this->velocityY = -_VELOCITY_Y_ * ((rand() % 100) * 1.0 / 100 + 1) * _HEIGH_TABLE_GAME_ / (_WIDTH_TABLE_GAME_);
    this->velocityX = _VELOCITY_X_ * (((rand() % 100) * 1.0 / 50 - 1) >= 0 ? 1 : -1) * (_VELOCITY_X_ / sqrt(sqr(_VELOCITY_X_) + sqr(this->velocityY)));
    
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
short ThePong::moveBall(Pos positionBar, buildStage &stage, float &score) {

    float pastPosX = this->posX;
    float pastPosY = this->posY;
    
    this->pastBall = this->imgSpr.getGlobalBounds();
    
    // hàm di chuyển bóng
    
    // thay đổi vị trí bóng
    this->posX += this->velocityX;
    this->posY += this->velocityY;
    
    // điều chỉnh nếu bóng vượt biên
    this->normalizePosX();
    this->normalizePosY();
    
    if ((this->posX <= _DIS_FROM_LEFT_) || (this->posX + this->posXend >= _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_)) {

        this->velocityX *= -1;

    }

    // kiểm tra chạm thanh
    if (this->checkClashToBar(positionBar)) {
        
        this->posX = pastPosX + (this->posX - pastPosX) * (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_ - this->posYend - pastPosY) / (this->posY - pastPosY);
        this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_ - this->posYend;
        
        // cập nhật vận tốc trên trục nếu có thay đổi
        if ((this->posX > positionBar.x + positionBar.endX) || (this->posX + this->posXend < positionBar.x)) {
            this->velocityX *= -1;
        }
        else{
            this->velocityY *= -1;
        }

        // cập nhật vận tốc mới vì đã chạm thanh
        this->updateVelocityY();
        this->updateVelocityX();

    }
    
    // kiểm tra chạm gạch
    
     float middleX = this->posX + posXend/2;
     float middleY = this->posY + posYend/2;
     
     short startX = (int)((middleX - _DIS_FROM_LEFT_) / (_WIDTH_BRICK_ + _DIS_BETWEEN_BRICKS_)) - 1;  // -1 -> 15
     short startY = (int)((middleY - _DIS_FROM_TOP_) / (_WIDTH_BRICK_ / _GOLDEN_RATIO_ + _DIS_BETWEEN_BRICKS_)) -1;     // -1 -> 16
    
    if (startX < 0) startX = 0;
    if (startY < 0) startY = 0;
    
    if (startX < _NUMBER_OF_BRICKS_PER_LINE_ && startY < _NUMBER_OF_BRICKS_PER_LINE_) {
        
        unsigned short toX, toY;
        switch (startX) {
            case _NUMBER_OF_BRICKS_PER_LINE_ -2:    // 15
            case _NUMBER_OF_BRICKS_PER_LINE_ -3:    // 14
                toX = _NUMBER_OF_BRICKS_PER_LINE_ -1;
                break;
            default:
                toX = startX +2;
                break;
        }
        switch (startY) {
            case _NUMBER_OF_BRICKS_PER_LINE_ -1:    // 16
            case _NUMBER_OF_BRICKS_PER_LINE_ -2:    // 15
            case _NUMBER_OF_BRICKS_PER_LINE_ -3:    // 14
                toY = _NUMBER_OF_BRICKS_PER_LINE_ -1;
                break;
            default:
                toY = startY +2;
                break;
        }
        
        int count = 0;
        bool crashed = false;
        sf::FloatRect presentBall;
        sf::FloatRect rectBrick;
        for (unsigned short i = startY; i <= toY; i++){
           for (unsigned short j = startX; j <= toX; j++){
               // làm cho zui thôi
               if (stage.mSignBricks[i][j] != 0) {
                   this->pointX[count++].setPosition(stage.mStage[i][j]->getBound().left, stage.mStage[i][j]->getBound().top);
               }
               // kiểm tra thật sự
               sf::Vector2f ve;
               if (stage.mSignBricks[i][j] != 0 && stage.mStage[i][j]->collision(this->imgSpr.getGlobalBounds())){
                   
                   if (!crashed) {
                       rectBrick = stage.mStage[i][j]->getBound();
                                          
                      //==================================
                      
                       presentBall = sf::FloatRect(this->posX, this->posY, this->posXend, this->posYend);
                                         
                       ve = returnPosOnBorder(rectBrick, presentBall, this->pastBall);
                       
                       this->point4.setPosition(ve.x, ve.y);
                       this->posX = ve.x;
                       this->posY = ve.y;
                      
                   }
                   
                   crashed = true;
                   
                   stage.mStage[i][j]->destroy();
                   score += stage.mStage[i][j]->getScore();
                   if (stage.mSignBricks[i][j] != -1) {
                       if (stage.mSignBricks[i][j] == 8)
                          {
                              this->crashedIntoTreasure = true;
                          }
                       stage.mSignBricks[i][j] = 0;
//					   if (stage.mSignBricks[i][j] == 9)
//					   {
//						   SpecBricks special;
//						   special.dropGift(*this, bar, positionBar); // ko ổn
//					   }
                       delete stage.mStage[i][j];
                   }
                   
               }
                          
           }

        }
        
    }
    
    
    
    // nếu chạm biên trên sẽ điều ngược lại trục tung
    if (this->posY <= _DIS_FROM_TOP_) {
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
        
        this->point1.setPosition(pastBall.left, pastBall.top);
        this->point2.setPosition(presentBall.left, presentBall.top);
        this->point3.setPosition(brick.left, brick.top);
        
    }
    
    return vect;
}
bool ThePong::checkGoDown(){
    return (this->velocityY > 0);
}
sf::Vector2f ThePong::posAtBotInFuture(){
        
    float alp = (this->velocityY / this->velocityX);
    float bet = (this->posY + this->posYend/2) - alp * (this->posX + this->posXend/2);
    
//    float x = 0;
//    float y = alp * x + bet;
    
    this->lineBall[0] = sf::Vertex(sf::Vector2f((this->posX + this->posXend/2), (this->posY + this->posYend/2)), sf::Color::Blue);
    this->lineBall[1] = sf::Vertex(sf::Vector2f(((_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_) - bet) / alp, (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_)), sf::Color::Blue);
    
    float posXInFut = ((_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_) - bet) / alp;
    
    while (true) {
        
        if (_DIS_FROM_LEFT_ + this->posXend/2 <= posXInFut && posXInFut <= _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_ - this->posXend/2) {
            return sf::Vector2f(posXInFut, (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_));
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
            
            posXInFut = ((_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_) - bet) / alp;
        }
    }
    
    return sf::Vector2f(_DIS_FROM_LEFT_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_);
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

bool ThePong::isGotTreasure(){
    return this->crashedIntoTreasure;
}

void ThePong::draw(sf::RenderWindow& window) {      // vẽ bóng
    window.draw(this->imgSpr);
    
    point1.drawText(window);
    point2.drawText(window);
    point3.drawText(window);
	point4.drawText(window);
    for (int i=0; i<9; i++) {
        this->pointX[i].drawText(window);
        this->pointX[i].setPosition(0, 0);
    }
    
    window.draw(this->lineBall, 2, sf::Lines);
    
}
