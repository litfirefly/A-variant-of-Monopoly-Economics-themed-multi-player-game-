#include "board.h"
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
#include "textdisplay.h"
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include<fstream>
#include <sstream>
#include <stdexcept>
//#include <bits/stdc++.h> 
using namespace std;

void Board::initSquares(){

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

void Board::initialize(int numOfPlayers){

	for(int i = 0; i < maxNumOfPlayers; i++){
		piecesChosen.push_back(false);
	}
	string name;
	string playerPiece;
	int i = 0;
	while(numOfPlayers != 0){
		while(true){
			cout << "Player " << i+1 << ": Enter your name: ";
                	cin>>name;
			if (name=="BANK"){
				cout << "Player cannot be named BANK" << endl;
				continue;
			}
			int currPlayers = playerList.size();
			bool taken=false;
			for (int i=0; i<currPlayers; i++){
				if (playerList[i]->getName()==name){
					cout << "Name already taken." << endl;
					taken = true;
					break;
				}
			}
			if(!taken)
				break;

		}
		cout << "Your options for pieces include (Type letter): " << endl;;


                for(int x = 0; x < maxNumOfPlayers; x++){
                        if(!piecesChosen[x])
                                cout << "\t" << pieces[x] << endl;
                }
		while(true){
                	cout << "Choose your piece: ";
 	                cin >> playerPiece;
        	        int counter = 0;
			int numOfPieces = pieces.size();
	                for(int y = 0; y < numOfPieces; y++){
        	                if(playerPiece[0] != pieces[y][0]){
                	                counter++;
                        	}
     	                   	else if(playerPiece[0] == pieces[y][0]){
        	                        piecesChosen[y] = true;
                	                counter = 0;
                	        }
               		}  
			if(counter == maxNumOfPlayers){  
  				cout << "This piece does not exist. Please select one of the available pieces." << endl;
                		continue;
			}
			break;
		}
		char piece_char = playerPiece[0];
                auto player = make_shared<Player>(piece_char, name,1500,0,0);
                playerList.push_back(player);
		numOfPlayers--;
		i++;        
	}
	
	initSquares();
	
	td = make_shared<TextDisplay>(shared_from_this());
	numOfPlayers = playerList.size();
	string waste;
	getline(cin,waste);
}


void Board::setTesting(){
	testMode = true;
}



void Board::trade(vector<string> command, int currPlayer){

      if (command.size() == 4) {
	      int index=-1;
	      int size = playerList.size();
	      for (int i=0; i<size; i++){
			if (playerList[i]->getName()==command[1]){
				index = i;
				break;
			}
	      }
	      if (index==-1){
			cout << "Player doesn't exist" << endl;
			return;
	      }
	      shared_ptr<Player> current = playerList[currPlayer];
	      shared_ptr<Player> other = playerList[index];
	      int value=-1;
	      value = stoi(command[3]);
	      
	      if (value>-1){

		     vector<shared_ptr<Square>> mySquares = current->getSquares();
		     int numPropOwned = mySquares.size();
	             int square_index=-1;
	      	     string accept="";
		     for (int i=0; i<numPropOwned; i++){
			if (mySquares[numPropOwned]->getName()==command[1]){
				square_index=i;
				break;
			}
		     }
		     if (square_index==-1){
				cout<<"You don't own this square." <<endl;
				return;
		     }
		     if (other->getMoney()<value){
				cout<<"The other player doesn't have enough money"<<endl;
				return;
		     }
		     cout << "Does " << command[3] << " accept the trade (type accept to accept)" << endl;
		     getline(cin,accept);
		     if (accept!="accept"){
			cout << command[3] << " has not accepted." << endl;
			return;
		     }
		    current->transferProperty(other, mySquares[square_index]);
		    other->subtractMoney(value, playerList);
		    current->addMoney(value);
	      		
		    return;
	      }

	      value = stoi(command[2]);
		
      	      if (value>-1){
                     
		     vector<shared_ptr<Square>> otherSquares = other->getSquares();
		     int numPropOwned = otherSquares.size();
	             int square_index=-1;
	      	     string accept="";
		     
		     for (int i=0; i<numPropOwned; i++){
                        if (otherSquares[numPropOwned]->getName()==command[2]){
                                square_index=i;
                                break;
                        }
                     }
                     if (square_index==-1){
                                cout<< command[3] << " doesn't own this square." <<endl;
                                return;
                     }
                     if (current->getMoney()<value){
                                cout<<"You don't have enough money"<<endl;
                                return;
                     }
                     cout << "Does " << command[3] << " accept the trade (type accept to accept)" << endl;
                     getline(cin,accept);
                     if (accept!="accept"){
                        cout << command[3] << " has not accepted." << endl;
                        return;
                     }
                    other->transferProperty(current, otherSquares[square_index]);
                    current->subtractMoney(value, playerList);
                    other->addMoney(value);

                    return;
              }


	
	      vector<shared_ptr<Square>> mySquares = current->getSquares();
              int numPropOwned = mySquares.size();
              int square_index=-1;
              string accept="";
              for (int i=0; i<numPropOwned; i++){
              	     if (mySquares[numPropOwned]->getName()==command[1]){
                          square_index=i;
                          break;
                     }
              }
              if (square_index==-1){
                        cout<<"You don't own this square." <<endl;
                        return;
              }  
	      vector<shared_ptr<Square>> otherSquares = other->getSquares();
              int numPropOwnedOther = otherSquares.size();
              int square_index_other=-1;
              for (int i=0; i<numPropOwnedOther; i++){
                     if (otherSquares[numPropOwnedOther]->getName()==command[2]){
                          square_index_other=i;
                          break;
                     }
              }
              if (square_index_other==-1){
                        cout<<command[3] <<" doesn't own this square." <<endl;
                        return;
              }

              cout << "Does " << command[3] << " accept the trade (type accept to accept)" << endl;
              getline(cin,accept);
              if (accept!="accept"){
                   cout << command[3] << " has not accepted." << endl;
                     return;
                   }
	      current->transferProperty(other, mySquares[square_index]);
              other->transferProperty(current,otherSquares[square_index_other]);
	      return;
      }
}



void Board::loadGame(string load){

	ifstream inp(load);
	string line = "";
	getline(inp, line);
	int numPlayers = stoi(line);
	if (numPlayers<2 || numPlayers>8){
		throw invalid_argument("Input file must have 2-8 players");
	}
	
	for (int i=0; i<numPlayers; i++){
		getline(inp, line);
		stringstream ss(line);
		string temp;
		vector<string> command;
		int currPlayers=i;
		while (ss >> temp){
			command.push_back(temp);
		}
		string player_name = command[0];
		if (player_name=="BANK"){
			throw invalid_argument("Player cannot be named Bank.");
		}
		for (int j=0; j<currPlayers; j++){
			if (playerList[j]->getName()==player_name){
				throw invalid_argument("A name is duplicated.");
			}
		}
		string player_piece = command[1];
		bool found=false;
		for (int j=0; j<maxNumOfPlayers; j++){
			if (pieces[j][0]==player_piece[0]){
				found = true;
			}	
		}
		if (!found){
			throw invalid_argument("This is not a valid piece.");
		}
		for (int j=0; j<currPlayers; j++){
			if (playerList[j]->getPiece()==player_piece[0]){
				throw invalid_argument("A piece is duplicated.");
			}
		}
		int cups = stoi(command[2]);
		if (cups+rollUpCards>4){
			throw invalid_argument("Too many Roll Up The Rims Cups");
		}
		int money = stoi(command[3]);
		if (money<0){
			throw invalid_argument("Cannot have negative money");
		}
		int jail = 0;
		int jailTurns = -1;
		int position = stoi(command[4]);
		if (position==30){
			throw invalid_argument("Cannot start on go to tims");
		}
		if (position==10){
			jail = stoi(command[5]);
			if (jail==1){
				jailTurns=stoi(command[6]);
				if (jailTurns<0 || jailTurns>2){
					throw invalid_argument("Jail turns must be between 0 and 2");
				}
			}
		}
                auto player = make_shared<Player>(player_piece[0], player_name, money,position,cups);
		if (jail==1){
			player->setJail(true);
			player->setJailTurns(jailTurns);
		}
                playerList.push_back(player);
		rollUpCards+=cups;
	}

	initSquares();
	int numSquares = squares.size();
	for (int i=0; i<numSquares; i++){
		getline(inp, line);
		stringstream ss(line);
		string temp;
		vector<string> command;
		while (ss >> temp){
			command.push_back(temp);
		}
		if (command[0]==squares[i]->getName()){
			string owner = command[1];
			if (owner!="BANK"){
				bool found = false;
				for (int j=0; j<numPlayers; j++){
					if (owner==playerList[j]->getName()){
						found = true;
						squares[i]->setOwner(playerList[j]);
						playerList[j]->addSquare(squares[i]);
						break;
					}
				}
				if(!found){
					throw invalid_argument("Not a valid owner");
				}
			}
			int improvements = stoi(command[2]);
			if (improvements<-1 || improvements>5){
				throw invalid_argument("Improvements must between -1(Mortgaged) and 5");
			}
			if ((improvements==-1 || improvements>0) && !(squares[i]->isOwnable())){
				throw invalid_argument("Improvements for not ownables properties must be 0.");
			}
			if (improvements>0 && !(squares[i]->isImprovable())){
				throw invalid_argument("Improvements for not improvable properties must be 0, or -1(mortgaged)");
			}
			squares[i]->setImprovementLevel(improvements);	
		}
	}
	playTurn();
}

void Board::saveGame(string filename){
	ofstream file;
	file.open(filename);
	int numPlayers = playerList.size();
	file << numPlayers << endl;
	for (int i=0; i<numPlayers; i++){
		auto player = playerList[i];
		string playerstring = "";
		playerstring+=player->getName()+" ";
		playerstring+=player->getPiece();
		playerstring+=" ";
		playerstring+=to_string(player->getTimCups()) + " ";
		playerstring+=to_string(player->getMoney()) + " ";
		playerstring+=to_string(player->getPosition());
		if (player->getPosition()==10){
			if(player->isInJail()){
				playerstring+=" 1 "+to_string(player->getJailTurns());
			}
			else{
				playerstring+=" 0";
			}
		}
		file << playerstring << endl;
	}
	vector<int> io;
	io.push_back(1);
	io.push_back(3);
	io.push_back(5);
	io.push_back(6);
	io.push_back(8);
	io.push_back(9);
	io.push_back(11);
	io.push_back(12);
	io.push_back(13);
	io.push_back(14);
	io.push_back(15);
	io.push_back(16);
	io.push_back(18);
	io.push_back(19);
	io.push_back(21);
	io.push_back(23);
	io.push_back(24);
	io.push_back(25);
	io.push_back(26);
	io.push_back(27);
	io.push_back(28);
	io.push_back(29);
	io.push_back(31);
	io.push_back(32);
	io.push_back(34);
	io.push_back(35);
	io.push_back(37);
	io.push_back(39);
	int numOwnable = io.size();
	for (int i=0; i<numOwnable; i++){
		auto square = squares[io[i]];
		string square_string = square->getName();
		if (square->getOwner()){
			square_string += " " + square->getOwner()->getName();
		}
		else{
			square_string += " BANK";
		}
		if (square->isMortgaged()){
			square_string += " -1";
		}
		else{
			square_string += " " + to_string(square->getImprovementLevel());
		}
		file << square_string << endl;

	}
	file.close();	
	cout << "Saved to " << filename << "." << endl;
}

void Board::displayOption(shared_ptr<Player> player){
	cout << "It is now " << player->getName() << "'s turn. These are your options: " << endl;
	if (player->isInJail()){
		cout << "\t next (will end your turn)" << endl;;
	}
	else{
		if(testMode){
			cout << "\t roll <die1> <die2> (will end your turn)" << endl;
		}
		cout << "\t roll (will end your turn)" << endl;
	}
	cout << "\t trade <name> <property> <money>" << endl;
	cout << "\t trade <name> <property> <property>" << endl;
	cout << "\t trade <name> <money> <property>" << endl;
	cout << "\t improve <property> buy/sell" << endl;
	cout << "\t mortgage <property>" << endl;
	cout << "\t unmortgage <property>" << endl;
	cout << "\t assets" << endl;
	cout << "\t all" << endl;
	cout << "\t save <filename>" << endl;
	cout << "\t quit" << endl;
}

void Board::playTurn(){
	int currPlayer = 0;
	string line = "";
	bool ended = false;
	td->print();
	displayOption(playerList[currPlayer]);
	cout << "Enter Input: " << endl;
	while(!ended){
		getline(cin, line);
		stringstream ss(line);
		string temp;
		vector<string> command;
		
		while (ss >> temp){
			command.push_back(temp);
		}
		if(command.size()<1){
			continue;
		}
		if (command[0]=="quit"){
			ended=true;
			break;
		}
		else if(command[0] == "roll"){
			if ((playerList[currPlayer]->isInJail())){
				cout << "You are not eligible to roll, and this command is invalid. Use next, to end you turn. " << endl;
				continue;
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
				cout << "You rolled " << roll[0] << " and " << roll[1] << "." << endl;
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
			playerList[currPlayer]->move(totalRoll);
			td->print();
			while(playerList[currPlayer]->getPosition() > 40){
				playerList[currPlayer]->move(-40);
				squares[0]->action(playerList[currPlayer]);
			}
			cout << "You landed on: " << squares[playerList[currPlayer]->getPosition()]->getName() << endl;
			if ((playerList[currPlayer]->getPosition()!=0)&&(playerList[currPlayer]->getPosition()!=10)){
				squares[playerList[currPlayer]->getPosition()]->action(playerList[currPlayer]);
			}
		
		

			if (playerList[currPlayer]->isBankrupt()){
				cout << "You have been bankrupted, your piece will now be removed." << endl;
				numOfPlayers--;
				playerList.erase(playerList.begin()+currPlayer);
				if (numOfPlayers==1){
					cout << "The game is now over. The winner is " << playerList[0]->getName() << "." << endl;
					cout << "The game is now over. The winner is " << playerList[0]->getName() << "." << endl;
					cout << "The game is now over. The winner is " << playerList[0]->getName() << "." << endl;
					ended=true;
				}
			}
			
			while(totalRoll > 40){
				totalRoll -= 40;
				squares[0]->action(playerList[currPlayer]);
			}
			currPlayer++;
			int numPlayers = playerList.size();
			if(currPlayer>=numPlayers){
				currPlayer=0;
			}
			cout << "It is now the next player's turn" << endl;
			displayOption(playerList[currPlayer]);
			cout << "Enter Input: " << endl;
		}		
		else if(command[0] == "next"){
			if (!(playerList[currPlayer]->isInJail())){
				cout << "You are eligible to roll, and this command is invalid. " << endl;
				continue;
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
			int numPlayers = playerList.size();
			if(currPlayer>=numPlayers){
				currPlayer=0;
			}
			cout << "It is now the next player's turn" << endl;
			displayOption(playerList[currPlayer]);
		}	
		else if(command[0] == "improve"){
			string property = command[1];
			int numSquares=squares.size();
			for(int i = 0; i < numSquares; i++){
				auto academicProperty = squares[i];
				cout << "Right" << endl;
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
					}	
					break;
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
			int numPlayers=playerList.size();
			for(int i = 0; i < numPlayers; i++){
	                        playerList[i]->printPlayerAssets();
				cout << endl;
			}
                        
                }
		else if (command[0] == "trade"){
			trade(command, currPlayer);
		}
		else if (command[0]=="save"){
			saveGame(command[1]);
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
