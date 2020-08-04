#include "player.h"
#include <iostream>
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
int Player::transferMoney(std::shared_ptr<Player> to, int amount){
	int fail = subtractMoney(amount);
	if (!fail){
		to->addMoney(amount);
	}
	return fail;
}

int Player::transferProperty(std::shared_ptr<Player> to, std::shared_ptr<Square> square){
	int found=-1;
	int size = squaresOwned.size();
	for (int i=0; i<size; i++){
		if (squaresOwned[i]==square){
			found = i;
			break;
		}
	}
	if (found==-1){
		return -1;
	}	
	squaresOwned.erase(squaresOwned.begin()+found);
	to->addSquare(square);
	return 0;
}

void Player::addSquare(std::shared_ptr<Square> square){
	squaresOwned.insert(squaresOwned.end(), square);
}
	
void Player::addMoney(int amount){
	if (amount<=0 || isBankrupt){
		return;
	}	
	money+=amount;
}

int Player::subtractMoney(int amount){

	if (isBankrupt){
		cout << "The player ("<< name <<") is bankrupt." << endl;
		return -2;
	}
	if (money < amount){
		cout << "The player ("<< name <<") does not have enough money." << endl;
		return -1;
	}
	money-=amount;
	return 0;
}


