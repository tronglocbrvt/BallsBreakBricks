#include "buildStage.hpp"


buildStage::buildStage(int stage){
    std::fstream fs;
    fs.open("res/file/Stage.txt", std::fstream::in);
    
    std::string data;
    
    while (getline(fs, data)) {
        if (std::stoi(data) == stage) {
            for (int i = 0; i < _NUMBER_OF_BRICKS_PER_LINE_; i++) {
                for (int j = 0; j < _NUMBER_OF_BRICKS_PER_LINE_; j++) {
                    fs >> this->mSignBricks[i][j];
                }
            }
            getline(fs, data); // get '/n'
            getline(fs, data); // get empty line
        }
        else
        {
            for (int i = 0; i<= _NUMBER_OF_BRICKS_PER_LINE_; i++) {
                getline(fs, data);
            }
        }
    }
    
    std::cout <<  _WIDTH_BRICK_/_GOLDEN_RATIO_ << " = " << std::endl;

    for (int i = 0; i < _NUMBER_OF_BRICKS_PER_LINE_; i++) {
        for (int j = 0; j < _NUMBER_OF_BRICKS_PER_LINE_; j++) {
            if (this->mSignBricks[i][j]) {
                
                this->mStage[i][j].set(_DIS_FROM_LEFT_ + j * (_WIDTH_BRICK_ + _DIS_BETWEEN_BRICKS_), _DIS_FROM_TOP_ + i * (_WIDTH_BRICK_ / _GOLDEN_RATIO_ + _DIS_BETWEEN_BRICKS_), _WIDTH_BRICK_, _WIDTH_BRICK_ / _GOLDEN_RATIO_, this->mSignBricks[i][j]);
                
//                this->mStage[i][j].setSize(sf::Vector2f(_WIDTH_BRICK_ , _WIDTH_BRICK_ / _GOLDEN_RATIO_));
//
//                this->mStage[i][j].setPosition(_DIS_FROM_LEFT_ + j * (_WIDTH_BRICK_ + _DIS_BETWEEN_BRICKS_), _DIS_FROM_TOP_ + i * (_WIDTH_BRICK_ / _GOLDEN_RATIO_ + _DIS_BETWEEN_BRICKS_));
                
            }
        }
    }
    
    fs.close();
}

void breakTheBrick(const sf::FloatRect& ballBound){
    
}

void buildStage::draw(sf::RenderWindow &window){
    for (int i = 0; i < _NUMBER_OF_BRICKS_PER_LINE_; i++) {
        for (int j = 0; j < _NUMBER_OF_BRICKS_PER_LINE_; j++) {
            if (this->mSignBricks[i][j]) {
//                window.draw(this->mStage[i][j]);
                this->mStage[i][j].draw(window);
            }
            
        }
    }
}
