#ifndef listHighScore_hpp
#define listHighScore_hpp
#include "highScore.hpp"
#include "Display.hpp"
#include <fstream>
#include <vector>

class highScore;
class listHighScore:public Display
{
private:
	std::vector<highScore> highScores;
	sf::Font fontHead;
	sf::Text textHead;

public:
	listHighScore();
	listHighScore(float, float, int);
	virtual ~listHighScore();

	void addHighScore(highScore A);
	int readFile(int mode);
	void compareScore(highScore A, int mode);
	void drawMenu(sf::RenderWindow& window, int mode);
	int updateFile(int mode);
};

#endif
