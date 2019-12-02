//#pragma once
////#include <conio.h>
//#include <time.h>
//#include "Console.h"
//#include "Ball.h"
//#include "Paddle.h"
//
//
//enum move	//các phím nhận di chuyển của paddle và thoát game
//{
//	UP1 = 'w',
//	DOWN1 = 's',
//	UP2 = 72,
//	DOWN2 = 80,
//	ESC = 27,
//};
//#define right 68	//vị trí border phải
//#define bottom 28	//border dưới
//
//class OMG
//{
//private:
//	
//	Ball* ball;	//quả bóng
//	Paddle* player1, * player2;	//hai paddle chơi
//	int score1, score2;	//điểm
//	bool stop;	//biến quản lí dừng chơi sẽ in lại menu
//public:
//
//	OMG(int w, int h);
//	~OMG();
//	//in menu chơi
//	void printMenu(int &choice);
//	//reset game
//	void reset();
//	//vẽ khung
//	void drawBorders();
//	//viết hướng dẫn
//	void printInstruction(int choice);
//	//xử lí di chuyển cho thanh trượt
//	void movePaddles();
//	//xử lí di chuyển ball
//	void moveBall();
//	//hàm chạy game
//	void run(int choice);
//	//in người thắng
//	void printGameOver();
//	//tự động di chuyển thanh trượt 2
//	void autoMovePaddle();
//};
//
