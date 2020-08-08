#include "dcTimsLine.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

DCTimsLine::DCTimsLine(string &name, int position) : name{name}, position{position}, monopolyBlock{""}, ownable{false}, improvable{false} {}

void DCTimsLine::option(Player &player){
	while(true){
		cout << "Enter 'roll' to roll the die, 'pay' to pay the jail fee, or 'up' to use your Roll Up card" << endl;
		string playTurn;
		cin << playTurn;
	
		if(playTurn == "roll"){
			rollDice(player);
			break;
		}
		else if(playTurn == "pay"){
			if(player->money - 50 >= 0){
				payJailFee(player);
				break;
			}
			else{
				cout << "Please pick another option as you do not have enough funds to pay $50. Shame on you!" << endl;
			}
		}
		else if(playTurn == "up"){
			if(player->rollUp > 0){
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

void DCTimsLine::rollDice(Player &player){
	if(player->jailTurns == 2){
		payJailFee(player);
	}
	else{
		srand (time(NULL));
		int die1 = rand() % 6 + 1; 
		int die2 = rand() % 6 + 1;
		cout << "You rolled " << die1 << " & " << die2 << "." << endl;
		if(die1 == die2){
			player->inJail = false;
			player->jailTurns = -1;
			player->position = die1 + die2;
		}
		else{
			player->jailTurns++;
		}	
	}
}

void DCTimsLine::payJailFee(Player &player){
	srand (time(NULL));
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	cout << "You rolled " << die1 << " & " << die2 << "." << endl;
	if(die1 != die2){
		player->subtractMoney(jailFee);
	}
	if(!player->isBankrupt){
		player->inJail = false;
		player->jailTurns = -1;
		player->position = die1 + die2;
	}
}

void DCTimsLine::useRollUp(Player &player){
	player->rollUp--;
	player->inJail = false;
	player->jailTurns = -1;
}

string DCTimsLine::getName(){
        return name;
}

int DCTimsLine::getPosition(){
        return position;
}
bool DCTimsLine::getImprovable(){
        return improvable;
}
bool DCTimsLine::getOwnable(){
        return ownable;
}
