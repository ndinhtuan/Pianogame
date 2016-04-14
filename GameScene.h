#pragma once
#include "RuleQuantity.h"

class GameScene
{
private:
	int width;
	int height;
public:
	GameScene();
	~GameScene();

	// this function creat body for game scene
	void createScene();

	// this function draw scene of game.
	void drawScene();

	// this function decorate for Background of game
	void decorateScene();

	// this function draw score in game 's background
	// @ parameter score is current score.
	void drawScore(int score);
};

