#include "player.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

Player::Player(char piece, std::string name, int money, int position, int timCups): piece{piece}, name{name}, position{position}, inJail{false}, jailTurns{-1}, 
	bankrupt{false}, money{money}, numOfResidences{0}, numOfGyms{0}, timCups{timCups}{}

void Player::printPlayerAssets(){
	cout << "Name: " << name << endl;
	cout << "Piece: " << piece << endl;
	cout << "Position: " << position << endl;
	if (inJail){
		cout << "Jail: " << jailTurns << " turns left" <<  endl;
	}
	else{
		cout << "Jail: Not in Jail" << endl;
	}

	if (bankrupt){
		cout << "Money: Is Bankrupt" << endl;
	}
	else{
		cout << "Money: $" << money << endl;
	}
	int size=squaresOwned.size();
	for (int i=0; i<size; i++){
		cout << squaresOwned[i] << endl;
	}
}



void Player::transferMoney(std::shared_ptr<Player> to, int amount, std::vector<shared_ptr<Player>> otherPlayers){
	try{
		subtractMoney(amount, otherPlayers);
		to->addMoney(amount);
	}
	catch(const invalid_argument& ia){
			cerr << ia.what() << endl;
	}
}

int Player::getMoney(){
	return money;
}

string Player::getName(){
	return name;
}

char Player::getPiece(){
	return piece;
}

bool Player::isBankrupt(){
	return bankrupt;
}


int Player::getResNum(){
	return numOfResidences;
}
void Player::addResNum(){
	numOfResidences++;
}

int Player::getJailTurns(){
	return jailTurns;
}
void Player::setJailTurns(int jt){
	jailTurns = jt;
}

bool Player::isInJail(){
	return inJail;
}
void Player::setJail(bool jail){
	inJail = jail;
}

int Player::getPosition(){
	return position;
}

int Player::getWorth(){
	int property_worth = 0;
	int size = squaresOwned.size();
	for (int i=0; i<size; i++){
		property_worth+=squaresOwned[i]->getValue();
	}	
	return property_worth+money;

}

std::vector<std::shared_ptr<Square>> Player::getSquares(){
	return squaresOwned;
}

int Player::getGymNum(){
	return numOfGyms; 
}

void Player::addGym(){
	numOfGyms++;
}
void Player::setGymNum(int num){
	numOfGyms=num;
}

int Player::getTimCups(){
	return timCups;
}

void Player::addTimCup(){
	timCups++;
}
void Player::useTimCup(){
	timCups--;
}

void  Player::setPosition(int pos){
	position = pos;
}

void Player::transferProperty(std::shared_ptr<Player> to, std::shared_ptr<Square> square){
	int found=-1;
	int size = squaresOwned.size();
	for (int i=0; i<size; i++){
		if (squaresOwned[i]==square){
			found = i;
			break;
		}
	}
	if (found==-1){
		throw invalid_argument("Property Not Found");
		return;
	}
	if (square->isOwnable() && !square->isImprovable()){
		if (square->isGym()){
			numOfGyms--;
			to->addGym();
		}
		else{
			numOfResidences--;
			to->addResNum();
		}		
	}	
	squaresOwned.erase(squaresOwned.begin()+found);
	to->addSquare(square);
}

void Player::addSquare(std::shared_ptr<Square> square){
	squaresOwned.insert(squaresOwned.end(), square);
}
	
void Player::addMoney(int amount){
	if (amount<=0){
		cout << "Trying to add an amount less than 0." << endl;
		return;
	}	
	else if (bankrupt){
		cout << "Player is bankrupt." << endl;
	}
	else{
		money+=amount;
		cout << "You completed the transaction. Your current balance is now: " << money << endl;
	}
	return;
}

