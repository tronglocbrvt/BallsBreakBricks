#include "BackGround.hpp"

// class game table
Table::Table(){
    this->setPosition(startTableX(), startTableY());
    
    // vẽ đường biên ngang trên
//    this->lineTopCorssBar[0] = sf::Vertex(sf::Vector2f(this->posX - _THICK_LINE_, _DIS_FROM_TOP_ - _THICK_LINE_), sf::Color::Red);
//    this->lineTopCorssBar[1] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_ + _THICK_LINE_, _DIS_FROM_TOP_ - _THICK_LINE_), sf::Color::Blue);
//    this->lineTopCorssBar[2] = sf::Vertex(sf::Vector2f(this->posX, _DIS_FROM_TOP_), sf::Color::Red);
//    this->lineTopCorssBar[3] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_, _DIS_FROM_TOP_), sf::Color::Blue);
    
    // vẽ đường biên ngang dưới
//    this->lineBotCorssBar[0] = sf::Vertex(sf::Vector2f(this->posX - _THICK_LINE_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ + _THICK_LINE_), sf::Color::Red);
//    this->lineBotCorssBar[1] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_ + _THICK_LINE_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ + _THICK_LINE_), sf::Color::Blue);
//    this->lineBotCorssBar[2] = sf::Vertex(sf::Vector2f(this->posX, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_), sf::Color::Red);
//    this->lineBotCorssBar[3] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_), sf::Color::Blue);
    
    // vẽ đường biên dọc trái
//    this->lineLeftVerticalBar[0] = sf::Vertex(sf::Vector2f(this->posX - _THICK_LINE_, _DIS_FROM_TOP_ - _THICK_LINE_), sf::Color::Red);
//    this->lineLeftVerticalBar[1] = sf::Vertex(sf::Vector2f(this->posX - _THICK_LINE_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ + _THICK_LINE_), sf::Color::Red);
//    this->lineLeftVerticalBar[2] = sf::Vertex(sf::Vector2f(this->posX, _DIS_FROM_TOP_), sf::Color::Red);
//    this->lineLeftVerticalBar[3] = sf::Vertex(sf::Vector2f(this->posX, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_), sf::Color::Red);
    
    // vẽ đường biên dọc phải
//    this->lineRightVerticalBar[0] = sf::Vertex(sf::Vector2f(this->posX + _THICK_LINE_ + _WIDTH_TABLE_GAME_, _DIS_FROM_TOP_ - _THICK_LINE_), sf::Color::Blue);
//    this->lineRightVerticalBar[1] = sf::Vertex(sf::Vector2f(this->posX + _THICK_LINE_ + _WIDTH_TABLE_GAME_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ + _THICK_LINE_), sf::Color::Blue);
//    this->lineRightVerticalBar[2] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_, _DIS_FROM_TOP_), sf::Color::Blue);
//    this->lineRightVerticalBar[3] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_), sf::Color::Blue);
    
    // vẽ đường phân chia chính giữa
//    this->lineMiddleVerticalBar[0] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_ / 2, _DIS_FROM_TOP_), sf::Color::Red);
//    this->lineMiddleVerticalBar[1] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_ / 2, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_), sf::Color::Blue);
    
    // vẽ vòng tròn ở giữa
//    this->middleCir.setRadius(_HEIGH_TABLE_GAME_ / 6);
//    this->middleCir.setPosition(this->posX + _WIDTH_TABLE_GAME_ / 2 - this->middleCir.getRadius(), _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ / 2 - this->middleCir.getRadius());
//    this->middleCir.setOutlineThickness(2);
//    this->middleCir.setOutlineColor(sf::Color::White);
//    this->middleCir.setFillColor(sf::Color::Transparent);
    
    
}
Table::~Table(){
    
}
void Table::setPosition(float x, float y){                      // setter vị trí
    this->posX = x;
    this->posY = y;
    
}
void Table::drawTable(sf::RenderWindow &window){                // vẽ nền game
    window.draw(this->lineTopCorssBar, 4, sf::Lines);
    window.draw(this->lineBotCorssBar, 4, sf::Lines);
    window.draw(this->lineLeftVerticalBar, 4, sf::Lines);
    window.draw(this->lineRightVerticalBar, 4, sf::Lines);
    window.draw(this->lineMiddleVerticalBar, 2, sf::Lines);
    window.draw(this->middleCir);
}
float Table::getPosX(){                                         // getter vị trí X
    return this->posX;
}
float Table::midTableX(){                                       // getter vị trí chính giữ theo Ox
    return (this->startTableX() + _WIDTH_TABLE_GAME_ / 2);
}
float Table::midTableY(){                                       // getter vị trí chính giữ theo Oy
    return (this->startTableY() + _HEIGH_TABLE_GAME_ / 2);
}
float Table::startTableX(){                                     // vị trí bắt đầu của nền game
    return  (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_) / 2;
}
float Table::startTableY(){
    return _DIS_FROM_TOP_;
}


