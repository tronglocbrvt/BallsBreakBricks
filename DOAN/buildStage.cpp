#include "buildStage.hpp"


buildStage::buildStage(int stage) {
    
    this->time = sf::seconds(0.01f);
    this->maxScore = 0;
    
	std::fstream fs;
    std::stringstream stream;
    stream << "res/stage/Stage" << stage << ".txt";
    std::string dir;
    stream >> dir;
    
	fs.open(dir, std::fstream::in);

	std::string data;
    
    fs >> this->timeLimit;
    fs >> this->timeLimit;
    this->timeLimit *= 60;
    getline(fs, data); // get stage

    for (int i = 0; i < _NUMBER_OF_BRICKS_PER_LINE_; i++) {
        for (int j = 0; j < _NUMBER_OF_BRICKS_PER_LINE_; j++) {
            fs >> this->mSignBricks[i][j];
        }
    }
	fs.close();

	for (int i = 0; i < _NUMBER_OF_BRICKS_PER_LINE_; i++) {
		for (int j = 0; j < _NUMBER_OF_BRICKS_PER_LINE_; j++) {
            switch (this->mSignBricks[i][j]) {
                case 1: // brick
                case 2:
                case 3:
                    this->mStage[i][j] = new NormalBrick(this->mSignBricks[i][j]);
                    this->maxScore += this->mSignBricks[i][j];
                    break;
                case -1:    // rock
                    this->mStage[i][j] = new RockBrick();
                    break;
                case 9:
                    this->mStage[i][j] = new SpecBricks();
                    break;
                default:
                    continue;
                    break;
            }
            
            this->mStage[i][j]->set(_DIS_FROM_LEFT_ + j * (_WIDTH_BRICK_ + _DIS_BETWEEN_BRICKS_), _DIS_FROM_TOP_ + i * (_WIDTH_BRICK_ / _GOLDEN_RATIO_ + _DIS_BETWEEN_BRICKS_), _WIDTH_BRICK_, _WIDTH_BRICK_ / _GOLDEN_RATIO_, this->mSignBricks[i][j]);

		}
	}
//    for (int i=0; i<_NUMBER_OF_BRICKS_PER_LINE_; i++) {
//        for (int j=0; j<_NUMBER_OF_BRICKS_PER_LINE_; j++) {
//            std::cout << this->mSignBricks[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
}

void buildStage::startClock(){
    this->clock.restart();
}

void buildStage::draw(sf::RenderWindow &window){
    for (int i = 0; i < _NUMBER_OF_BRICKS_PER_LINE_; i++) {
		for (int j = 0; j < _NUMBER_OF_BRICKS_PER_LINE_; j++) {
			if (this->mSignBricks[i][j]) {
				this->mStage[i][j]->draw(window);
			}

		}
    }
	
    
//    NormalBrick br(2);
//    br.draw(window);
}

float buildStage::getTimeLimit(){
    return this->timeLimit;
}
float buildStage::getTimePlaying(){
    return this->time.asSeconds();
}
int buildStage::getMaxScore(){
    return this->maxScore;
}
Brick* buildStage::getmStage(int i, int j)
{
	return mStage[i][j];
}






//                            this->mStage[i][j].setSize(sf::Vector2f(_WIDTH_BRICK_ , _WIDTH_BRICK_ / _GOLDEN_RATIO_));
            
//                            this->mStage[i][j].setPosition(_DIS_FROM_LEFT_ + j * (_WIDTH_BRICK_ + _DIS_BETWEEN_BRICKS_), _DIS_FROM_TOP_ + i * (_WIDTH_BRICK_ / _GOLDEN_RATIO_ + _DIS_BETWEEN_BRICKS_));
