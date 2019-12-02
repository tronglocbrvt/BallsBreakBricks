#ifndef TextClass_hpp
#define TextClass_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include "BackGround.hpp"

#define CHRACTER_SIZE 40

class TextShow {
protected:
    std::string textS;          // chuỗi lưu các ký tự để in lên màn hình
        
    sf::Font font;              // biến lưu font chữ
    sf::Text textT;             // biến Text trong sf
    sf::Text style;             // kiểu chữ
    
    float posX;                 // vị trí in ra màn hình
    float posY;
    
public:
    TextShow(std::string textS, std::string font, float posX, float posY);
    void setPosition(float posX, float posY);
    void setText(std::string textS);
    void setFont(std::string font);
    void drawText(sf::RenderWindow& window);
    void setStyleFont(int style);
    void setColor(unsigned short red, unsigned short green, unsigned short blue);
    void updateText();
    void scale(float scaleSize);
    void setSize(float size);
    
    float getSizeText();
    float getSizeCharacter();
    short lengthText();
    
    float getPositionX();
    float getPositionY();
};

#endif /* TextClass_hpp */
