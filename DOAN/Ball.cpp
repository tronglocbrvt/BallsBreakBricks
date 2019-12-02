#include "Ball.h"

Ball::Ball(int x, int y)
{
	//khởi tạo các giá trị ban đầu
	original.X = current.X = x;
	original.Y = current.Y = y;
	speed = 1;
	direction = STOP;
}

Ball::~Ball()
{
}

COORD Ball::getPosition()
{
	return current;	//trả về vị trí hiện tại
}

void Ball::print()
{
	gotoXY(current.X, current.Y);	//đưa con trỏ đến vị trí hiện tại
	cout << "o";	//in ra quả bóng
}

void Ball::reset()
{
	current = original;	//đưa về vị trí gốc
	speed = 1;	//tốc độ bằng 1
	direction = STOP;	//dừng di chuyển
}

BallDirection Ball::getDirection()
{
	return direction;	//trả về hướng di chuyển
}

void Ball::changeDirection(BallDirection dir)
{
	direction = dir;	//thay đổi hướng di chuyển
}

void Ball::moveUpRight()
{
	clearObj(current.X, current.Y);	//xoá quả bóng ở vị trí hiện tại

	//đưa con trỏ lên trên phải
	current.X++;
	current.Y--;

	print();	//in lại quả bóng
	Sleep(120/speed);	//sleep để thấy di chuyển
}

void Ball::moveUpLeft()
{
	//khá tương tự moveUpRight()
	clearObj(current.X, current.Y);
	current.X--;
	current.Y--;
	print();
	Sleep(120/speed);
}

void Ball::moveDownRight()
{
	//khá tương tự moveUpRight()
	clearObj(current.X, current.Y);
	current.X++;
	current.Y++;
	print();
	Sleep(120/speed);
}

void Ball::moveDownLeft()
{
	//khá tương tự moveUpRight()
	clearObj(current.X, current.Y);
	current.X--;
	current.Y++;
	print();
	Sleep(120/speed);
}

void Ball::speedUp()
{
	speed = speed * 1.1;	//tăng tốc độ lên 10%
}





