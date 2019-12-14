#include "buildStage.hpp"

buildStage::buildStage()
{
	this->time = sf::seconds(0.01f);
	this->availableBricks = 0;

}

buildStage::buildStage(int stage) {
    
    this->time = sf::seconds(0.01f);
    this->availableBricks = 0;
    
    std::fstream fs;
    std::stringstream stream;
    stream << "res/stage/Stage" << stage << ".txt";
    std::string dir;
    stream >> dir;
    
    fs.open(dir, std::fstream::in);

    std::string data;
    
    fs >> this->timeLimit; // this is not time
    fs >> this->timeLimit; // now, get time
    this->timeLimit *= 60; // convert into second
    
    getline(fs, data); // get '\n'

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
                    this->availableBricks++;
                    break;
                case -1:    // rock
                    this->mStage[i][j] = new RockBrick();
                    break;
                case 8:
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
buildStage::buildStage(std::string nameFile){
    
    this->time = sf::seconds(0.01f);
    this->availableBricks = 0;
    
    std::fstream fs;
    std::stringstream stream;
    stream << "res/stage/" << nameFile;
    std::string dir;
    stream >> dir;
    
    fs.open(dir, std::fstream::in);

    std::string data;
    
    fs >> this->timeLimit; // this is not time
    fs >> this->timeLimit; // now, get time
    this->timeLimit *= 60; // convert into second
    
    getline(fs, data); // get '\n'

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
                    this->availableBricks++;
                    break;
                case -1:    // rock
                    this->mStage[i][j] = new RockBrick();
                    break;
                case 8:
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

void buildStage::setTime(float temp)
{
	time = sf::seconds(temp);
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
	
}

int buildStage::getmSignBricks(int i, int j)
{
	return mSignBricks[i][j];
}

float buildStage::getTimeLimit(){
    return this->timeLimit;
}
float buildStage::getTimePlaying(){
    return this->time.asSeconds();
}
void buildStage::updateTime(){
    this->time += clock.getElapsedTime();
    clock.restart();
}
int buildStage::getAvailableBricks(){
    return this->availableBricks;
}
Brick* buildStage::getmStage(int i, int j)
{
	return mStage[i][j];
}

sf::Vector2f buildStage::nearestBrickToPoint(sf::Vector2f point, bool left){
    float minDis2Point = sqrt(sqr(_HEIGH_TABLE_GAME_) + sqr(_WIDTH_TABLE_GAME_));
    
    sf::Vector2f pointMin;
    if (left) {
        point = sf::Vector2f(_DIS_FROM_LEFT_, _DIS_FROM_TOP_);
    }
    else
    {
        point = sf::Vector2f(_DIS_FROM_LEFT_+_WIDTH_TABLE_GAME_, _DIS_FROM_TOP_);
    }
    
    short start = 0;
    short finish = 0;
    if (left) {
        start = 0;
        finish = _NUMBER_OF_BRICKS_PER_LINE_ / 2;
    }
    else
    {
        start = _NUMBER_OF_BRICKS_PER_LINE_ / 2;
        finish = _NUMBER_OF_BRICKS_PER_LINE_;
    }
    
    for (short i = _NUMBER_OF_BRICKS_PER_LINE_ -1; i >= 0; i--) {
        for (short j = start; j < finish; j++) {
            if (this->mSignBricks[i][j] > 0) {
                float distance = Object::DisBet2Point(point, this->mStage[i][j]->getCentroid());
                
                if (minDis2Point > distance) {
                    minDis2Point = distance;
                    
                    pointMin.x = this->mStage[i][j]->getCentroid().x;
                    pointMin.y = this->mStage[i][j]->getCentroid().y;
                    
                }
            }
        }
        
        if (pointMin.x != 0) {
            return pointMin;
        }
        
    }
    
    return sf::Vector2f();
}
