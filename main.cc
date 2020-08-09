#include <iostream>
#include "board.h"
using namespace std;

int main(int argc, char* argv[]){
	cout << "Welcome to Watopoly" << endl;	
	Board game;
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
		game.loadGame(load_file);
	}

	else{
		if (testing){
			cout << "You have started Watopoly in Testing Mode." << endl;
			game.setTesting();
		}
	
	
		cout << "How many players will be playing today?" << endl;
		int count_players = 0;
		while(true){
			cin>>count_players;
			if (count_players<2 || count_players>8){
				cout << "This is an invalid number of players. Their must be 2-8 players playing." << endl;
				continue;
			}
			break;
		}
		game.initialize(count_players);
		game.playTurn();
	}

	return 0;
}
