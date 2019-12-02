#ifndef BackGround_hpp
#define BackGround_hpp

//#include "Ball.hpp"
#include <vector>
#include <string>
#include "TextClass.hpp"
#include "mathfunction.hpp"
//#include <SFML/Graphics.hpp>


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
    
    float posX;
    float posY;
    
    int rateLeft;
    int rateRight;
    
    bool isPersonLeft;
    bool isPersonRight;
    
    // text
    TextShow tHeader;
    TextShow rateA;
    TextShow rateB;
    TextShow devideSymbol;
    
public:
    TableInf();
    virtual ~TableInf();
    
    void setMode(bool isPersonLeft, bool isPersonRight);
    void drawInfTable(sf::RenderWindow &window);
    void setPosition(float x, float y);

    void setRate(int left, int right);
    
};

class BackGround {      // class khu vực tổng, quản lý
private:
    Table gameTable;
    TableInf tableinf;
public:
    BackGround(bool isPersonLeft, bool isPersonRight);
    virtual ~BackGround();
    
    void setRate(int left, int right);
    
    void draw(sf::RenderWindow &window);
    
    Table getTableGame();
};

#endif /* BackGround_hpp */
