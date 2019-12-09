#include "SpecBricks.hpp"


SpecBricks::SpecBricks(){
    this->score = 9;
    
    if (!this->imgTex.loadFromFile("res/img/specBrick.png")) {
        std::cout << "Load file failed" << std::endl;
        return;
    }
    this->imgTex.setSmooth(true);
    
    this->imgSpr.setTexture(this->imgTex);

	srand(time(NULL));
	typeGift = rand() % 5 + 1;

}
SpecBricks::~SpecBricks(){
    
}

void SpecBricks::destroy()
{
}

void SpecBricks::dropGift(rewardItem& Gift, ThePong& ball, TheBar& bar)
{
	
	switch (typeGift)
	{
	case 1:
	{
		Gift.doubleScore();
		break;
	}
	case 2:
	{
		Gift.separateScore();
		break;
	}
	case 3: 
	{
		Gift.fireBall();
		break;

	}
	case 4: 
	{
		Gift.zoomBall(ball);
		break;

	}
	case 5:
	{
		Gift.widenBar(bar);
		break;

	}
	default:
		break;
	}
}
