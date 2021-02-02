
#ifndef PvsP_hpp
#define PvsP_hpp

#include "BackGround.hpp"
#include "Ball.hpp"
#include "rewardItem.h"
#include "Paddle.hpp"
#include "buildStage.hpp"
#include <thread>
#include <future>
#include "listHighScore.hpp"

bool pauseGame(sf::RenderWindow& window, ThePong& ball, BackGround& bg, TheBar& bar, buildStage& stage, TextShow& text, sf::Keyboard::Key key, bool mode, int level, int checkGift, float timeEnd);
int EndGame(sf::RenderWindow& window, buildStage &stage, float score, int level, bool isWinner, int mode);
int play(sf::RenderWindow& window, int levelCur); // người với người chơi
void saveGame(ThePong ball, TheBar bar, bool mode, buildStage stage, int level, int checkGift, float timeEnd);
void fileEmpty(); // làm cho file rỗng

#endif /* PvsP_hpp */
