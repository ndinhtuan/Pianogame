#include "NotePlay.h"
#include "GameLib.h"
#include <iostream>


NotePlay::NotePlay()
{
}


NotePlay::~NotePlay()
{
}

void NotePlay::drawNote(){

	textcolor(15);

	for (int j = y - NOTEHEIGHT; j <= y; j++){

		for (int i = x; i <= x + NOTEWIDTH; i++){

			gotoxy(i, j);
			std::cout << char(CHR);

		}

	}

}

void NotePlay::setCoordNote(int c_x, int c_y){

	x = c_x;
	y = c_y;

}

void NotePlay::deleteNote(){

	//textcolor(4);
	for (int j = y - NOTEHEIGHT; j <= y; j++){

		for (int i = x; i <= x + NOTEWIDTH; i++){

			gotoxy(i, j);
			std::cout << " ";

		}

	}

}

void NotePlay::moveNote(int step){

	deleteNote();
	y += step;

}

bool NotePlay::checkNote(){

	if (y >= YMAX) return true;
	return false;

}