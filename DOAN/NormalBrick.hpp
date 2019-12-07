#ifndef rewardItem_hpp
#define rewardItem_hpp
#include "Brick.hpp"

class NormalBrick:public Brick
{
private: 
	int score; // điểm của gạch
	int type; // loại gạch normal, mỗi gạch normal có số điểm khác nhau

public:
	NormalBrick();
	virtual ~NormalBrick();
    
	virtual void destroy();
};

#endif
