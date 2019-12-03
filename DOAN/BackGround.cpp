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
    this->score = 0;
    
    this->tHeader.set(std::string("INSTRUCTION"), std::string("HACKED.ttf"), this->posX + (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_)/2, _HEIGH_SCREEN/10);
    this->tHeader.scale(1.6);
    this->tHeader.setOriginToMidle();
    
    this->tTutorial.set(std::string("        PRESS SPACE TO CONTINUE\n               OR ESC TO EXIT\n Press A or left-key to Move left\nPress D or right-key to Move right"), std::string("HACKED.ttf"), 0,0);
    this->tTutorial.setOriginToMidTop();
    this->tTutorial.setPosition(this->posX + (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_)/2, this->tHeader.getBottom() + _SPACE_BET_OBJ_);
    this->tTutorial.scale(0.8);
    this->tTutorial.setOriginToMidTop();
    // điểm bên trái đạt được
    
    this->tScore.set( std::string("Score: ") + std::to_string(this->score), std::string("HACKED.ttf"),this->posX, this->tTutorial.getBottom() + 3*_SPACE_BET_OBJ_);
    this->tScore.scale(0.8);
    this->tScore.setOriginToMidHead();
    this->tScore.setColor(236, 3, 252);
    
    this->tWeaponInf.set( std::string("Weapon: ") + weapon::fire_ball, std::string("HACKED.ttf"),this->posX, this->tScore.getBottom() + _SPACE_BET_OBJ_);
    this->tWeaponInf.scale(0.8);
    this->tWeaponInf.setOriginToMidHead();
    this->tWeaponInf.setColor(236, 3, 252);
  
//    this->point1.set(".", std::string("HACKED.ttf"), this->posX + (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_)/2, _HEIGH_SCREEN/5);
//    this->point2.set(".", std::string("HACKED.ttf"), this->posX + (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_)/2, _HEIGH_SCREEN/5);
//    this->point3.set(".", std::string("HACKED.ttf"), this->posX + (_WIDTH_SCREEN - _WIDTH_TABLE_GAME_)/2, _HEIGH_SCREEN/5);
//
//    this->point1.setPosition(this->tHeader.getPositionX(), this->tHeader.getPositionY());
//    this->point1.setColor(25, 25, 25);
//
//    this->point2.setPosition(this->tHeader.getPositionX(), this->tHeader.getBottom());
//    this->point2.setColor(50, 50, 50);
//
//    this->point3.setPosition(this->tHeader.getPositionX(), this->tHeader.getBottom() + _SPACE_BET_OBJ_);
//
    this->time = sf::seconds(0.01f);
    
}
TableInf::~TableInf(){
    
}

void TableInf::setMode(bool isPerson){
    this->isPerson = isPerson;
}

void TableInf::setPosition(float x, float y){       // seter vị trí
    this->posX = x;
    this->posY = y;
}
void TableInf::drawInfTable(sf::RenderWindow &window){      // hàm vẽ
    
    // vẽ điểm
    this->tScore.drawText(window);
    this->tHeader.drawText(window);
    this->tTutorial.drawText(window);
    this->tWeaponInf.drawText(window);
    
    time += clock.getElapsedTime();
    switch (int(time.asSeconds() * SpeechChangeColor) % NumberOfColor) {
        case MyColor::Silver:
            this->tTutorial.setColor(214, 214, 214);
            break;
        case MyColor::Asparagus:
            this->tTutorial.setColor(146, 144, 0);
            break;
        case MyColor::Midnight:
            this->tTutorial.setColor(1, 25, 147);
            break;
        case MyColor::Purple:
            this->tTutorial.setColor(204, 0, 204);
            break;
        case MyColor::Red:
            this->tTutorial.setColor(255, 80, 80);
            break;
        case MyColor::Yellow:
            this->tTutorial.setColor(255, 251, 0);
            break;
        case MyColor::Blue:
            this->tTutorial.setColor(0, 102, 255);
            break;
        case MyColor::Green:
            this->tTutorial.setColor(51, 204, 51);
            break;
        default:
            break;
    }
    clock.restart();
    
    
//    this->point1.drawText(window);
//    this->point2.drawText(window);
//    this->point3.drawText(window);
}
void TableInf::setScore(int score){        // thiết lập điểm ban đầu
    this->score = score;
}


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// class background
BackGround::BackGround(bool isPerson){
    this->tableinf.setMode(isPerson);
    
    if (!this->BGimage.loadFromFile("res/img/BG_BreakBricks.png")) {
        std::cout << "Cant find file" << std::endl;
    }
    this->BGsprite.setTexture(this->BGimage);
    this->BGsprite.scale(_WIDTH_SCREEN * 1.0 / this->BGsprite.getTexture()->getSize().x, _HEIGH_SCREEN * 1.0 / this->BGsprite.getTexture()->getSize().y);
}
BackGround::~BackGround(){
    
}

void BackGround::setScore(int score){          // thiết lập điểm
    this->tableinf.setScore(score);
}
void BackGround::draw(sf::RenderWindow &window){        // vẽ nền
   
    window.draw(this->BGsprite);
    this->gameTable.drawTable(window);
    this->tableinf.drawInfTable(window);
    
    
}
Table BackGround::getTableGame(){                       // getter nền game
    return this->gameTable;
}
