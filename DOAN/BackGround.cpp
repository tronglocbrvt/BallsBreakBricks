#include "BackGround.hpp"

// class game table
Table::Table(){
    this->setPosition(startTableX(), startTableY());
    
    // vẽ đường biên ngang trên
    this->lineTopCorssBar[0] = sf::Vertex(sf::Vector2f(this->posX - _THICK_LINE_, this->posY - _THICK_LINE_), sf::Color::Red);
    this->lineTopCorssBar[1] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_ + _THICK_LINE_, this->posY - _THICK_LINE_), sf::Color::Blue);
    this->lineTopCorssBar[2] = sf::Vertex(sf::Vector2f(this->posX, this->posY), sf::Color::Red);
    this->lineTopCorssBar[3] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_, this->posY), sf::Color::Blue);
    
    // vẽ đường biên ngang dưới
    this->lineBotCorssBar[0] = sf::Vertex(sf::Vector2f(this->posX - _THICK_LINE_, this->posY + _HEIGH_TABLE_GAME_ + _THICK_LINE_), sf::Color::Red);
    this->lineBotCorssBar[1] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_ + _THICK_LINE_, this->posY + _HEIGH_TABLE_GAME_ + _THICK_LINE_), sf::Color::Blue);
    this->lineBotCorssBar[2] = sf::Vertex(sf::Vector2f(this->posX, this->posY + _HEIGH_TABLE_GAME_), sf::Color::Red);
    this->lineBotCorssBar[3] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_, this->posY + _HEIGH_TABLE_GAME_), sf::Color::Blue);
    
    // vẽ đường biên dọc trái
    this->lineLeftVerticalBar[0] = sf::Vertex(sf::Vector2f(this->posX - _THICK_LINE_, _DIS_FROM_TOP_ - _THICK_LINE_), sf::Color::Red);
    this->lineLeftVerticalBar[1] = sf::Vertex(sf::Vector2f(this->posX - _THICK_LINE_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ + _THICK_LINE_), sf::Color::Red);
    this->lineLeftVerticalBar[2] = sf::Vertex(sf::Vector2f(this->posX, _DIS_FROM_TOP_), sf::Color::Red);
    this->lineLeftVerticalBar[3] = sf::Vertex(sf::Vector2f(this->posX, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_), sf::Color::Red);
    
    // vẽ đường biên dọc phải
    this->lineRightVerticalBar[0] = sf::Vertex(sf::Vector2f(this->posX + _THICK_LINE_ + _WIDTH_TABLE_GAME_, _DIS_FROM_TOP_ - _THICK_LINE_), sf::Color::Blue);
    this->lineRightVerticalBar[1] = sf::Vertex(sf::Vector2f(this->posX + _THICK_LINE_ + _WIDTH_TABLE_GAME_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_ + _THICK_LINE_), sf::Color::Blue);
    this->lineRightVerticalBar[2] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_, _DIS_FROM_TOP_), sf::Color::Blue);
    this->lineRightVerticalBar[3] = sf::Vertex(sf::Vector2f(this->posX + _WIDTH_TABLE_GAME_, _DIS_FROM_TOP_ + _HEIGH_TABLE_GAME_), sf::Color::Blue);
    
    float widthLine = 1;
    
    
    this->BackGround.setSize(sf::Vector2f(_WIDTH_TABLE_GAME_ - widthLine/2, _HEIGH_TABLE_GAME_ - widthLine*1.45));
    this->BackGround.setFillColor(sf::Color(204, 255, 204));
    this->BackGround.setPosition(this->posX, this->posY);
    
    
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
    window.draw(this->BackGround);
    
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
//    return  (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_) / 2;
    return _DIS_FROM_LEFT_;
}
float Table::startTableY(){
    return _DIS_FROM_TOP_;
}


// class table information
// Tutorial table
TableInf::TableInf(){
    
    
    // set vị trí của nền
    this->setPosition(_WIDTH_TABLE_GAME_ + _DIS_FROM_LEFT_ + 2*_THICK_LINE_, _DIS_FROM_TOP_ - _THICK_LINE_);
    
    
 
    // set default tỷ số điểm
    this->rateRight = 0;
    this->rateLeft  = 0;
    
    this->tHeader.set(std::string("INSTRUCTION"), std::string("HACKED.ttf"), this->posX + (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_)/2, _HEIGH_SCREEN/10);
    
    // điểm bên trái đạt được
    this->score.set(std::to_string(this->rateLeft), std::string("HACKED.ttf"),_WIDTH_SCREEN / 4, _HEIGH_TABLE_GAME_ + (_HEIGH_SCREEN - (_HEIGH_TABLE_GAME_+_DIS_FROM_TOP_)) / 2);
    this->score.setColor(236, 3, 252);
  
    this->point1.set(".", std::string("HACKED.ttf"), this->posX + (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_)/2, _HEIGH_SCREEN/5);
    this->point2.set(".", std::string("HACKED.ttf"), this->posX + (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_)/2, _HEIGH_SCREEN/5);
    this->point3.set(".", std::string("HACKED.ttf"), this->posX + (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_)/2, _HEIGH_SCREEN/5);
    
    this->point1.setPosition(this->tHeader.getPositionX(), _HEIGH_SCREEN/5);
    this->point2.setPosition(this->tHeader.getPositionX(), _HEIGH_SCREEN/5);
    this->point3.setPosition(this->tHeader.getPositionX(), _HEIGH_SCREEN/5);
    
}
TableInf::~TableInf(){
    
}

void TableInf::setMode(bool isPersonLeft, bool isPersonRight){
    this->isPersonLeft = isPersonLeft;
    this->isPersonRight = isPersonRight;
}

void TableInf::setPosition(float x, float y){       // seter vị trí
    this->posX = x;
    this->posY = y;
}
void TableInf::drawInfTable(sf::RenderWindow &window){      // hàm vẽ
    
    // thay đổi kích thước hiển thị điểm
    this->score.scale(1.5);

    // vẽ điểm
    this->score.drawText(window);
    this->tHeader.drawText(window);
    
    this->point1.drawText(window);
    this->point2.drawText(window);
    this->point3.drawText(window);
    
}
void TableInf::setRate(int left, int right){        // thiết lập điểm ban đầu
    this->rateLeft      = left;
    this->rateRight     = right;
}


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// class background
BackGround::BackGround(bool isPersonLeft, bool isPersonRight){
    this->tableinf.setMode(isPersonLeft, isPersonRight);
    
    if (!this->BGimage.loadFromFile("res/img/BG_BreakBricks.png")) {
        std::cout << "Cant find file" << std::endl;
    }
    this->BGsprite.setTexture(this->BGimage);
    this->BGsprite.scale(_WIDTH_SCREEN * 1.0 / this->BGsprite.getTexture()->getSize().x, _HEIGH_SCREEN * 1.0 / this->BGsprite.getTexture()->getSize().y);
}
BackGround::~BackGround(){
    
}

void BackGround::setRate(int left, int right){          // thiết lập điểm
    this->tableinf.setRate(left, right);
}
void BackGround::draw(sf::RenderWindow &window){        // vẽ nền
   
    window.draw(this->BGsprite);
    this->gameTable.drawTable(window);
    this->tableinf.drawInfTable(window);
    
    
}
Table BackGround::getTableGame(){                       // getter nền game
    return this->gameTable;
}
