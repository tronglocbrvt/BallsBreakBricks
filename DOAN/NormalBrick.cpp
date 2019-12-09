#include "NormalBrick.hpp"

NormalBrick::NormalBrick()
{
}
NormalBrick::NormalBrick(int score){
    this->score = score;
    
    if (!this->imgTex.loadFromFile("res/img/Bricks.png", sf::IntRect((score - 1) * widBrick + 1, 2, widBrick -3, heiBrick -3))) {
        std::cout << "Load file failed" << std::endl;
        return;
    }
    this->imgTex.setSmooth(true);
    
    this->imgSpr.setTexture(this->imgTex);
}

NormalBrick::~NormalBrick()
{
}

void NormalBrick::destroy()
{
    this->imgSpr.~Sprite();
}
