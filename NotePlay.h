#pragma once
#include "RuleQuantity.h"

#define NOTEWIDTH 7
#define NOTEHEIGHT 6

class NotePlay
{
private:
	// the coord of note
	int x;
	int y;
public:
	NotePlay();
	~NotePlay();

	// this function draw note music in game base on it's coord : x, y
	void drawNote();

	// this function set coord for note
	// @ parameter c_x is x of note 's coord
	// @ parameter c_y is y of note 's coord
	void setCoordNote(int c_x, int c_y);

	// this function move note down height = 3
	// @ parameter step is length of height , which note move
	void moveNote(int step = 6);

	// this function delete note in current coord.
	void deleteNote();

	// this function check note go out the side of body game
	// function return true if note go out, othewise.
	bool checkNote();
};

