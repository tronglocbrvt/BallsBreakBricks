//#include "OMG.h"
//
//
//OMG::OMG(int w, int h)
//{
//	ball = new Ball(w / 2, h / 2);	//khởi tạo quả bóng tại vị trí chính giữa khung
//
//	//khởi tạo hai thanh paddle ở hai bên trái và phải
//	player1 = new Paddle(1, h / 2);
//	player2 = new Paddle(w - 1, h / 2);
//
//	score1 = score2 = 0;	//điểm ban đầu
//	stop = false;	//chưa dừng chơi
//}
//
//OMG::~OMG()
//{
//	//giải phóng bộ nhớ ha
//	delete ball;
//	delete player1;
//	delete player2;
//}
//
//void OMG::printMenu(int &choice)
//{
//
//	gotoXY(45, 12);
//	cout << "------------------------------";
//	//lựa chọn kiểu chơi 1 or 2 và thoát game 3
//	gotoXY(48, 14);
//	cout << "Please choose an option: ";
//	gotoXY(53, 16);
//	cout << "1. PvP";
//	gotoXY(53, 17);
//	cout << "2. PvE";
//	gotoXY(53, 18);
//	cout << "3. Quit";
//	gotoXY(73, 14);
//	cin >> choice;	//nhập lựa chọn
//	gotoXY(0, 19);
//}
//
//void OMG::reset()
//{
//	ball->reset();	//reset quả bóng
//
//	//reset hai thanh trượt
//	player1->reset();
//	player2->reset();
//
//	score1 = score2 = 0;	//điểm về 0
//	stop = false;	//chưa stop
//}
//
//void OMG::drawBorders()
//{
//	gotoXY(0, 0);
//	cout << (char)201;	//vẽ góc trên trái
//	gotoXY(right, 0);
//	cout << (char)187;	//vẽ góc trên phải
//	for (int i = 1; i < right; i++)
//	{
//		gotoXY(i, 0);
//		cout << (char)205;	//vẽ cạnh trên
//	}
//	for (int i = 1; i < bottom; i++)
//	{
//		gotoXY(0, i);
//		cout << (char)186;	//vẽ cạnh trái
//		gotoXY(right, i);
//		cout << (char)186;	//vẽ cạnh phải
//	}
//	gotoXY(0, bottom);
//	cout << (char)200;	//vẽ góc dưới trái
//	gotoXY(right, bottom);
//	cout << (char)188;	//vẽ góc dưới phải
//	for (int i = 1; i < right; i++)
//	{
//		gotoXY(i, bottom);
//		cout << (char)205;	//vẽ cạnh dưới
//	}
//}
//
//void OMG::printInstruction(int choice)
//{
//	//viết hướng dẫn chơi game
//	gotoXY(81, 5);
//	cout << "INSTRUCTION";
//	gotoXY(74, 7);
//	cout << "Press any key to start the game.";
//	gotoXY(74, 10);
//	cout << "Player 1: ";
//	gotoXY(74, 11);
//	cout << "W: UP; S: DOWN.";
//
//	//nếu choice (ở menu game) là 2 người chơi thì in hướng dẫn cho người chơi 2
//	if (choice == 1)
//	{
//		gotoXY(74, 13);
//		cout << "Player 2: ";
//		gotoXY(74, 14);
//		cout << "Arrow up: UP; Arrow down: DOWN.";
//	}
//	gotoXY(72, 17);
//	cout << "-----------------------------------";
//}
//
//void OMG::movePaddles()
//{
//	if (_kbhit())	//nếu nhận phím
//	{
//		char c = _getch();	//c bắt phím nhập
//
//		//quả bóng chạy về phía paddle nào thì paddle đó mới có thể di chuyển
//		if (ball->getDirection() == UPLEFT || ball->getDirection() == DOWNLEFT)
//		{
//			if (c == UP1 && player1->getPosition().Y > 4)	//nhấn key up và paddle 1 chưa chạm khung
//			{
//				player1->moveUp();	//paddle 1 đi lên
//			}
//			if (c == DOWN1 && player1->getPosition().Y < bottom - 4)	//key xuống và paddle 1 chưa chạm khung
//			{
//				player1->moveDown();	//paddle 1 đi xuống
//			}
//		}
//		else
//		{
//			if (c == UP2 && player2->getPosition().Y > 4)	//nhấn key up và paddle 2 chưa chạm khung
//			{
//				player2->moveUp();	//paddle 2 đi lên
//			}
//
//			if (c == DOWN2 && player2->getPosition().Y < bottom - 4)	//key xuống và paddle 2 chưa chạm khung
//			{
//				player2->moveDown();	//paddle 2 đi xuống
//			}
//		}
//
//		if (c == ESC)	//nếu escape thì stop ra menu
//		{
//			stop = true;
//			system("cls");
//		}
//	}
//}
//
//void OMG::moveBall()
//{
//	srand(time(NULL));	//khởi tạo để random hướng bóng
//	switch (ball->getDirection())
//	{
//	case STOP:	//nếu bóng đang dừng và nhận phím thì random một hướng bắt đầu di chuyển
//		if (_kbhit())
//		{
//			ball->changeDirection((BallDirection)((rand() % 4) + 1));
//		}
//		break;
//	case UPLEFT:	//hướng lên trái
//		ball->moveUpLeft();
//		break;
//	case UPRIGHT:	//hướng lên phải
//		ball->moveUpRight();
//		break;
//	case DOWNLEFT:	//hướng xuống trái
//		ball->moveDownLeft();
//		break;
//	case DOWNRIGHT:	//hướng xuống phải
//		ball->moveDownRight();
//	default:
//		break;
//	}
//
//	//khi bóng chạm khung trên
//	if (ball->getPosition().Y == 1)
//	{
//		//nếu đang lên phải thì thành xuống
//		if (ball->getDirection() == UPRIGHT)
//		{
//			ball->changeDirection(DOWNRIGHT);
//		}
//
//		//nếu đang lên trái thì thành xuống trái
//		if (ball->getDirection() == UPLEFT)
//		{
//			ball->changeDirection(DOWNLEFT);
//		}
//	}
//
//	//khi bóng chạm khung dưới
//	if (ball->getPosition().Y == bottom - 1)
//	{
//		//nếu đang xuống phải thì lên phải
//		if (ball->getDirection() == DOWNRIGHT)
//		{
//			ball->changeDirection(UPRIGHT);
//		}
//
//		//nếu đang xuống trái thì lên trái
//		if (ball->getDirection() == DOWNLEFT)
//		{
//			ball->changeDirection(UPLEFT);
//		}
//	}
//
//	//khi bóng sắp chạm khung trái
//	if (ball->getPosition().X == player1->getPosition().X + 1)
//	{
//		//nếu bóng chạm paddle 1
//		if (ball->getPosition().Y <= player1->getPosition().Y + 3 && ball->getPosition().Y >= player1->getPosition().Y - 3)
//		{
//			ball->speedUp();	//tăng tốc
//
//			//nếu bóng đang xuống trái thì xuống phải
//			if (ball->getDirection() == DOWNLEFT)
//			{
//				ball->changeDirection(DOWNRIGHT);
//			}
//
//			//nếu bóng đang lên trái thì lên phải
//			if (ball->getDirection() == UPLEFT)
//			{
//				ball->changeDirection(UPRIGHT);
//			}
//		}
//		else
//		{
//			//nếu bóng không chạm paddle 1 thì cộng điểm cho player2 và stop
//			score2++;
//			stop = true;
//			//in game over
//			printGameOver();
//		}
//	}
//
//	//khi bóng sắp chạm khung phải
//	if (ball->getPosition().X == player2->getPosition().X - 1)
//	{
//		//nếu bóng chạm paddle 2
//		if (ball->getPosition().Y <= player2->getPosition().Y + 3 && ball->getPosition().Y >= player2->getPosition().Y - 3)
//		{
//			//tăng tốc
//			ball->speedUp();
//
//			//nếu đang xuống phải thì xuống trái
//			if (ball->getDirection() == DOWNRIGHT)
//			{
//				ball->changeDirection(DOWNLEFT);
//			}
//
//			//nếu đang lên phải thì lên trái
//			if (ball->getDirection() == UPRIGHT)
//			{
//				ball->changeDirection(UPLEFT);
//			}
//		}
//		else
//		{
//			//nếu bóng không chạm paddle 2 thì cộng điểm cho player1 và stop
//			score1++;
//			stop = true;
//			//in game over
//			printGameOver();
//		}
//	}
//}
//void OMG::run(int choice)
//{
//	system("cls");
//	drawBorders();	//in khung
//	player1->print();	//in paddle
//	player2->print();	//in paddle
//	ball->print();	//in quả bóng
//	printInstruction(choice);	//in hướng dẫn
//
//	//nếu chọn chơi với người
//	if (choice == 1)
//	{
//		while (!stop)	//khi chưa dừng game
//		{
//			movePaddles();	//di chuyển thanh trượt
//			moveBall();	//đi chuyển quả bóng
//		}
//	}
//
//	//nếu chọn chơi với máy
//	else if (choice == 2)
//	{
//		while (!stop)	//khi chưa dừng game
//		{
//			autoMovePaddle();	//di chuyển paddle 1 và tự động di chuyển paddle 2
//			moveBall();	//di chuyển quả bóng
//		}
//
//	}
//}
//
////xử lý game over
//void OMG::printGameOver()
//{
//	//GAME OVER
//	system("cls");
//	gotoXY(52, 10);
//	cout << "CONGRATULATIONS!";
//	if (score1 > score2) //nếu điểm 1 lớn hơn điểm 2 thì người chơi 1 chiến thắng
//	{
//		gotoXY(49, 11);
//		cout << "The winner is Player 1.";
//	}
//	else if (score1 < score2) //mếu điểm 2 lớn hơn điểm 1 thì người chơi 2 chiến thắng
//	{
//		gotoXY(49, 11);
//		cout << "The winner is Player 2.";
//	}
//}
//
//void OMG::autoMovePaddle()
//{
//	if (_kbhit())
//	{
//		//xử lí thao tác paddle 1
//		//khi quả bóng hướng về phía trái
//		if (ball->getDirection() == UPLEFT || ball->getDirection() == DOWNLEFT)
//		{
//			char c = _getch();
//			if (c == UP1 && player1->getPosition().Y > 4)	//nhấn key up và paddle 1 chưa chạm khung
//			{
//				player1->moveUp();	//di chuyển paddle lên
//			}
//			if (c == DOWN1 && player1->getPosition().Y < bottom - 4)	//key xuống và paddle 1 chưa chạm khung
//			{
//				player1->moveDown();	//di chuyển paddle xuống
//			}
//			if (c == ESC)	//nếu escape thì stop ra menu
//			{
//				stop = true;
//				system("cls");
//			}
//		}
//	}
//	//xử lí thao tác tự động di chuyển paddle 2
//	//khi tung độ ball và paddle 2 trùng nhau
//	if (ball->getPosition().Y == player2->getPosition().Y)
//	{
//		switch (ball->getDirection())
//		{
//		case UPRIGHT:	//khi bóng đang đi lên
//			if (player2->getPosition().Y > 4)	//nếu paddle 2 chưa chạm khung
//			{
//				player2->moveUp();	//di chuyển paddle 2 lên
//			}
//			break;
//
//		case DOWNRIGHT:	//khi bóng đang đi xuống
//			if (player2->getPosition().Y < bottom - 4)	//nếu paddle 2 chưa chạm khung
//			{
//				player2->moveDown();	//di chuyển paddle 2 xuống
//			}
//			break;
//
//		default:
//			break;
//		}
//	}
//}
