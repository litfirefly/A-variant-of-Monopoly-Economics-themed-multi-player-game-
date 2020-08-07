#include "tuition.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Tuition::Tuition(string &name, int position) : Square{name, "", position, -1, nullptr, -1, false, false} {}

void Tuition::payTuition(Player &player){
	int 10percent = player->getWorth() * 0.1;
	cout << "Choose between paying $300 tuition or 10\% of your total worth (including your savings, printed prices of all buildings you own, and costs of each improvement)." << endl;
	cout << "Enter 'tuition' to pay using tuition and '10' to pay 10\% of your total worth." << endl;
	cout << "10\% of your worth is " << 10percent << endl; 
	while(true){
		string command;
        	cin >> command;
	
        	if (cin.eof()) break;	

		if( command == "tuition" ){
			player->subtractMoney(300);
		}
		else if ( command == "10" ){
			player->subtractMoney(10percent);
		}
		else{
			cout << "Please enter a valid command" << endl;	
			continue;
		}
		break;
}

}
