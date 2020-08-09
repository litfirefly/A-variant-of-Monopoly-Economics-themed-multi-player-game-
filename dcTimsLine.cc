#include "dcTimsLine.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


DCTimsLine::DCTimsLine(std::shared_ptr<Board> board,string name, int position) : Square{board, name, "", position, -1, nullptr, -1, false, false} {}

void DCTimsLine::action(shared_ptr<Player> player){
	while(true){
		cout << "Enter 'roll' to roll the die, 'pay' to pay the jail fee, or 'up' to use your Roll Up card" << endl;
		string playTurn;
		cin >> playTurn;
	
		if(playTurn == "roll"){
			rollDice(player);
			break;
		}
		else if(playTurn == "pay"){
			if(player->getMoney() - 50 >= 0){
				payJailFee(player);
				break;
			}
			else{
				cout << "Please pick another option as you do not have enough funds to pay $50. Shame on you!" << endl;
			}
		}
		else if(playTurn == "up"){
			if(player->getTimCups() > 0){
				useRollUp(player);
				break;
			}
			else{
				cout << "Please pick another option as you do not own a Roll Up card!" << endl;
			}
		}
		else{
			cout << "Invalid option. Please choose one of the options given." << endl;
		}		
	}
}

void DCTimsLine::rollDice(shared_ptr<Player> player){
	if(player->getJailTurns() == 2){
		payJailFee(player);
	}
	else{
		srand (time(NULL));
		int die1 = rand() % 6 + 1; 
		int die2 = rand() % 6 + 1;
		cout << "You rolled " << die1 << " & " << die2 << "." << endl;
		if(die1 == die2){
			player->setJail(false);
			player->setJailTurns(-1);
			player->move(die1 + die2);
		}
		else{
			player->setJailTurns(player->getJailTurns()+1);
		}	
	}
}

void DCTimsLine::payJailFee(shared_ptr<Player> player){
	srand (time(NULL));
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	cout << "You rolled " << die1 << " & " << die2 << "." << endl;
	if(die1 != die2){
		player->subtractMoney(jailFee, getBoard()->getPlayers());
	}
	if(!player->isBankrupt()){
		player->setJail(false);
		player->setJailTurns(-1);
		player->move(die1 + die2);
	}
}

void DCTimsLine::useRollUp(shared_ptr<Player> player){
	player->useTimCup();
	getBoard()->setRollUpCards(getBoard()->getRollUpCards()-1);
	player->setJail(false);
	player->setJailTurns(-1);
}


