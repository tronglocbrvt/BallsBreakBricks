#include "highScore.hpp"

highScore::highScore(float point, int levelCur)
{
	level = levelCur;
	// lấy thời gian hiện tại;
	timeNow = time(0);
	tm* ltm = localtime(&timeNow);

	score = point; 
	date = ltm->tm_mday;
	month = 1 + ltm->tm_mon;
	year = 1900 + ltm->tm_year;

	hour = ltm->tm_hour;
	minute = ltm->tm_min;

	if (!font.loadFromFile("res/fnt/Truly.otf"))
	{
		std::cout << "Load font failed" << std::endl;
	}

}

highScore::~highScore()
{

}

void highScore::setPositionText(sf::Text& text, float height) // căn chỉnh giữa 
{
	sf::FloatRect textRect(text.getLocalBounds());
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2);
	text.setPosition(sf::Vector2f(_WIDTH_SCREEN / 2, height));
}

void highScore::setScore(int goal) // set lại điểm
{
	score = goal;
}

bool highScore::operator<(const highScore&A) // toán tử so sánh giữa 2 đối tượng highScore
{
	/* so sánh điểm 
	nếu điểm bằng nhau thì so sánh thời gian
	do thời gian được tính từ 1/1/1900 và được quy đổi ra giây nên không thể bằng nhau*/
	if (score == A.score)
	{
		return (timeNow < A.timeNow) ? true : false;
	}
	else 
	{
		return (score < A.score) ? true : false;
	}
}

void highScore::writeFile() // ghi thông tin điểm, thời gian vào file
{
	std::ofstream fo;

	fo.open("res/file/highScore.txt", std::ios::app);
	if (fo.fail())
	{
		std::cout << "Open file failed\n";
		return;
	}
	
	fo << level << " ";
	fo << score << " ";
	fo << date << " ";
	fo << month << " ";
	fo << year << " ";
	fo << hour << " ";
	fo << minute << " ";
	fo << timeNow << "\n";

	fo.close();
}