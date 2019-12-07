#ifndef rewardItem_hpp
#define rewardItem_hpp
#include "Brick.hpp"

class normalBrick:public Brick
{
private: 
	int score; // điểm của gạch
	int type; // loại gạch normal, mỗi gạch normal có số điểm khác nhau

public:
	normalBrick();
	virtual ~normalBrick();

	void draw(sf::RenderWindow& window);
	void destroy();
};

#endif