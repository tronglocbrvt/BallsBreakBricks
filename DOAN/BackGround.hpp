#ifndef BackGround_hpp
#define BackGround_hpp

//#include "Ball.hpp"
#include <vector>
#include <string>
#include "TextClass.hpp"
#include "mathfunction.hpp"
#include <map>
//#include <SFML/Graphics.hpp>

class Table {           // class khu vực xử lý đồ học nền game
private:
    sf::Vertex lineTopCorssBar[4];
    sf::Vertex lineBotCorssBar[4];
    sf::Vertex lineLeftVerticalBar[4];
    sf::Vertex lineRightVerticalBar[4];
    
    sf::RectangleShape BackGround;
    
    
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
    
    int score;
    
    short mode;
    
    // text
    TextShow tHeader;
    TextShow tScore;
    
    TextShow tTutorial;
    TextShow tWeaponInf;
//    TextShow
    
//    TextShow point1;
//    TextShow point2;
//    TextShow point3;
    
    sf::Time time;
    sf::Clock clock;
    
public:
    TableInf(short mode);
    virtual ~TableInf();
    
    void setMode(short mode);
    void drawInfTable(sf::RenderWindow &window);
    void setPosition(float x, float y);
    short getMode();

    void setScore(int score);
    
};

class BackGround {      // class khu vực tổng, quản lý
private:
    Table gameTable;
    TableInf tableinf;
    
    sf::Texture BGimage;
    sf::Sprite BGsprite;
public:
    BackGround(short mode);
    virtual ~BackGround();
    
    void setScore(int score);
    short getMode();
    
    void draw(sf::RenderWindow &window);
    
    Table getTableGame();
};

#endif /* BackGround_hpp */
