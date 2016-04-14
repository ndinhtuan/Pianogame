#include "PlayBody.h"
#include <conio.h>

int main(){
	PlayBody game;
	game.beginGame();
	game.playGame();
	_getch();
	return 0;
}