#include "tuition.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Tuition::Tuition(string &name, int position) : name{name}, position{position}, monopolyBlock{""}, ownable{false}, improvable{false} {}

void Tuition::payTuition(Player &player){
	cout << "Choose between paying $300 tuition or 10\% of your total worth (including your savings, printed prices of all buildings you own, and costs of each improvement)." << endl;
	cout << "Enter 'tuition' to pay using tuition and '10' to pay 10\% of your total worth." << endl;

	string command;
        cin >> command;

        if (cin.eof()) break;	

	if( command == "tuition" ){
		player->subtractMoney(300);
	}
	else if ( command == "10" ){
		// Create a getSavings() function in player class
		int money = player->getSavings() * 0.1;
		player->subtractMoney(money);
	}
	else{
		// throw exception that calls this function again
	}
}

string Tuition::getName(){
        return name;
}

int Tuition::getPosition(){
        return position;
}
bool Tuition::getImprovable(){
        return improvable;
}
bool Tuition::getOwnable(){
        return ownable;
}
