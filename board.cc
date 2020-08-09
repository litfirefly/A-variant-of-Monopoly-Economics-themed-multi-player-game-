#include "board.h"
#include "player.h"
#include "square.h"
#include "textdisplay.h"
#include "academic.h"
#include "coop.h"
#include "dcTimsLine.h"
#include "goosenesting.h"
#include "goToTims.h"
#include "gym.h"
#include "needleshall.h"
#include "osap.h"
#include "residences.h"
#include "slc.h"
#include "tuition.h"
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
//#include <bits/stdc++.h> 
using namespace std;

void Board::initialize(int numOfPlayers){
	for(int i = 0; i < maxNumOfPlayers; i++){
		piecesChosen[i] = false;
	}
	string name;
	string playerPiece;
	int i = 0;
	while(numOfPlayers != 0){
		cout << "Player " << i << ": Enter your name: ";
                cin >>  name;
                cout << "Your options for pieces include: ";
                for(int x = 0; x < maxNumOfPlayers; x++){
                        if(!piecesChosen[x])
                                cout << "\t" << pieces[x] << endl;
                }
                cout << "Choose your piece: ";
                cin >> playerPiece;
                int counter = 0;
		int numOfPieces = pieces.size();
                for(int y = 0; y < numOfPieces; y++){
                        if(playerPiece != pieces[y]){
                                counter++;
                        }
                        else if(playerPiece == pieces[y]){
                                piecesChosen[y] = true;
                                counter = 0;
                        }
                }  
		if(counter == maxNumOfPlayers){  
  			cout << "This piece does not exist. Please select one of the available pieces." << endl;
                }
                else{
			char piece_char = playerPiece[0];
                        auto player = make_shared<Player>(piece_char, name,1500,0,0);
                        playerList.push_back(player);
			numOfPlayers--;
			i++;
                }
	}
	squares.push_back(make_shared<Osap>(shared_from_this(), "Osap", 0));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "AL", "Arts1", 1, 40, nullptr, 0, 50, AL, false));
	squares.push_back(make_shared<SLC>(shared_from_this(), "SLC", 2));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "ML", "Arts1", 3, 60, nullptr, 0, 50, ML, false));
	squares.push_back(make_shared<Tuition>(shared_from_this(), "Tuition", 4));
	squares.push_back(make_shared<Residences>(shared_from_this(), "MKV", 5, nullptr, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "ECH", "Arts2", 6 , 100, nullptr, 0, 50, ECH, false));
	squares.push_back(make_shared<NeedlesHall>(shared_from_this(), "Needles Hall", 7));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "PAS", "Arts2", 8, 100, nullptr, 0, 50, PAS, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "HH", "Arts2", 9, 120, nullptr, 0, 50, HH, false));
	squares.push_back(make_shared<DCTimsLine>(shared_from_this(), "DC Tims Line", 10));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "RCH", "Eng", 11, 140, nullptr, 0, 100, RCH, false));
	squares.push_back(make_shared<Gym>(shared_from_this(), "PAC", 12, nullptr, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "DWE", "Eng", 13, 140, nullptr, 0, 100, DWE, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "CPH", "Eng", 14, 160, nullptr, 0, 100, CPH, false));
	squares.push_back(make_shared<Residences>(shared_from_this(), "CPH", 15, nullptr, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "LHI", "Health", 16, 180, nullptr, 0, 100, LHI, false));
	squares.push_back(make_shared<SLC>(shared_from_this(), "SLC", 17));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "BMH", "Health", 18, 180, nullptr, 0, 100, BMH, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "OPT", "Health", 19, 200, nullptr, 0, 100, OPT, false));
	squares.push_back(make_shared<GooseNesting>(shared_from_this(), "Goose Nesting", 20));		
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "EV1", "Env", 21, 220, nullptr, 0, 150, EV1, false));
	squares.push_back(make_shared<NeedlesHall>(shared_from_this(), "Needles Hall", 22));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "EV2", "Env", 23, 220, nullptr, 0, 150, EV2, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "EV3", "Env", 24, 240, nullptr, 0, 150, EV3, false));
	squares.push_back(make_shared<Residences>(shared_from_this(), "V1", 25, nullptr, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "PHYS", "Sci1", 26, 260, nullptr, 0, 150, PHYS, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "B1", "Sci1", 27, 260, nullptr, 0, 150, B1, false));
	squares.push_back(make_shared<Gym>(shared_from_this(), "CIF", 28, nullptr, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "B2", "Sci1", 29, 280, nullptr, 0, 150, B2, false));
	squares.push_back(make_shared<GoToTims>(shared_from_this(), "Go To Tims", 30));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "EIT", "Sci2", 31, 300, nullptr, 0, 200, EIT, false));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "ESC", "Sci2", 32, 300, nullptr, 0, 200, ESC, false));
	squares.push_back(make_shared<SLC>(shared_from_this(), "SLC", 33));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "C2", "Sci2", 34, 320, nullptr, 0, 200, C2, false));
	squares.push_back(make_shared<Residences>(shared_from_this(), "REV", 35, nullptr, false));
	squares.push_back(make_shared<NeedlesHall>(shared_from_this(), "Needles Hall", 36));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "MC", "Math", 37, 350, nullptr, 0, 200, MC, false));
	squares.push_back(make_shared<Coop>(shared_from_this(), "Co-op Fee", 38));
	squares.push_back(make_shared<AcademicProperty>(shared_from_this(), "DC", "Math", 39, 400, nullptr, 0, 200, DC, false));
}


