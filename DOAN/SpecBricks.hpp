#ifndef SpecBricks_hpp
#define SpecBricks_hpp

#include "Brick.hpp"
#include "rewardItem.h"
#include <ctime>

class SpecBricks : public Brick {
protected:
	sf::Texture textSpecial;
	sf::Sprite imgSpecial;
	int typeGift; // loại vật phẩm, ta sẽ random
public:
    SpecBricks();
    virtual ~SpecBricks();
    
    virtual void destroy();
	void dropGift(rewardItem& Gift, ThePong& ball, TheBar& bar);
};

#endif /* SpecBricks_hpp */
