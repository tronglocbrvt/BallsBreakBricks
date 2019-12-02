#include "OMG.h"

int main()
{
	hideCursor();	//ẩn con trỏ nhấp nháy
	OMG omg(right, bottom);	//khởi tạo game với biên phải và dưới
	int choice;	//biến lựa chọn
	omg.printMenu(choice);	//in ra menu lựa chọn
	
	//vòng lặp chơi game khi chưa chọn quit (choice != 3)
	do
	{
		omg.run(choice); // chơi game
		omg.reset();	//reset game
		omg.printMenu(choice);	//in menu
	} while (choice != 3);

	return 0;
}



