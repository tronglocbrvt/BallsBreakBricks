#include "Paddle.hpp"

// the bar class
TheBar::TheBar(){
    
    if (!this->textureBar.loadFromFile("res/img/barRed.png")) {
        std::cout << "Load File Failed";
    }
    this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_;
    this->posX = _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_/2 - _WIDTH_BAR_/2;
    
    this->imgSpr.setTexture(this->textureBar);      // set sprite theo texture
    this->heigBar = this->imgSpr.getTexture()->getSize().y;     // lấy kích thước theo chiều dài Oy
    this->longBar = this->imgSpr.getTexture()->getSize().x;     // lấy kích thước theo chiều rộng Ox
    
    this->imgSpr.scale( _WIDTH_BAR_ * 1.0 / this->longBar, _HEIGH_BAR_ * 1.0 / this->heigBar);      // scale để có kích thước chính xác là (_WIDTH_BAR_, _HEIGH_BAR_)
    
    // get lại kích thước mới
    this->heigBar = this->heigBar * this->imgSpr.getScale().y;
    this->longBar = this->longBar * this->imgSpr.getScale().x;
    
    
    // set tốc độ di chuyển theo chiều Oy
    this->velocityX = _VELOCITY_X_BAR_;
    this->acceleration = _ACCELERATION_BAR_;
    
    // set default information
    this->namePlayer = "Player";
    this->scores = 0;

}

TheBar::TheBar(bool side, float posX, int score, int health, std::string name)  // true = side A - left     false = side B - right          constructor: set theo thông tin ban đầu
{
    if (!this->textureBar.loadFromFile("res/img/barRed.png")) {
        std::cout << "Load File Failed";
    }
    this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - _HEIGH_BAR_;
    
    
    this->imgSpr.setTexture(this->textureBar);      // set sprite theo texture
    
    this->heigBar = this->imgSpr.getTexture()->getSize().y;     // lấy kích thước theo chiều dài Oy
    this->longBar = this->imgSpr.getTexture()->getSize().x;     // lấy kích thước theo chiều rộng Ox

    this->imgSpr.scale(_WIDTH_BAR_ * 1.0 / this->longBar, _HEIGH_BAR_ * 1.0 / this->heigBar);      // scale để có kích thước chính xác là (_WIDTH_BAR_, _HEIGH_BAR_)
    
    // get lại kích thước mới
    this->heigBar = this->heigBar * this->imgSpr.getScale().y;
    this->longBar = this->longBar * this->imgSpr.getScale().x;
    
    // set vị trí Oy
    this->posX = posX;

    // set tốc độ di chuyển theo chiều Ox
    this->velocityX = _VELOCITY_X_BAR_;
    this->acceleration = _ACCELERATION_BAR_;

    // set default information
    this->namePlayer = name;
    this->scores = score;
}

TheBar::~TheBar(){
    
}

void TheBar::setNamePlayer(std::string name){               // đặt tên người chơi
    this->namePlayer = name;
}
int TheBar::getScores(){                                    // lấy về số điểm đang có
    return this->scores;
}
std::string TheBar::getNameplayer(){                        // lấy về tên người chơi
    return this->namePlayer;
}

void TheBar::setScores(int score){                          // cài đặt số điểm hiện có
    this->scores = score;
}

void TheBar::setLongBar(float length)
{
	longBar = length;
}

void TheBar::setHeightBar(float height)
{
	heigBar = height;
}

void TheBar::setPosY(float y){                              // cài vị trí thanh hiện đang ở đâu theo Y
    this->posY = y;
}
float TheBar::getPosX(){                                    // lấy vị trí thanh hiện đang ở đâu theo X
    return this->posX;
}
float TheBar::getPosY(){                                    // lấy vị trí thanh hiện đang ở đâu theo Y
    return this->posY;
}
sf::Sprite TheBar::getImgSpr()
{
	return imgSpr;
}
float TheBar::getWidth(){                                   // lấy chiều dài thanh
    return this->longBar;
}
float TheBar::getHeigh(){                                   // lấy chiều cao thanh
    return this->heigBar;
}

float TheBar::getLongBar()                                  // lấy chiều dài thanh
{
    return this->longBar;
}

void TheBar::scale(float width, float heigh){               // cài đặt độ phóng của thanh
    this->imgSpr.scale(width, heigh);
}
void TheBar::moveBar(sf::RenderWindow &window, bool Left, bool Right){     // di chuyển thanh -> bool trái , bool phải
    // lưu vị trí cũ
    float pastY = this->posY;
    
    // nếu thanh di chuyển lên
    if (Left) {
        // đặt vị trí Y
        if (this->posX - this->velocityX < _DIS_FROM_LEFT_) {
            this->posX = _DIS_FROM_LEFT_;
        }
        else {
            this->posX -= this->velocityX;
        }
        
    }
    // nếu thanh đi xuống
    if (Right) {
        // đặt vị trí Y
        if ((this->posX + this->longBar + this->velocityX) > (_DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_)) {
            this->posX = _DIS_FROM_LEFT_  + _WIDTH_TABLE_GAME_ - this->longBar;
        }
        else {
            this->posX += this->velocityX;
        }
    }
    
    // dịch chuyển thanh
    this->imgSpr.move(0, this->posY - pastY);
    window.draw(this->imgSpr);
    
}
void TheBar::draw(sf::RenderWindow &window){            // thể hiện trên màn hình
    this->imgSpr.setPosition(this->posX, this->posY);
    window.draw(this->imgSpr);
    
}
void TheBar::haveScore(short score){                               // tăng điểm
    this->scores += scores;
}
