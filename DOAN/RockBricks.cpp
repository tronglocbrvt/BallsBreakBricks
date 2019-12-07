#include "RockBricks.hpp"

RockBrick::RockBrick(){
    this->score = -1;
    
    if (!this->imgTex.loadFromFile("res/img/rock.png")) {
        std::cout << "Load file failed" << std::endl;
        return;
    }
    this->imgTex.setSmooth(true);
    
    this->imgSpr.setTexture(this->imgTex);
}
RockBrick::~RockBrick(){
    
}

void RockBrick::destroy()
{
}
