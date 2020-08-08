#include "player.h"
#include <iostream>
#include <stdexcept>
using namespace std;
Player::Player(char piece, std::string name): piece{piece}, name{name}, position{0}, inJail{false}, jailTurns{-1}, isBankrupt{false}, money{1500}, numOfResidences{0}, numOfGyms{0}{}

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

	if (isBankrupt){
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




void Player::transferMoney(std::shared_ptr<Player> to, int amount){
	try(){
		subtractMoney(amount);
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

int Player::getPosition(){
	return position;
}

int Player::getWorth(){
	int property_worth = 0;
	for (int i=0; i<squaresOwned; i++){
		property_worth+=squaresOwned[i].getValue();
	}	
	return property_worth+money;

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
	else if (isBankrupt){
		cout << "Player is bankrupt." << endl;
	}
	else{
		money+=amount;
		cout << "You completed the transaction. Your current balance is now: " << money << endl;
	}
	return;
}

void Player::subtractMoney(int amount, vector<shared_ptr<Player>> otherPlayers){
	if (isBankrupt){
		throw invalid_argument("Player is bankrupt.");
		return;
	}
	else if (money >= amount){
		money-=amount;
		cout << "You completed the transaction. Your current balance is now: " << money << endl;
	}
	else {	
		cout << "Your do not have enough money for this transaction. These are your assets: " << endl;
		player->printPlayerAssets();
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
				stack_of_inputs.push_back(temp);
			}

			if (command[0]=="bankrupt"){
				isBankrupt = true;
				return;
			}
			else if (command[0]=="mortgage"){
				if (command.size()!=1){
					for (int i=0; i<squaresOwned; i++){
						if(squaresOwned[i]->getName()==command[1]){
							squaresOwned[i]->mortgage(this);
							break;
						}
					}
				}
			}
			else if (command[0]== "improve"){
				if (command.size()!=3 || command[2]!="sell"){
					"invalid command";
				}
				else{
					for (int i=0; i<squaresOwned; i++){
						if(squaresOwned[i]->getName()==command[1]){
							squaresOwned[i]->improveSell(this);
							break;
						}
					}
				}
			}
			else if (command[0]=="trade"){
				if (command.size()!=4){
					int index = 0;
					for (int i=0; i<otherPlayers.size(); i++){
						if (otherPlayers[index]->getName()==command[1]){
							int value=-1;
							if (stoi(command[3],value)){
								if (otherPlayers[index].getMoney()>=value){
									cout << "Does " << command[3] << " accept? (Type accept to accept, anything else to reject)" << endl;
									string accept="";
									getline(accept);
									if (accept=="accept"){
										bool found=false;
										for (int i=0; i<squaresOwned;i++){
											if (squaresOwned[i]->getName()==command[2]){
												transferSquare(otherPlayers[index],squaredOned[i];
												otherPlayers[index]->subtractMoney(value);
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
								int myIndex=-1;
								for (int i=0; i<squaresOwned;i++){
									if (squaresOwned[i]->getName()==command[2]){
										myIndex=i;	
										found=true;
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
									getline(accept);
									if (accept=="accept"){
										bool found=false;
										for (int i=0; i<otherPlayers[index]->squaresOwned;i++){
											if (otherPlayers[index]->squaresOwned[i]->getName()==command[2]){
												transferSquare(this,otherPlayers[index]->squaredOned[i];
												transferSquare(otherPlayers, squresOwned[i]);
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

void Player::move(int position){
	player->position+=position;
}

