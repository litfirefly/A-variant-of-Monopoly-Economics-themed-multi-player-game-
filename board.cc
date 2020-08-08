#include "board.h"
#include "player.h"
#include "square.h"
// Include all other squares
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void Board::initialize(int numOfPlayers){
	for(int i = 0; i < maxNumOfPlayers; i++){
		piecesChosen[i] = false;
	}
	string name;
	string playerPiece;
	int counter = numOfPlayers;
	int i = 0;
	while(numOfPlayers != 0){
		cout << "Player " << i << ": Enter your name: ";
                cin << name;
                cout << "Your options for pieces include: ";
                for(int x = 0; x < maxNumOfPlayers; x++){
                        if(!piecesChosen[x])
                                cout << "\t" << pieces[x] << endl;
                }
                cout << "Choose your piece: ";
                cin << playerPiece;
                int counter = 0;
                for(int y = 0; y < maxNumOfPlayers; y++){
                        if(playerPiece != pieces[y]){
                                counter++;
                        }
                        else if(playerPiece == pieces[y]){
                                piecesChosen[y] = true;
                                counter = 0;
                        }
                }                                                                                                                                                                           if(counter == maxNumOfPlayers){
                        cout << "This piece does not exist. Please select one of the available pieces." << endl;
                }
                else{
                        auto player = make_shared<Player>(playerPiece, name);
                        playerList.push_back(player);
			numOfPlayers--;
			i++;
                }
	}

	squares.push_back(make_shared<Osap>("Osap", 0));
	squares.push_back(make_shared<AcademicProperty>("AL", "Arts1", 1, 40, nullptr, 0, 50, AL, false));
	squares.push_back(make_shared<SLC>("SLC", 2));
	squares.push_back(make_shared<AcademicProperty>("ML", "Arts1", 3, 60, nullptr, 0, 50, ML, false));
	squares.push_back(make_shared<Tuition>("Tuition", 4));
	squares.push_back(make_shared<Residences>("MKV", 5));
	squares.push_back(make_shared<AcademicProperty>("ECH", "Arts2", 6 , 100, nullptr, 0, 50, ECH, false));
	squares.push_back(make_shared<NeedlesHall>("Needles Hall", 7));
	squares.push_back(make_shared<AcademicProperty>("PAS", "Arts2", 8, 100, nullptr, 0, 50, PAS, false));
	squares.push_back(make_shared<AcademicProperty>("HH", "Arts2", 9, 120, nullptr, 0, 50, HH, false));
	squares.push_back(make_shared<DCTimsLine>("DC Tims Line", 10));
	squares.push_back(make_shared<AcademicProperty>("RCH", "Eng", 11, 140, nullptr, 0, 100, RCH, false));
	squares.push_back(make_shared<Gym>("PAC", 12));
	squares.push_back(make_shared<AcademicProperty>("DWE", "Eng", 13, 140, nullptr, 0, 100, DWE, false));
	squares.push_back(make_shared<AcademicProperty>("CPH", "Eng", 14, 160, nullptr, 0, 100, CPH, false));
	squares.push_back(make_shared<Residences>("CPH", 15));
	squares.push_back(make_shared<AcademicProperty>("LHI", "Health", 16, 180, nullptr, 0, 100, LHI, false));
	squares.push_back(make_shared<SLC>("SLC", 17));
	squares.push_back(make_shared<AcademicProperty>("BMH", "Health", 18, 180, nullptr, 0, 100, BMH, false));
	squares.push_back(make_shared<AcademicProperty>("OPT", "Health", 19, 200, nullptr, 0, 100, OPT, false));
	squares.push_back(make_shared<GooseNesting>("Goose Nesting", 20));		
	squares.push_back(make_shared<AcademicProperty>("EV1", "Env", 21, 220, nullptr, 0, 150, EV1, false));
	squares.push_back(make_shared<NeedlesHall>("Needles Hall", 22));
	squares.push_back(make_shared<AcademicProperty>("EV2", "Env", 23, 220, nullptr, 0, 150, EV2, false));
	squares.push_back(make_shared<AcademicProperty>("EV3", "Env", 24, 240, nullptr, 0, 150, EV3, false));
	squares.push_back(make_shared<Residences>("V1", 25));
	squares.push_back(make_shared<AcademicProperty>("PHYS", "Sci1", 26, 260, nullptr, 0, 150, PHYS, false));
	squares.push_back(make_shared<AcademicProperty>("B1", "Sci1", 27, 260, nullptr, 0, 150, B1, false));
	squares.push_back(make_shared<Gym>("CIF", 28));
	squares.push_back(make_shared<AcademicProperty>("B2", "Sci1", 29, 280, nullptr, 0, 150, B2, false));
	squares.push_back(make_shared<GoToTims>("Go To Tims", 30));
	squares.push_back(make_shared<AcademicProperty>("EIT", "Sci2", 31, 300, nullptr, 0, 200, EIT, false));
	squares.push_back(make_shared<AcademicProperty>("ESC", "Sci2", 32, 300, nullptr, 0, 200, ESC, false));
	squares.push_back(make_shared<SLC>("SLC", 33));
	squares.push_back(make_shared<AcademicProperty>("C2", "Sci2", 34, 320, nullptr, 0, 200, C2, false));
	squares.push_back(make_shared<Residences>("REV", 35));
	squares.push_back(make_shared<NeedlesHall>("Needles Hall", 36));
	squares.push_back(make_shared<AcademicProperty>("MC", "Math", 37, 350, nullptr, 0, 200, MC, false));
	squares.push_back(make_shared<Coop>("Co-op Fee", 38));
	squares.push_back(make_shared<AcademicProperty>("DC", "Math", 39, 400, nullptr, 0, 200, DC, false));
}

