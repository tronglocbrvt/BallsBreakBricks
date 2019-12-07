#include "Ball.hpp"

// the pong class
ThePong::ThePong() {

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
    this->imgSpr.setPosition(this->posX - this->posXend * 1.0 / 2, this->posY);
    
    this->point1.set(".", std::string("HACKED.ttf"), 0, 0);
//    this->point1.scale(0.5);

    this->point2.set(".", std::string("HACKED.ttf"), 0, 0);
//    this->point2.scale(0.2);
    
    this->point3.set(".", std::string("HACKED.ttf"), 0, 0);
//    this->point3.scale(0.2);
    
    this->point4.set(".", std::string("HACKED.ttf"), 0, 0);
//    this->point4.scale(0.2);

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

void ThePong::scale(float width, float heigh) {     // thay đổi kích thước bóng kiểu co giãn
    this->imgSpr.scale(width, heigh);
}
short ThePong::moveBall(Pos positionBar, buildStage &stage) {

    float pastPosX = this->posX;
    float pastPosY = this->posY;
    
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
                toX = startX +3;
                break;
        }
        switch (startY) {
            case _NUMBER_OF_BRICKS_PER_LINE_ -1:    // 16
            case _NUMBER_OF_BRICKS_PER_LINE_ -2:    // 15
            case _NUMBER_OF_BRICKS_PER_LINE_ -3:    // 14
                toY = _NUMBER_OF_BRICKS_PER_LINE_ -1;
                break;
            default:
                toY = startY +3;
                break;
        }
        
        
        for (unsigned short i = startX; i <= toX; i++){
           for (unsigned short j = startY; j <= toY; j++){
               if (stage.mSignBricks[i][j] != 0 && stage.mStage[i][j]->collision(this->imgSpr.getGlobalBounds())){
//
//                   std::cout << "crash" << std::endl;
                   
//                   this->posX = pastPosX + (this->posX - pastPosX) * (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_ - this->posYend - pastPosY) / (this->posY - pastPosY);
//                   this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_ - this->posYend;
//
//                   // cập nhật vận tốc trên trục nếu có thay đổi
//                   if ((this->posX > positionBar.x + positionBar.endX) || (this->posX + this->posXend < positionBar.x)) {
//                       this->velocityX *= -1;      // chạm biên trái/phải của gạch
//                   }
//                   else{
//                       this->velocityY *= -1;      // chạm biên trên/dưới của gạch
//                   }
               }
//
           }
        }
        
    }
    
    
    
    // nếu chạm biên trên sẽ điều ngược lại trục tung
    if (this->posY <= _DIS_FROM_TOP_) {
        this->velocityY *= -1;
    }
    
    if (this->posY + this->posYend >= (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_)) {
        this->velocityX = 0;
        this->velocityY = 0;
        return -1;
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
    
    this->point1.setPosition(position.x, position.y);

    this->point2.setPosition(position.x + position.endX, position.y);

    this->point3.setPosition(this->posX, this->posY + this->posYend);

    this->point4.setPosition(this->posX + this->posXend, this->posY + this->posYend);
    
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

void ThePong::draw(sf::RenderWindow& window) {      // vẽ bóng
    window.draw(this->imgSpr);
    
    point1.drawText(window);
    point2.drawText(window);
    point3.drawText(window);
	point4.drawText(window);
}
//
//template <class T, class Y>
//struct MapStruct {
//    T key;
//    Y value;
//
//    MapStruct<T, Y> *pNext;
//};
//
//
//template <class T, class Y>
//class MyMap {
//private:
//    MapStruct<T, Y> *phead;
//public:
//    // function...
//};
