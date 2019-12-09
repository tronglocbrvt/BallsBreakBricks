#ifndef highScore_hpp
#define highScore_hpp

#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <fstream>
#include "Display.hpp"

class highScore
{
private:
	sf::Text textHigh; 
	sf::Font font;

	int level;
	int score;
	int date;
	int month;
	int year;

	int hour;
	int minute;

	std::string name;

	time_t timeNow;

public:
	highScore();
	virtual ~highScore();

	void setPositionText(sf::Text&, float);
	void setScore(int);

	bool operator <(const highScore&);
	void writeFile();
	friend class listHighScore;
};
#endif
