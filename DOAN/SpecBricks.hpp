#ifndef SpecBricks_hpp
#define SpecBricks_hpp

#include "Brick.hpp"
#include "rewardItem.h"
#include "DataPos.hpp"
#include <ctime>

class SpecBricks : public Brick {
protected:
//	rewardItem Gift;
	sf::Texture textSpecial;
	sf::Sprite imgSpecial;
	int typeGift; // loại vật phẩm, ta sẽ random
	float veloc;
public:
    SpecBricks();
    virtual ~SpecBricks();
    
    virtual short getScore();
    virtual void destroy();
//	void dropGift(ThePong& ball, TheBar& bar, Pos positionBar);
	bool checkClashBar(Pos position);
	void drawGift(sf::RenderWindow& window);
};

#endif /* SpecBricks_hpp */