void Player::subtractMoney(int amount, vector<shared_ptr<Player>> otherPlayers){
	if (bankrupt){
		throw invalid_argument("Player is bankrupt.");
		return;
	}
	else if (money >= amount){
		money-=amount;
		cout << "You completed the transaction. Your current balance is now: " << money << endl;
	}
	else {	
		cout << "Your do not have enough money for this transaction. These are your assets: " << endl;
		printPlayerAssets();
		cout << "The following commands are available to you: " << endl;
		cout << "   bankrupt" << endl;
		cout << "   mortgage <property>" << endl;
		cout << "   improve <property> sell" << endl;
		cout << "   trade <player_name> <property> <property>" << endl;
		cout << "   trade <player_name> <property> <money>" << endl;
		
		string line = "";
		while(money < amount){
			
			cout << "Enter a valid command: " << endl;
			stringstream ss(line);
			string temp;
			vector<string> command;
			while (ss >> temp){
				command.push_back(temp);
			}

			if (command[0]=="bankrupt"){
				bankrupt = true;
				return;
			}
			else if (command[0]=="mortgage"){
				if (command.size()!=1){
					int size = squaresOwned.size();
					for (int i=0; i<size; i++){
						if(squaresOwned[i]->getName()==command[1]){
							if (!(squaresOwned[i]->isOwnable())){
								cout << "Square cannot be mortgaged." << endl;
							}
							else{
								squaresOwned[i]->mortgage(shared_from_this());
							}
							break;
						}
					}
				}
			}
			else if (command[0]== "improve"){
				if (command.size()!=3 || command[2]!="sell"){
					cout << "invalid command" << endl;
				}
				else{
					int size = squaresOwned.size();
					for (int i=0; i<size; i++){
						if(squaresOwned[i]->getName()==command[1]){
							if (!(squaresOwned[i]->isImprovable()) || squaresOwned[i]->getImprovementLevel()<1){
								cout << "Square has no improvements." << endl;
							}
							else{
								squaresOwned[i]->improveSell(shared_from_this());
							}
							break;
						}
					}
				}
			}
			else if (command[0]=="trade"){
				if (command.size()!=4){
					int index = 0;
					int size=otherPlayers.size();
					for (int i=0; i<size; i++){
						if (otherPlayers[index]->getName()==command[1]){
							int value=stoi(command[3]);
							if (value>0){
								if (otherPlayers[index]->getMoney()>=value){
									cout << "Does " << command[3] << " accept? (Type accept to accept, anything else to reject)" << endl;
									string accept="";
									getline(cin, accept);
									if (accept=="accept"){
										bool found=false;
										int size = squaresOwned.size();
										for (int i=0; i<size;i++){
											if (squaresOwned[i]->getName()==command[2]){
												transferProperty(otherPlayers[index],squaresOwned[i]);
												otherPlayers[index]->subtractMoney(value, otherPlayers);
												addMoney(value);
												found=true;
												break;
											}
										}
										if (!found){
											cout << "You don't have the propety" << endl;	
										}
									}
									else{
										cout << "Trade rejected" << endl;
									}
								}
								else{
									cout << command[3] << " doesn't have enough money." << endl;
								}
							}

							else {
								bool found=false;
								int numOwned = squaresOwned.size();
								int index=-1;
								for (int i=0; i<numOwned;i++){
									if (squaresOwned[i]->getName()==command[2]){
										found=true;
										index = i;
										break;
									}
								}
								if (!found){
									cout << "You don't have the propety" << endl;	
									break;
								}
								else{

									cout << "Does " << command[3] << " accept? (Type accept to accept, anything else to reject)" << endl;
									string accept="";
									getline(cin, accept);
									if (accept=="accept"){
										bool found=false;
										int numPlayers = otherPlayers.size();
										for (int i=0; i<numPlayers;i++){
											if (otherPlayers[index]->squaresOwned[i]->getName()==command[2]){
												otherPlayers[index]->transferProperty
													(shared_from_this(),otherPlayers[index]->squaresOwned[i]);
												transferProperty(otherPlayers[index], squaresOwned[i]);
												found=true;
												break;
											}
										}
										if (!found){
											cout << "Other player don't have the propety" << endl;	
										}
									}
									else{
										cout << "Trade rejected" << endl;
									}
								}
							}
							break;
						}
					}
				}	
			}
		}
		money-=amount;
		cout << "You raised enough money, and paid the transaction. Your current balance is now: " << money << endl;
	}
	return;
}

void Player::move(int pos){
	position+=pos;
}

