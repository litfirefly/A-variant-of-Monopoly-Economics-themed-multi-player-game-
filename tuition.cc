#include "tuition.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Tuition::Tuition(std::shared_ptr<Board> board,string name, int position) : Square{board, name, "", position, 0, nullptr, 0, false, false} {}

void Tuition::action(shared_ptr<Player> player){
	int tenpercent = player->getWorth() * 0.1;
	cout << "Choose between paying $300 tuition or 10\% of your total worth (including your savings, printed prices of all buildings you own, and costs of each improvement)." << endl;
	cout << "Enter 'tuition' to pay using tuition and '10' to pay 10\% of your total worth." << endl;
	cout << "10\% of your worth is " << tenpercent << endl; 
	while(true){
		string command;
        	cin >> command;
	
        	if (cin.eof()) break;	

		if( command == "tuition" ){
			player->subtractMoney(300,getBoard()->getPlayers());
		}
		else if ( command == "10" ){
			player->subtractMoney(tenpercent, getBoard()->getPlayers());
		}
		else{
			cout << "Please enter a valid command" << endl;	
			continue;
		}
		break;
	}

}
