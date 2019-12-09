
#ifndef PvsP_hpp
#define PvsP_hpp

#include "BackGround.hpp"
#include "Ball.hpp"
#include "rewardItem.h"
#include "Paddle.hpp"
#include "buildStage.hpp"
#include "BallsHandler.h"
#include <thread>
#include <future>

bool pauseGame(sf::RenderWindow& window, ThePong &ball, BackGround &bg, TheBar &bar, buildStage &stage, TextShow &text);
int EndGame(sf::RenderWindow& window, buildStage &stage, int score);
int play(sf::RenderWindow& window); // người với người chơi

#endif /* PvsP_hpp */