void Board::setTesting(){
	testMode = true;
}



void Board::trade(vector<string> command){
	//All three types of trades are possible
}

void Board::loadGame(string load){

}

string Board::saveGame(){
	return "fix";
}



void Board::playTurn(){
	int currPlayer = 0;
	string line = "";
	while(true){
		stringstream ss(line);
		string temp;
		vector<string> command;

		while (ss >> temp){
			command.push_back(temp);
		}
		if(command[0] == "roll"){
			if ((playerList[currPlayer]->isInJail())){
				cout << "You are not eligible to roll, and this command is invalid. Use next, to end you turn. " << endl;
			}
			vector<int> roll;
			int totalRoll;
			while(true){
				if(!testMode)
					roll=rollDice(-1, -1);
				else{
					if(command.size()==3 || command[1] != "" || command[2] != ""){
						rollDice(stoi(command[1]), stoi(command[2]));
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
				squares[0]->action(playerList[currPlayer]);
			}
			
			squares[playerList[currPlayer]->getPosition()]->action(playerList[currPlayer]);
		
		

			if (playerList[currPlayer]->isBankrupt()){
				cout << "You have been bankrupted, your piece will now be removed." << endl;
				numOfPlayers--;
				playerList.erase(playerList.begin()+currPlayer);
				if (numOfPlayers==1){
					cout << "The game is now over. The winner is " << playerList[0]->getName() << "." << endl;
					cout << "The game is now over. The winner is " << playerList[0]->getName() << "." << endl;
					cout << "The game is now over. The winner is " << playerList[0]->getName() << "." << endl;
				}
			}
			
			while(totalRoll > 40){
				totalRoll -= 40;
				squares[0]->action(playerList[currPlayer]);
			}
			
			currPlayer++;
			if(currPlayer>=numOfPlayers){
				currPlayer=0;
			}
			cout << "It is now the next player's turn" << endl;
		}		
		else if(command[0] == "next"){
			if (!(playerList[currPlayer]->isInJail())){
				cout << "You are eligible to roll, and this command is invalid. " << endl;
			}
			else{
				squares[playerList[currPlayer]->getPosition()]->action(playerList[currPlayer]);
				if(currPlayer == numOfPlayers - 1){
					currPlayer = 0;
				}
				else
					currPlayer++;
			}

			currPlayer++;
			if(currPlayer>=numOfPlayers){
				currPlayer=0;
			}
			cout << "It is now the next player's turn" << endl;
		}	
		else if(command[0] == "improve"){
			string property = command[1];
			int numSquares=squares.size();
			for(int i = 0; i < numSquares; i++){
				auto academicProperty = squares[i];
				if(academicProperty->getName() == property && academicProperty->isImprovable()){
					if(command[2] == "sell"){
						academicProperty->improveSell(playerList[currPlayer]);
						break;
					}
					else if(command[2] == "buy"){
						academicProperty->improveBuy(playerList[currPlayer]);
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
			int numSquares = squares.size();
                        for(int i = 0; i < numSquares; i++){     
				auto square = squares[i];   
					if(square->getName() == property && !square->isMortgaged() && 
						playerList[currPlayer]->getName() == square->getOwner()->getName()){			  
						square->mortgage(playerList[currPlayer]);
						break;
					}
                                        else{
                                                cout << "Invalid command. Please enter one of the commands given." << endl;                                                                                               		     break;
				       	}
			}	
		}
		else if(command[0] == "unmortgage"){
                        string property = command[1];
			int numSquares = squares.size();
                        for(int i = 0; i < numSquares; i++){
                                auto square = squares[i];
                                if(square->getName() == property && square->isMortgaged() && playerList[currPlayer]->getName() == square->getOwner()->getName()){
                                	square->unmortgage(playerList[currPlayer]); 
					break;      
				}
				else{ 
					cout << "Invalid command. Please enter one of the commands given." << endl;  
					break;    
				}
                           
                        }
                }
		else if(command[0] == "assets"){
			playerList[currPlayer]->printPlayerAssets();
			
		}
		else if(command[0] == "all"){ 
			for(int i = 0; i < numOfPlayers; i++){
	                        playerList[i]->printPlayerAssets();
			}
                        
                }
		else if (command[0] == "trade"){
			trade(command);
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

std::vector<std::shared_ptr<Player>> Board::getPlayers(){
	return playerList;
}

std::vector<std::shared_ptr<Square>> Board::getSquares(){
	return squares;
}

int Board::getRollUpCards(){
	return rollUpCards;
}
void Board::setRollUpCards(int cards){
	rollUpCards=cards;
}
