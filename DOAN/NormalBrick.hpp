#ifndef NormalBrick_hpp
#define NormalBrick_hpp
#include "Brick.hpp"

#define widBrick 113
#define heiBrick 47

class NormalBrick : public Brick
{
protected:
public:
    NormalBrick();
	NormalBrick(int score);
	virtual ~NormalBrick();
    
	virtual void destroy();
};

#endif
