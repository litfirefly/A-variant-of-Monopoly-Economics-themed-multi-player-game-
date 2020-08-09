#include <iostream>
#include <stdexcept>
#include <memory>
#include "board.h"
using namespace std;

int main(int argc, char* argv[]){
	cout << "Welcome to Watopoly" << endl;	
	shared_ptr<Board> game = make_shared<Board>();
	string load_file = "";
	bool testing = false;
	for (int i=0; i < argc; i++){
		string command = argv[i];
		if (command=="-testing"){
			testing=true;
		}
		else if (command=="-load"){
			if ((i+1)<argc){
				load_file = argv[i+1];
			}
		}
	}
	if (load_file!=""){
		cout << "You have loaded the file: " << load_file << endl;
		game->loadGame(load_file);
	}

	else{
		if (testing){
			cout << "You have started Watopoly in Testing Mode." << endl;
			game->setTesting();
		}
	
	
		cout << "How many players will be playing today?" << endl;
		int count_players = 0;
		string num = "";
		while(true){
			cin>>num;
			try{
				stoi(num);
				count_players = stoi(num);
			}
			catch(const invalid_argument& ia){
				cout << "Enter a number." << endl;
				continue;
			}
			if (count_players<2 || count_players>8){
				cout << "This is an invalid number of players. Their must be 2-8 players playing." << endl;
				continue;
			}
			break;
		}
		game->initialize(count_players);
		game->playTurn();
	}

	return 0;
}
