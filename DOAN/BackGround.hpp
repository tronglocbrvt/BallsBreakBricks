#ifndef BackGround_hpp
#define BackGround_hpp

#include "Ball.hpp"
#include <vector>
#include <string>
#include "TextClass.hpp"
#include "mathfunction.hpp"

#define _WIDTH_TABLE_GAME_ 1080
#define _HEIGH_TABLE_GAME_ 540
#define _DIS_FROM_TOP_ 25

#define _MAX_HEALTH_ 3
#define _THICK_LINE_ 5

#define _HEIGH_ICON_ 20
#define _WIDTH_ICON_ 20
#define _SPACE_BET_OBJ_ 10

class Table {           // class khu vực xử lý đồ học nền game
private:
    sf::Vertex lineTopCorssBar[4];
    sf::Vertex lineBotCorssBar[4];
    sf::Vertex lineLeftVerticalBar[4];
    sf::Vertex lineRightVerticalBar[4];
    sf::Vertex lineMiddleVerticalBar[2];
    sf::CircleShape middleCir;
    
    
    float posX;
    float posY;
public:
    Table();
    virtual ~Table();
    void drawTable(sf::RenderWindow &window);
    void setPosition(float x, float y);
    
    float getPosX();
    float midTableX();
    float midTableY();
    float startTableX();
    float startTableY();
};
class TableInf {        // class khu vực xử lý về thông tin hiện trên màn hình
private:
    std::string namePlayerLeft;
    std::string namePlayerRight;
    
    float posX;
    float posY;
    
    int rateLeft;
    int rateRight;
    
    sf::Texture hearticon;
    
    sf::Sprite HealthLeft[_MAX_HEALTH_];
    sf::Sprite HealthRight[_MAX_HEALTH_];
    
    int healthLeft;
    int healthRight;
    
public:
    TableInf();
    virtual ~TableInf();
    
    void drawInfTable(sf::RenderWindow &window);
    void setPosition(float x, float y);
    
    void setHealth(int left, int right);
    void setRate(int left, int right);
    void setNamePlayer(std::string namePlayerLeft, std::string namePlayerRight);
};

class BackGround {      // class khu vực tổng, quản lý
private:
    Table gameTable;
    TableInf tableinf;
public:
    BackGround();
    virtual ~BackGround();
    
    void setHealth(int left, int right);
    void setRate(int left, int right);
    void setNamePlayer(std::string namePlayerLeft, std::string namePlayerRight);
    
    void draw(sf::RenderWindow &window);
    
    Table getTableGame();
};

#endif /* BackGround_hpp */
