#include "PlayBody.h"
#include "GameLib.h"
#include "RuleQuantity.h"
#include <iostream>
#include <thread>
#include <cstdio>


PlayBody::PlayBody()
{
	m_score = 0;
	m_scene = new GameScene;
	gameOver = false;

	head = NULL;


	m_note1.setCoordNote(X0 + 1, 19);
	m_note2.setCoordNote(R1 + 1, 17);
	m_note3.setCoordNote(R2 + 1, 23);
	push(R2 + 1, 23);
	m_notePlay.push(3);
	push(X0 + 1, 19);
	m_notePlay.push(1);
	push(R1 + 1, 17);
	m_notePlay.push(2);
}


PlayBody::~PlayBody()
{
	delete m_scene;
	remove();
}

void PlayBody::drawScore(){

	textcolor(12);
	gotoxy(XSCORE, YSCORE);
	std::cout << "Score: " << m_score;

}

void PlayBody::beginGame(){

	m_scene->drawScene();

}

void PlayBody::func1(){
	m_note1.drawNote();
}

void PlayBody::func2(){
	m_note2.drawNote();
}

void PlayBody::func3(){
	m_note3.drawNote();
}

void PlayBody::drawNotes(){

	/*m_note1.drawNote();
	m_note2.drawNote();
	m_note3.drawNote();*/

	Node *current = head;
	while (current != NULL){
		current->note.drawNote();
		current = current->next;
		//std::cout << "b";
	}

	/*std::thread f1( &func1 , this);
	std::thread f2( &func2 , this); 
	std::thread f3(&func3, this);

	f1.join();
	f2.join();
	f3.join();*/
	//fthread(this);

}

void ff1(PlayBody *pb){
	(pb->m_note1).drawNote();
}

void ff2(PlayBody *pb){
	(pb->m_note2).drawNote();
}

void ff3(PlayBody *pb){
	(pb->m_note3).drawNote();
}

void fthread(PlayBody *pb){
	std::thread f1(ff1, pb);
	std::thread f2(ff2, pb);
	std::thread f3(ff3, pb);

	f1.join();
	f2.join();
	f3.join();
}

bool PlayBody::checkNotes(){
	//return (m_note1.checkNote() || m_note2.checkNote() || m_note3.checkNote());
	Node *current = head;
	while (current != NULL){
		if (current->note.checkNote()) return true;
		current = current->next;
	}

	return false;
}

void PlayBody::moveNotes(){
	
	/*m_note1.moveNote();
	m_note2.moveNote();
	m_note3.moveNote();*/
	//std::cout << "aaaaaaaaaa";
	Node *current = head;
	while (current != NULL){
		current->note.moveNote();
		current = current->next;
		
	}
}

void PlayBody::playGame(){
	srand(time(NULL));

	int k = 0;

	while (1){

		drawNotes();
		Sleep(200);
		moveNotes();
		if (checkNotes()){
			gameOver = true;
			break;
		}
		// Process touch

		if (_kbhit()){

			char c = _getch();
			int need = m_notePlay.front();
			
			if (c == 'a' || c == 'A'){

				if (need == 1){
					m_score++;
					m_notePlay.pop();
					//m_note1.deleteNote();
					//m_note1.setCoordNote(X0 + 1, 17);
					pop();
					//push(X0 + 1, 17);
					//m_notePlay.push(1);
				}
				else{
					gameOver = true;
					break;
				}

			}

			if (c == 's' || c == 'S'){

				if (need == 2){
					m_score++;
					m_notePlay.pop();
					/*m_note2.deleteNote();
					m_note2.setCoordNote(R1 + 1, 17);*/
					pop();
					//push(R1 + 1, 17);
					//m_notePlay.push(2);
				}
				else{
					gameOver = true;
					break;
				}

			}

			if (c == 'd' || c == 'D'){

				if (need == 3){
					m_score++;
					m_notePlay.pop();
					/*m_note3.deleteNote();
					m_note3.setCoordNote(R2 + 1, 17);*/
					pop();
					//push(R2 + 1, 17);
					//m_notePlay.push(3);
				}
				else{
					gameOver = true;
					break;
				}

			}

			drawScore();

		}

		if (k % 2 == 0){
			int key = rand() % 3 + 1;

			if (key == 1){
				push(X0 + 1, 17);
				m_notePlay.push(1);
			}
			if (key == 2){
				push(R1 + 1, 17);
				m_notePlay.push(2);
			}
			if (key == 3){
				push(R2 + 1, 17);
				m_notePlay.push(3);
			}
		}
		//------------------------

		/*Sleep(200);
		moveNotes();*/


		k++;
		if (k > 50){
			k = 0;
		}
	}

	if (gameOver){

		gotoxy(Y0 - 4, X0 + 15);
		std::cout << "Game Over !";

	}

	std::cin.ignore(3);

}

void PlayBody::push(int x, int y){
	Node *addNode = new Node;
	addNode->note.setCoordNote(x, y);
	addNode->next = head;
	head = addNode;
}

void PlayBody::pop(){
	Node *current = head;
	if (current->next == NULL) return;
	while (current->next->next != NULL){

		current = current->next;

	}

	delete current->next;
	current->next = NULL;
}

int PlayBody::size(){

	int len = 0;
	Node *current = head;

	while (current != NULL){

		current = current->next;
		len++;

	}

	return len;

}

void PlayBody::remove(){

	int len = size();

	while (len){

		Node *current = head;

		for (int i = 0; i < len - 1; i++){
			current = current->next;
		}
		
		delete current;
		len--;

	}

	head = NULL;

}





















