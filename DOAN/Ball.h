#pragma once
#include "Console.h"


enum BallDirection	//các di chuyển của ball
{
	STOP, 
	UPLEFT, 
	UPRIGHT,
	DOWNLEFT,
	DOWNRIGHT,
};
class Ball
{
private:
	COORD current;	//vị trí hiện tại
	COORD original;	//vị trí gốc
	float speed;	//tốc độ
	BallDirection direction;	//hướng di chuyển
public:
	Ball(int x, int y);
	~Ball();
	//trả về vị trí hiện tại
	COORD getPosition();
	//in quả bóng ra màn hình
	void print();
	//đưa về vị trí gốc
	void reset();
	//trả về hướng di chuyển
	BallDirection getDirection();
	//thay đổi hướng di chuyển
	void changeDirection(BallDirection dir);
	//lên phải
	void moveUpRight();
	//lên trái
	void moveUpLeft();
	//xuống phải
	void moveDownRight();
	//xuống trái
	void moveDownLeft();
	//tăng tốc độ
	void speedUp();
};

