#include "listHighScore.hpp"

listHighScore::listHighScore()
{

}

listHighScore::listHighScore(float width, float height):Display(width, height)
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
	textHead.setCharacterSize(50);

	setPositionText(textHead, 140);

	readFile();
}

listHighScore::~listHighScore()
{

}

void listHighScore::addHighScore(highScore A) // thêm điểm cao vào vector
{
	highScores.push_back(A);
}

int listHighScore::readFile()
{
	std::ifstream fi;

	fi.open("res/file/highScore.txt");
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

void listHighScore::compareScore(highScore A)
{
	if (highScores[A.level - 1] < A)
	{
		highScores[A.level - 1] = A;

		updateFile(); // ghi lại file 
	}
}

void listHighScore::drawMenu(sf::RenderWindow& window)
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
			
			for (int i = 0; i < highScores.size(); i++) // in các điểm cao
			{ 
				highScores[i].textHigh.setFont(highScores[i].font);
				highScores[i].textHigh.setFillColor(sf::Color::Yellow);
				highScores[i].name = "Level " + std::to_string(highScores[i].level) +"\t\t" + std::to_string(highScores[i].score) + "\t\t<" + std::to_string(highScores[i].date) + "/" + std::to_string(highScores[i].month) + "/" + std::to_string(highScores[i].year) + ">\t\t" + "<" + std::to_string(highScores[i].hour) + ":" + std::to_string(highScores[i].minute) + ">" + '\0';
				highScores[i].textHigh.setString(highScores[i].name);
				highScores[i].textHigh.setStyle(sf::Text::Regular);
				highScores[i].textHigh.setCharacterSize(40);
				setPositionText(highScores[i].textHigh, 150 + i * 70);
				window.draw(highScores[i].textHigh);

			}

			window.display();
		}
	}
}

int listHighScore::updateFile()
{
	std::ofstream fo;

	fo.open("res/file/highScore.txt");
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


