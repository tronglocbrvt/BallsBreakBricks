//#include "Ball.h"
//
//Ball::Ball(int x, int y)
//{
//	//khởi tạo các giá trị ban đầu
//	original.X = current.X = x;
//	original.Y = current.Y = y;
//	speed = 1;
//	direction = STOP;
//}
//
//Ball::~Ball()
//{
//}
//
//COORD Ball::getPosition()
//{
//	return current;	//trả về vị trí hiện tại
//}
//
//void Ball::print()
//{
//	gotoXY(current.X, current.Y);	//đưa con trỏ đến vị trí hiện tại
//	cout << "o";	//in ra quả bóng
//}
//
//void Ball::reset()
//{
//	current = original;	//đưa về vị trí gốc
//	speed = 1;	//tốc độ bằng 1
//	direction = STOP;	//dừng di chuyển
//}
//
//BallDirection Ball::getDirection()
//{
//	return direction;	//trả về hướng di chuyển
//}
//
//void Ball::changeDirection(BallDirection dir)
//{
//	direction = dir;	//thay đổi hướng di chuyển
//}
//
//void Ball::moveUpRight()
//{
//	clearObj(current.X, current.Y);	//xoá quả bóng ở vị trí hiện tại
//
//	//đưa con trỏ lên trên phải
//	current.X++;
//	current.Y--;
//
//	print();	//in lại quả bóng
//	Sleep(120/speed);	//sleep để thấy di chuyển
//}
//
//void Ball::moveUpLeft()
//{
//	//khá tương tự moveUpRight()
//	clearObj(current.X, current.Y);
//	current.X--;
//	current.Y--;
//	print();
//	Sleep(120/speed);
//}
//
//void Ball::moveDownRight()
//{
//	//khá tương tự moveUpRight()
//	clearObj(current.X, current.Y);
//	current.X++;
//	current.Y++;
//	print();
//	Sleep(120/speed);
//}
//
//void Ball::moveDownLeft()
//{
//	//khá tương tự moveUpRight()
//	clearObj(current.X, current.Y);
//	current.X--;
//	current.Y++;
//	print();
//	Sleep(120/speed);
//}
//
//void Ball::speedUp()
//{
//	speed = speed * 1.1;	//tăng tốc độ lên 10%
//}
//
//
//
//
//

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
//    this->posX = _WIDTH_TABLE_GAME_ / 2 + _DIS_FROM_LEFT_;
//    this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ - this->posYend - _HEIGH_BAR_;
    this->resetPong(0);
    
    // điều chỉnh vị trí
    this->imgSpr.setPosition(this->posX - this->posXend * 1.0 / 2, this->posY);

}
ThePong::ThePong(float x, float y, float veX, float veY) {
    // set vị trí theo điểm đầu
    this->posX = x;
    this->posY = y;

    // load file ảnh và cài đặt thông số bóng
    if (!this->textureBall.loadFromFile("res/img/pongball.png")) {
        std::cout << "Load file failed" << std::endl;
    }
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

void ThePong::setPosX(float x) {        // đặt vị trí x
    this->posX = x;
}
void ThePong::setPosY(float y) {        // đặt vị trí y
    this->posY = y;
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
//    this->velocityX /= (myMath::squarerootOf(myMath::squareOf(this->velocityX) + myMath::squareOf(this->velocityY)));
    this->velocityX *= this->acceleration;
    if (myMath::absFloat(this->velocityX) > _MAX_VELOCITY_) {
        if (this->velocityX < 0) {
            this->velocityX = -_MAX_VELOCITY_;
        }
        else this->velocityX = _MAX_VELOCITY_;
    }
}
void ThePong::updateVelocityY() {       // cập nhật tốc độ của x
    this->velocityY *= this->acceleration;
    if (myMath::absFloat(this->velocityY) > _MAX_VELOCITY_) {
        if (this->velocityY < 0) {
            this->velocityY = -_MAX_VELOCITY_;
        }
        else this->velocityY = _MAX_VELOCITY_;
    }
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
short ThePong::moveBall(sf::RenderWindow& window) {    // hàm di chuyển bóngc

    // thay đổi vị trí bóng
    this->posX += this->velocityX;
    this->posY += this->velocityY;
    
    if ((this->posX <= _DIS_FROM_LEFT_) || (this->posX + this->posXend >= _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_)) {
        
//        this->velocityY *= 1;
        this->velocityX *= -1;
//        this->acceleration = 0;
//        this->velocityY *= 0;
//        this->velocityX *= 0;

    }
    

    // điều chỉnh nếu bóng vượt biên
    this->normalizePosX();
    this->normalizePosY();

//    float rateDisFromMid = 1;
//    bool normalMoveOfX = true;
    
    // kiểm tra chạm thanh
//    bool checkCrashToBarLeft = this->checkClashToBar(positionLeft, true);
//    bool checkCrashToBarRight = this->checkClashToBar(positionRight, false);

//    if (checkCrashToBarLeft || checkCrashToBarRight) {
//        float minDis = 0;
//        if (checkCrashToBarLeft) {
//
//            // trường hợp chạm biên trên của thanh trái
//            if ((this->posX + myMath::absFloat(this->velocityX) <= positionLeft.x + positionLeft.endX) && (this->posY + this->posYend + myMath::absFloat(this->velocityY) >= positionLeft.y) && (this->posY + this->posYend + myMath::absFloat(this->velocityY) <= positionLeft.y + positionLeft.endY)) {
//                this->velocityY *= -1;
//                normalMoveOfX = false;
//            }
//            // trường hợp chạm biên dưới của thanh trái
//            else if ((this->posX + myMath::absFloat(this->velocityX) <= positionLeft.x + positionLeft.endX) && (this->posY - myMath::absFloat(this->velocityY) >= positionLeft.y) && (this->posY - myMath::absFloat(this->velocityY) <= positionLeft.y + positionLeft.endY)) {
//                this->velocityY *= -1;
//                normalMoveOfX = false;
//            }
//            // >>>>>>>>>>>>>>>>>>>>>>>>>
//            else {
//                // lấy khoảng cách nhỏ nhất từ bóng đến điểm chính giữa khi chạm thanh
//                minDis = (myMath::absFloat(this->posY - positionLeft.y + (positionLeft.endY) / 2) < myMath::absFloat(this->posY + this->posYend - positionLeft.y + (positionLeft.endY) / 2)) ? myMath::absFloat(this->posY - positionLeft.y + (positionLeft.endY) / 2) : myMath::absFloat(this->posY + this->posYend - positionLeft.y + (positionLeft.endY) / 2);
//                // tính tỷ lệ thay đổi hướng trên trục tung
//                rateDisFromMid = ((minDis / (positionLeft.endY) / 2));
//            }
//
//        }
//        else {
//            // trường hợp chạm biên trên của thanh phải
//            if ((this->posX + this->posXend - myMath::absFloat(this->velocityX) >= positionRight.x) && (this->posY + this->posYend + myMath::absFloat(this->velocityY) >= positionRight.y) && (this->posY + this->posXend + myMath::absFloat(this->velocityY) <= positionRight.y + positionRight.endY)) {
//                this->velocityY *= -1;
//                normalMoveOfX = false;
//            }
//            // trường hợp chạm biên dưới của thanh phải
//            else if ((this->posX + this->posXend - myMath::absFloat(this->velocityX) >= positionRight.x) && (this->posY - myMath::absFloat(this->velocityY) >= positionRight.y) && (this->posY - myMath::absFloat(this->velocityY) <= positionRight.y + positionRight.endY)) {
//                this->velocityY *= -1;
//                normalMoveOfX = false;
//            }
//            // >>>>>>>>>>>>>>>>>>>>>>>>>
//            else {
//                // lấy khoảng cách nhỏ nhất từ bóng đến điểm chính giữa khi chạm thanh
//                minDis = (myMath::absFloat(this->posY - positionRight.y + (positionRight.endY) / 2) < myMath::absFloat(this->posY + this->posYend - positionRight.y + (positionRight.endY) / 2)) ? myMath::absFloat(this->posY - positionRight.y + (positionRight.endY) / 2) : myMath::absFloat(this->posY + this->posYend - positionRight.y + (positionRight.endY) / 2);
//
//                // tính tỷ lệ thay đổi hướng trên trục tung
//                rateDisFromMid = ((minDis / (positionRight.endY) / 2));
//            }
//
//
//        }
//
//        // cập nhật vận tốc trên trục tung nếu có thay đổi
//        if (rateDisFromMid != 1) {
//            if (myMath::absFloat(rateDisFromMid) > _MAX_CHANGE_VELOC_) {
//                if (rateDisFromMid < 0) {
//                    rateDisFromMid = -_MAX_CHANGE_VELOC_;
//                }
//                else rateDisFromMid = _MAX_CHANGE_VELOC_;
//                this->velocityY *= (rateDisFromMid);
//            }
//
//        }
//        if (normalMoveOfX) {
//            this->velocityX *= -1;
//        }
//        else{
//            std::cout << "Error" << std::endl;
//        }
//
//        // cập nhật vận tốc mới vì đã chạm thanh
//        this->updateVelocityY();
//        this->updateVelocityX();
//
//        //
//
//    }
    // nếu chạm biên trên và dưới sẽ điều ngược lại trục tung
    if ((this->posY <= _DIS_FROM_TOP_) || (this->posY + this->posYend >= (_DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_))) {
        this->velocityY *= -1;
    }


    this->imgSpr.setPosition(this->posX, this->posY);

//    if (checkCrashToBarLeft) {
//        return -2;
//    }
//    else if (checkCrashToBarRight){
//        return 2;
//    }
    return 0;  // did not crash

}

bool ThePong::checkClashToBar(Pos position, bool side) {        // bắt sự kiện va vào thanh trượt
    if (side) {
        // trường hợp góc trên trái của bóng chạm thanh trái
        if ((this->posX <= position.x + position.endX) && (this->posY >= position.y) && (this->posY <= position.y + position.endY)) {
            return true;
        }
        // trường hợp góc dưới trái của bóng chạm thanh trái
        else if ((this->posX <= position.x + position.endX) && (this->posY + this->posYend >= position.y) && (this->posY + this->posYend <= position.y + position.endY)) {
            return true;
        }
    }
    else {
        // trường hợp góc trên phải của bóng chạm thanh phải
        if ((this->posX + this->posXend >= position.x) && (this->posY >= position.y) && (this->posY <= position.y + position.endY)) {
            return true;

        }
        // trường hợp góc dưới phải của bóng chạm thanh phải
        else if ((this->posX + this->posXend >= position.x) && (this->posY + this->posYend >= position.y) && (this->posY + this->posXend <= position.y + position.endY)) {
            return true;
        }
    }
    return false;
}

void ThePong::normalizePosX() {         // điều chỉnh bóng không vượt biên trên Ox
    if (this->posX < _DIS_FROM_LEFT_) {
        this->posX = _DIS_FROM_LEFT_;
    }
    if (this->posX > _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_) {
        this->posX = _DIS_FROM_LEFT_ + _WIDTH_TABLE_GAME_;
    }
}
void ThePong::normalizePosY() {         // điều chỉnh bóng không vượt biên trên Oy
    if (this->posY < _DIS_FROM_TOP_) {
        this->posY = _DIS_FROM_TOP_;
    }
    if (this->posY > _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_) {
        this->posY = _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_;
    }
}

void ThePong::draw(sf::RenderWindow& window) {      // vẽ bóng
    window.draw(this->imgSpr);
}
