#pragma once
#include "Console.h"

class Paddle
{
private:
	COORD current;	//vị trí hiện tại
	COORD original;	//vị trí gốc

public:
	
	Paddle(int x, int y);
	~Paddle();
	//trả về vị trí hiện tại
	COORD getPosition();
	//in thanh trượt
	void print();
	//đưa về vị trí gốc
	void reset();
	//di chuyển thanh lên
	void moveUp();
	//di chuyển thanh xuống
	void moveDown();
};

