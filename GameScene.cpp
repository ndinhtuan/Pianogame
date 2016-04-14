#include "GameScene.h"
#include "GameLib.h"
#include <iostream>


GameScene::GameScene()
{
	width = 800;
	height = 800;
}

GameScene::~GameScene()
{
}

void GameScene::createScene(){

	int color = 6;

	textcolor(color);

	for (int i = Y0; i <= YMAX; i++){

		gotoxy(X0, i);
		std::cout << char(CHR);

		gotoxy(XMAX, i);
		std::cout << char(CHR);

		gotoxy(R1, i);
		std::cout << char(CHR);

		gotoxy(R2, i);
		std::cout << char(CHR);

	}

	for (int i = X0; i <= XMAX; i++){

		gotoxy(i, Y0);
		std::cout << char(CHR);

		gotoxy(i, YMAX);
		std::cout << char(CHR);

	}
}

// this function draw some image to decorate for Background of game
// @ parameter x is x axis of image center
// @ parameter y is y axis of image center
// @ parameter color is image 's color
void drawImageDecorate(int x, int y, int color){

	textcolor(color);

	gotoxy(x, y - 1);
	std::cout << char(CHR);
	gotoxy(x, y + 1);
	std::cout << char(CHR);
	gotoxy(x, y);
	std::cout << char(CHR);
	gotoxy(x - 1, y);
	std::cout << char(CHR);
	gotoxy(x + 1, y);
	std::cout << char(CHR);
}

void GameScene::decorateScene(){

	drawImageDecorate(10, 10, 4);
	drawImageDecorate(15, 15, 4);
	drawImageDecorate(19, 6, 4);

	drawImageDecorate(55, 10, 4);
	drawImageDecorate(60, 15, 4);
	drawImageDecorate(62, 6, 4);

}

void GameScene::drawScene(){

	resizeConsole(width, height);
	decorateScene();
	createScene();
	drawScore(7);

}

void GameScene::drawScore(int score){

	textcolor(12);
	gotoxy(XSCORE, YSCORE);
	std::cout << "Score : " << score;

}