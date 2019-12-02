#include "Console.h"



void gotoXY(int x, int y)
{
	COORD coord;
	//gán toạ độ cho coord
	coord.X = x;
	coord.Y = y;
	//đưa con trỏ đến coord
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearObj(int x, int y)
{
	gotoXY(x, y);	//đến vị trí x y
	cout << " ";	//cout khoảng trắng
}

void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);

	//tham khảo:
	//https://stackoverflow.com/questions/30126490/how-to-hide-console-cursor-in-c/55313602
	//https://docs.microsoft.com/en-us/windows/console/setconsolecursorinfo?redirectedfrom=MSDN
}