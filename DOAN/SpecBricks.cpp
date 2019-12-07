#include "SpecBricks.hpp"


SpecBricks::SpecBricks(){
    this->score = 9;
    
    if (!this->imgTex.loadFromFile("res/img/specBrick.png")) {
        std::cout << "Load file failed" << std::endl;
        return;
    }
    this->imgTex.setSmooth(true);
    
    this->imgSpr.setTexture(this->imgTex);
}
SpecBricks::~SpecBricks(){
    
}

void SpecBricks::destroy()
{
}
