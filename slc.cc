#include "slc.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

SLC::SLC(std::shared_ptr<Board> board,string name, int position) : Square{board, name, "", position, 0, nullptr, 0, false, false} {}

void SLC::action(shared_ptr<Player> player){
	srand (time(NULL)); 
	int val = rand() % 100 + 1;
	int oldpos = player->getPosition();
	if(val == 100 && getBoard()->getRollUpCards()!= 4){
		player->addTimCup();
		getBoard()->setRollUpCards(getBoard()->getRollUpCards()+1);
		cout << "got tim" << endl;
	}
	else{
		player->move(-2);

		val = rand() % 1000 + 1;
		
		if(val >= 1 && val < 126){
			cout << "Moved -3" << endl;
			player->move(-3);	
		}
		else if(val >= 126 && val < 292){
			// back 2
			cout << "Moved -2" << endl;
			player->move(-2);
		}
		else if(val >= 292 && val < 459){
			// back 1
			
			cout << "Moved back 1" << endl;
			player->move(-1);
		}
		else if(val >= 459 && val < 584){
			// forward 1
			cout << "Moved up 1" << endl;
			player->move(1);
		}
		else if(val >= 584 && val < 752){ 
			// forward 2 
			cout << "Moved up 2" << endl;
			player->move(2);  
		} 
		else if(val >= 752 && val < 918){   
			// forward 3
			cout << "Moved up 3" << endl;
			player->move(3);
		} 
		else if(val >= 918 && val < 960){  
			cout << "Moved to jail" << endl;
			player->setPosition(getBoard()->getSquares()[10]->getPosition());	
			player->setJail(true);
			player->setJailTurns(0);
		}
		else{
			cout << "Moved to osap" << endl;
			player->setPosition(getBoard()->getSquares()[0]->getPosition());	
		}
	}
	if (player->getPosition()<0){
		player->move(40);
	}
	if (player->getPosition()!=oldpos && player->getPosition()!=10){
		getBoard()->getSquares()[player->getPosition()]->action(player);
	}
	getBoard()->getSquares()[oldpos]->notifyObservers();
	getBoard()->getSquares()[player->getPosition()]->notifyObservers();
}

