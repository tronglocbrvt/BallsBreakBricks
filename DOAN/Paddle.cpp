//#include "Paddle.h"
//
//
//
//Paddle::Paddle(int x, int y)
//{
//	//khởi tạo các giá trị ban đầu
//	original.X = current.X = x;
//	original.Y = current.Y = y;
//}
//
//Paddle::~Paddle()
//{
//
//}
//
//COORD Paddle::getPosition()
//{
//	return current;	//trả về vị trí hiện tại
//}
//
//void Paddle::print()
//{
//	int x = current.X;
//	int y;
//	for (int i = -3; i <= 3; i++)	//paddle chiếm 7 cells trên console
//	{
//		y = current.Y + i;
//		gotoXY(x, y);	//đưa con trỏ đến vị trí cần in
//		cout << "\xDB";	//in thanh ở từng cell
//	}
//}
//
//void Paddle::reset()
//{
//	current = original;	//đưa về vị trí gốc
//}
//
//void Paddle::moveUp()
//{
//	int x = current.X;
//	int y;
//	for (int i = -3; i <= 3; i++)	//xoá paddle vị trí hiện tại
//	{
//		y = current.Y + i;
//		clearObj(x, y);
//	}
//	current.Y--;	//đưa vị trí hiện tại của paddle lên 1 cell
//	print();	//in lại paddle
//	Sleep(50);	//sleep để thấy di chuyển
//}
//
//void Paddle::moveDown()
//{
//	int x = current.X;
//	int y;
//	for (int i = -3; i <= 3; i++)	//xoá paddle vị trí hiện tại
//	{
//		y = current.Y + i;
//		clearObj(x, y);
//	}
//	current.Y++;	//đưa vị trí paddle xuống 1 cell
//	print();	//in lại paddle
//	Sleep(50);	//sleep để thấy di chuyển
//}
