#include "PlayBody.h"
#include "GameLib.h"
#include "RuleQuantity.h"
#include <iostream>
#include <thread>


PlayBody::PlayBody()
{
	m_score = 0;
	m_scene = new GameScene;
	gameOver = false;


	m_note1.setCoordNote(X0 + 1, 19);
	m_note2.setCoordNote(R1 + 1, 17);
	m_note3.setCoordNote(R2 + 1, 23);
	m_notePlay.push(3);
	m_notePlay.push(1);
	m_notePlay.push(2);
}


PlayBody::~PlayBody()
{
	delete m_scene;
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

	m_note1.drawNote();
	m_note2.drawNote();
	m_note3.drawNote();

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
	return (m_note1.checkNote() || m_note2.checkNote() || m_note3.checkNote());
}

void PlayBody::moveNotes(){
	
	m_note1.moveNote();
	m_note2.moveNote();
	m_note3.moveNote();

}

void PlayBody::playGame(){


	int k = 0;

	while (1){

		drawNotes();
		
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
					m_note1.deleteNote();
					m_note1.setCoordNote(X0 + 1, 17);
					m_notePlay.push(1);
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
					m_note2.deleteNote();
					m_note2.setCoordNote(R1 + 1, 17);
					m_notePlay.push(2);
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
					m_note3.deleteNote();
					m_note3.setCoordNote(R2 + 1, 17);
					m_notePlay.push(3);
				}
				else{
					gameOver = true;
					break;
				}

			}

			drawScore();

		}

		//------------------------

		Sleep(200);
		moveNotes();


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