void Board::setTesting(int numOfPlayers){
	testMode = true;
}

void Board::playTurn(){
	int currPlayer = 0;
	while(true){
		stringstream ss(line);
		string temp;
		vector<string> command;

		while (ss >> temp){
			command.push_back(temp);
		}
		if(command[0] == roll){
			vector<int> roll;
			int totalRoll;
			while(true){
				if(!testMode)
					roll = rollDice(-1, -1);
				else{
					if(command[1] != "" || command[2] != ""){
						rollDice(command[1], command[2]);
					}
					else{
						roll = rollDice(-1, -1);
					}
				}
				totalRoll = roll[0] + roll[1];
				if(roll[0] != roll[1]){
					break;
				}
				else{
					cout << "You rolled doubles." << endl;
					if(testMode){
						cout << "You are in testing mode. Please enter the following command again: roll <die1> <die2>." << endl;
						while(ss >> temp){
							command.push_back(temp);
						}
					}
				}
			}
			while(totalRoll > 40){
				totalRoll -= 40;
				collectOSAP(players[currPlayer]);
			}
			square[totalRoll]->action(players[currPlayer]);
		}		
		else if(command[0] == "next"){
			if(currPlayer == numOfPlayers - 1){
				currPlayer = 0;
			}
			else
				currPlayer++;
		}	
		else if(command[0] == "improve"){
			string property = command[1];
			for(int i = 0; i < squares.size(); i++){
				auto academicProperty = squares[i];
				if(academicProperty->getName() == property && academicProperty->getImprovable()){
					if(command[2] == "sell"){
						improveSell(players[currPlayer]);
						break;
					}
					else if(command[2] == "buy"){
						improveBuy(players[currPlayer]);
					}
					else{
						cout << "Invalid command. Please enter one of the commands given." << endl;
						break;
					}	
				}
			}
		}
		else if(command[0] == "mortgage"){
			string property = command[1];
                        for(int i = 0; i < squares.size(); i++){     
				auto academicProperty = squares[i];   
					if(academicProperty->getName() == property && !academicProperty->isMortgaged() && players[currPlayer]->getName() == academicProperty->owner->getName()){			  
						mortgage(players[currPlayer]);
						break;
					}
                                        else{
                                                cout << "Invalid command. Please enter one of the commands given." << endl;                                                                                                 break;                                                                                                                                                              }
                                }
                        }	
		}
		else if(command[0] == "unmortgage"){
                        string property = command[1];
                        for(int i = 0; i < squares.size(); i++){
                                auto academicProperty = squares[i];
                                if(academicProperty->getName() == property && academicProperty->isMortgaged() && players[currPlayer]->getName() == academicProperty->owner->getName()){
                                	unmortgage(players[currPlayer]); 
					break;      
				}
				else{ 
					cout << "Invalid command. Please enter one of the commands given." << endl;  
					break;    
				}
                           
                        }
                }
		else if(command[0] == "assets"){
			const int tuitionSquare = 4;
			if(players[currPlayer]->getPos() == tuitionSquare){
				cout << "Sorry, this cannot be done!" << endl;
			}
			else{
				players[currPlayer]->printPlayerAssets();
			}
		}
		else if(command[0] == "all"){ 
			const int tuitionSquare = 4;
			bool playerOnTuition = false;
			for(int i = 0; i < numOfPlayers; i++){
				if(players[i]->getPos() == tuitionSquare){ 
					cout << "Sorry, this cannot be done!" << endl;
					playerOnTuition = true;
					break;
                        	}
			}
			if(!playerOnTuition){
				for(int i = 0; i < numOfPlayers; i++){
	                        	players[i]->printPlayerAssets();
				}
                        }
                }
	}

}

vector<int> Board::rollDice(int die1, int die2){
	if(!testMode){
		srand (time(NULL));
        	die1 = rand() % 6 + 1;
		die2 = rand() % 6 + 1;
	}
	vector<int> rolls = {die1, die2};	
	return rolls;
}