// class table information
TableInf::TableInf(){
    // set vị trí của nền
    this->setPosition((_WIDTH_SCREEN - _WIDTH_TABLE_GAME_) / 2, _HEIGH_TABLE_GAME_ + _DIS_FROM_TOP_);
    
    // load file ảnh
    this->hearticon.loadFromFile("res/img/heart.png");
    
    this->healthLeft = _MAX_HEALTH_;
    this->healthRight = _MAX_HEALTH_;
    
    // set hình mạng 2 bên
    float disFrmBord = 0;
    for (int i = 0; i < _MAX_HEALTH_; i++) {
        this->HealthLeft[i].setTexture(this->hearticon);
        this->HealthRight[i].setTexture(this->hearticon);
        
        this->HealthRight[i].scale(_WIDTH_ICON_ * 1.0 / (this->HealthRight[i].getTexture()->getSize().x), _HEIGH_ICON_ * 1.0 / (this->HealthRight[i].getTexture()->getSize().y));
        this->HealthLeft[i].scale(_WIDTH_ICON_ * 1.0 / (this->HealthLeft[i].getTexture()->getSize().x), _HEIGH_ICON_ * 1.0 / (this->HealthLeft[i].getTexture()->getSize().y));
        
        this->HealthLeft[i].setPosition(this->posX + _WIDTH_ICON_ + disFrmBord, this->posY + this->HealthLeft[i].getTexture()->getSize().y * this->HealthLeft[i].getScale().y);
        this->HealthRight[i].setPosition(this->posX - 2 * _WIDTH_ICON_ + _WIDTH_TABLE_GAME_ - disFrmBord, this->posY + this->HealthRight[i].getTexture()->getSize().y * this->HealthRight[i].getScale().y);
        
        disFrmBord += _SPACE_BET_OBJ_ + _WIDTH_ICON_;
    }
    
    // set default tỷ số điểm
    this->rateRight = 0;
    this->rateLeft  = 0;
    
}
TableInf::~TableInf(){
    
}
void TableInf::setPosition(float x, float y){       // seter vị trí
    this->posX = x;
    this->posY = y;
}
void TableInf::drawInfTable(sf::RenderWindow &window){      // hàm vẽ
    // vẽ mạng
    // bên trái
    for (int i = 0; i < this->healthLeft; i++) {
        window.draw(this->HealthLeft[i]);
    }
    // bên phải
    for (int i = 0; i < this->healthRight; i++) {
        window.draw(this->HealthRight[i]);
    }
    
    // điểm bên trái đạt được
    TextShow rateA(std::to_string(this->rateLeft), std::string("HACKED.ttf"),_WIDTH_SCREEN / 4, _HEIGH_TABLE_GAME_ + (_HEIGH_SCREEN - (_HEIGH_TABLE_GAME_+_DIS_FROM_TOP_)) / 2);
    rateA.setColor(236, 3, 252);
    
    // điểm bên phải đạt được
    TextShow rateB(std::to_string(this->rateRight), std::string("HACKED.ttf"),_WIDTH_SCREEN * 3 / 4, _HEIGH_TABLE_GAME_ + (_HEIGH_SCREEN - (_HEIGH_TABLE_GAME_+_DIS_FROM_TOP_)) / 2);
    rateB.setColor(236, 3, 252);
    
    // điểm phân chia
    TextShow devideSymbol(std::string(" : "), std::string("HACKED.ttf"),_WIDTH_SCREEN * 2, _HEIGH_TABLE_GAME_ + (_HEIGH_SCREEN - (_HEIGH_TABLE_GAME_+_DIS_FROM_TOP_)) / 2);
    devideSymbol.setColor(236, 3, 252);
    
    // tên người chơi bên trái
    TextShow nameLeft(this->namePlayerLeft, std::string("HACKED.ttf"),_WIDTH_SCREEN / 4, _HEIGH_TABLE_GAME_ + (_HEIGH_SCREEN - (_HEIGH_TABLE_GAME_+_DIS_FROM_TOP_)) / 2 - rateA.getSizeCharacter() - 10);
    
    // tên người chơi bên phải
    TextShow nameRight(this->namePlayerRight, std::string("HACKED.ttf"),_WIDTH_SCREEN * 3 / 4 + rateB.getSizeCharacter() * myMath::CountIntNumberRadix(this->rateRight) / 2, _HEIGH_TABLE_GAME_ + (_HEIGH_SCREEN - (_HEIGH_TABLE_GAME_+_DIS_FROM_TOP_)) / 2 - rateB.getSizeCharacter() - 10);
    
    // setter vị trí tên
    nameLeft.setPosition(nameLeft.getPositionX() + nameLeft.getSizeText() / nameLeft.lengthText() , nameLeft.getPositionY());
    nameRight.setPosition(nameRight.getPositionX() - 2 * nameRight.getSizeText() / nameRight.lengthText() , nameRight.getPositionY());
    
    // thay đổi kích thước hiển thị điểm
    rateA.scale(1.5);
    rateB.scale(1.5);
    devideSymbol.scale(3);
    
    // vẽ điểm
    rateA.drawText(window);
    rateB.drawText(window);
    devideSymbol.drawText(window);
    
    // vẽ tên
    nameLeft.drawText(window);
    nameRight.drawText(window);
    
}
void TableInf::setHealth(int left, int right){      // thiết lập thanh máu
    this->healthLeft    = left;
    this->healthRight   = right;
}
void TableInf::setRate(int left, int right){        // thiết lập điểm ban đầu
    this->rateLeft      = left;
    this->rateRight     = right;
}
void TableInf::setNamePlayer(std::string namePlayerLeft, std::string namePlayerRight){      // thiết lập tên
    this->namePlayerLeft = namePlayerLeft;
    this->namePlayerRight = namePlayerRight;
}


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// class background
BackGround::BackGround(){
    
}
BackGround::~BackGround(){
    
}

void BackGround::setHealth(int left, int right){        // thiết lập máu
    this->tableinf.setHealth(left, right);
}
void BackGround::setRate(int left, int right){          // thiết lập điểm
    this->tableinf.setRate(left, right);
}
void BackGround::setNamePlayer(std::string namePlayerLeft, std::string namePlayerRight){        // thiết lập tên
    this->tableinf.setNamePlayer(namePlayerLeft, namePlayerRight);
}

void BackGround::draw(sf::RenderWindow &window){        // vẽ nền
   
    this->gameTable.drawTable(window);
    this->tableinf.drawInfTable(window);
    
}
Table BackGround::getTableGame(){                       // getter nền game
    return this->gameTable;
}
