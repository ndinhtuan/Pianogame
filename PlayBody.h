#pragma once
#include "GameScene.h"
#include "NotePlay.h"
#include <conio.h>
#include <Windows.h>
#include <queue>

struct Node{
	NotePlay note;
	Node *next;
};

class PlayBody
{
private:
	Node *head;
	int m_score;
	std::queue<int> m_notePlay;
	//std::queue<NotePlay> m_notes;
	GameScene *m_scene;
	NotePlay m_note1;
	NotePlay m_note2;
	NotePlay m_note3;
	bool gameOver;
public:
	PlayBody();
	~PlayBody();

	// this function draw score 
	void drawScore();

	void beginGame();
	void playGame();

	void drawNotes();
	bool checkNotes();
	void moveNotes();

	//
	int size();
	void remove();
	void pop();
	void push(int x, int y);
	// thread
	void func1();
	void func2();
	void func3();
	friend void fthread(PlayBody *pb);
	friend void ff1(PlayBody *pb);
	friend void ff2(PlayBody *pb);
	friend void ff3(PlayBody *pb);
};

