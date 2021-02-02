#include "listHighScore.hpp"

listHighScore::listHighScore()
{

}

listHighScore::listHighScore(float width, float height, int mode):Display(width, height)
{
	// set thông số đồ họa cho tiêu đề
	if (!fontHead.loadFromFile("res/fnt/venus.ttf"))
	{
		std::cout << "Load font failed" << std::endl;
	}

	textHead.setFont(fontHead);
	textHead.setFillColor(sf::Color::Cyan);
	textHead.setString("HIGH SCORE");
	textHead.setStyle(sf::Text::Underlined);
	textHead.setCharacterSize(40);

	setPositionText(textHead, 130);

	readFile(mode);
}

listHighScore::~listHighScore()
{

}

void listHighScore::addHighScore(highScore A) // thêm điểm cao vào vector
{
	highScores.push_back(A);
}

int listHighScore::readFile(int mode)
{
	std::ifstream fi;

	if(mode == 0)
		fi.open("res/file/highScoreP.txt");
	else
		fi.open("res/file/highScoreC.txt");

	if (fi.fail())
		std::cout << "Read file failed\n";

	fi.seekg(0, std::ios::end); // di chuyển con trỏ từ đầu file đến cuối file
	if (fi.tellg() == 0) // nếu số lượng đọc được là 0
	{
		return 0; // empty file 
	}

	fi.seekg(0); // di chuyển con trỏ về đầu file
	highScores.clear();
	highScore A(-1, 1);
	while (fi >> A.level)
	{		
		fi >> A.score;
		fi >> A.date;
		fi >> A.month;
		fi >> A.year;
		fi >> A.hour;
		fi >> A.minute;
		fi >> A.timeNow;
		addHighScore(A);
	}

	fi.close();
	return 1;
}

void listHighScore::compareScore(highScore A, int mode)
{
	if (highScores[A.level - 1] < A)
	{
		highScores[A.level - 1] = A;

		updateFile(mode); // ghi lại file 
	}
}

void listHighScore::drawMenu(sf::RenderWindow& window, int mode)
{
		while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					return;
				}
			}
			window.clear();
			Display::drawMenu(window);
			window.draw(textHead); // vẽ tiêu đề chữ "High Score"
			
			int k = 0;
			for (int i = 0; i < highScores.size(); i++) // in các điểm cao
			{ 
				highScores[i].textHigh.setFont(highScores[i].font);
				highScores[i].textHigh.setFillColor(sf::Color::Yellow);
			
				if (mode == 0 && i == 2)
					highScores[i].name = "SPECIAL 1\t\t" + std::to_string(highScores[i].score) + "\t\t<" + std::to_string(highScores[i].date) + "/" + std::to_string(highScores[i].month) + "/" + std::to_string(highScores[i].year) + ">\t\t" + "<" + std::to_string(highScores[i].hour) + ":" + std::to_string(highScores[i].minute) + ">" + '\0';
				else if (mode == 0 && i == 5)
					highScores[i].name = "SPECIAL 2\t\t" + std::to_string(highScores[i].score) + "\t\t<" + std::to_string(highScores[i].date) + "/" + std::to_string(highScores[i].month) + "/" + std::to_string(highScores[i].year) + ">\t\t" + "<" + std::to_string(highScores[i].hour) + ":" + std::to_string(highScores[i].minute) + ">" + '\0';
				else 
					highScores[i].name = " LEVEL  " + std::to_string(++k) + "\t\t" + std::to_string(highScores[i].score) + "\t\t<" + std::to_string(highScores[i].date) + "/" + std::to_string(highScores[i].month) + "/" + std::to_string(highScores[i].year) + ">\t\t" + "<" + std::to_string(highScores[i].hour) + ":" + std::to_string(highScores[i].minute) + ">" + '\0';

				highScores[i].textHigh.setString(highScores[i].name);
				highScores[i].textHigh.setStyle(sf::Text::Regular);
				highScores[i].textHigh.setCharacterSize(40);
				setPositionText(highScores[i].textHigh, 190 + i * 60);
				window.draw(highScores[i].textHigh);

			}

			window.display();
		}
	}
}

int listHighScore::updateFile(int mode)
{
	std::ofstream fo;

	if (mode == 0)
		fo.open("res/file/highScoreP.txt");
	else
		fo.open("res/file/highScoreC.txt");

	if (fo.fail())
	{
		std::cout << "Open file failed\n";
		return 0;
	}

	for (int i = 0; i < highScores.size(); i++) // ghi lại file danh sách điểm cao
	{
		fo << highScores[i].level << " ";
		fo << highScores[i].score << " ";
		fo << highScores[i].date << " ";
		fo << highScores[i].month << " ";
		fo << highScores[i].year << " ";
		fo << highScores[i].hour << " ";
		fo << highScores[i].minute << " ";
		fo << highScores[i].timeNow << "\n";
	}

	fo.close();
	return 1;
}


