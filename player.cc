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
		cout << "Jail: " << (2-jailTurns) << " turns left" <<  endl;
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

	if (timCups>0){
		cout << "TimCups: " << timCups << endl;
	}
	int size=squaresOwned.size();
	if (size>0){
		cout << "Properties: " << squaresOwned[0]->getName();
	}
	for (int i=1; i<size; i++){
		cout << ", " << squaresOwned[i]->getName();
	}
	if (size>0){
		cout << endl;
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

void Player::transferProperty(std::shared_ptr<Player> to, std::shared_ptr<Square> square, vector<shared_ptr<Player>> players){
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

	if (square->isMortgaged() || square->getImprovementLevel()==-1){
		to->subtractMoney(square->getCost()*0.1, players);

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
void Player::subtractMoney(int amount, vector < shared_ptr < Player >> otherPlayers) {
        if (bankrupt) {
                throw invalid_argument("Player is bankrupt.");
                return;
        } else if (money >= amount) {
                money -= amount;
                cout << "You completed the transaction. Your current balance is now: " << money << endl;
        } else {
                cout << "Your do not have enough money for this transaction. These are your assets: " << endl;
                printPlayerAssets();
                cout << "The following commands are available to you: " << endl;
                cout << "   bankrupt" << endl;
                cout << "   mortgage <property>" << endl;
                cout << "   improve <property> sell" << endl;
                cout << "   trade <player_name> <property> <property>" << endl;
                cout << "   trade <player_name> <property> <money>" << endl;
                cout << "   all" << endl;
                string line = "";

                cout << "Enter a valid command: " << endl;
                while (money < amount) {
                        getline(cin, line);
                        stringstream ss(line);
                        string temp;
                        vector < string > command;
                        while (ss >> temp) {
                                command.push_back(temp);
                        }
                        if (command.size() < 1) {
                                continue;
                        }

                        if (command[0] == "bankrupt") {
                                bankrupt = true;
                                return;
                        } else if (command[0] == "mortgage") {
                                if (command.size() > 1) {
                                        int size = squaresOwned.size();
                                        for (int i = 0; i < size; i++) {
                                                if (squaresOwned[i] -> getName() == command[1]) {
                                                        if (!(squaresOwned[i] -> isOwnable())) {
                                                                cout << "Square cannot be mortgaged." << endl;
                                                        } else {
								cout << "player226" << endl;
                                                                squaresOwned[i] -> mortgage(shared_from_this());
                                                        }
                                                        break;
                                                }
                                        }
                                }
                                continue;
                        } else if (command[0] == "improve") {
                                if (command.size() != 3 || command[2] != "sell") {
                                        cout << "invalid command" << endl;
                                } else {
                                        int size = squaresOwned.size();
                                        for (int i = 0; i < size; i++) {
                                                if (squaresOwned[i] -> getName() == command[1]) {
                                                        if (!(squaresOwned[i] -> isImprovable()) || squaresOwned[i] -> getImprovementLevel() < 1) {
                                                                cout << "Square has no improvements." << endl;
                                                        } else {
                                                                squaresOwned[i] -> improveSell(shared_from_this());
                                                        }
                                                        break;
                                                }
                                        }
                                }
                                continue;
                        } else if (command[0] == "trade") {

                                if (command.size() == 4) {
                                        int index = -1;
                                        int size = otherPlayers.size();
                                        for (int i = 0; i < size; i++) {
                                                if (otherPlayers[i] -> getName() == command[1]) {
                                                        index = i;
                                                        break;
                                                }
                                        }
                                        if (index == -1) {
                                                cout << "Player doesn't exist" << endl;
                                                return;
                                        }
                                        shared_ptr < Player > other = otherPlayers[index];
                                        int value = -1;
                                        try {
                                                value = stoi(command[3]);
                                        } catch (exception & err) {
	
					}

                                        if (value > -1) {
                                                int numPropOwned = squaresOwned.size();
                                                int square_index = -1;
                                                string accept = "";
                                                for (int i = 0; i < numPropOwned; i++) {
                                                        if (squaresOwned[i]->getName() == command[2]) {
                                                                square_index = i;
                                                                break;
                                                        }
                                                }
                                                if (square_index == -1) {
                                                        cout << "You don't own this square." << endl;
                                                        continue;
                                                }

                                                if (squaresOwned[square_index] -> isImprovable()) {
                                                        string mono_block = squaresOwned[square_index] -> getMonopolyBlock();
                                                        for (int i = 0; i < numPropOwned; i++) {
                                                                if (squaresOwned[i] -> getMonopolyBlock() == mono_block && squaresOwned[i] -> getImprovementLevel() > 0) {
                                                                        cout << "Cannot trade when the property, or properties in the same block, have improvements" << endl;
                                                                        continue;
                                                                }
                                                        }
                                                }

                                                if (other -> getMoney() < value) {
                                                        cout << "The other player doesn't have enough money" << endl;
                                                        continue;
                                                }
                                                cout << "Does " << command[1] << " accept the trade (type accept to accept)" << endl;
                                                getline(cin, accept);
                                                if (accept != "accept") {
                                                        cout << command[1] << " has not accepted." << endl;
                                                        continue;;
                                                }
                                                transferProperty(other, squaresOwned[square_index], otherPlayers);
                                                other -> subtractMoney(value, otherPlayers);
                                                addMoney(value);

                                                continue;;
                                        }

                                        int numPropOwned = squaresOwned.size();
                                        int square_index = -1;
                                        string accept = "";
                                        for (int i = 0; i < numPropOwned; i++) {
                                                if (squaresOwned[numPropOwned] -> getName() == command[2]) {
                                                        square_index = i;
                                                        break;
                                                }
                                        }
                                        if (square_index == -1) {
                                                cout << "You don't own this square." << endl;
                                                continue;;
                                        }
                                        vector < shared_ptr < Square >> otherSquares = other -> getSquares();
                                        int numPropOwnedOther = otherSquares.size();
                                        int square_index_other = -1;
                                        for (int i = 0; i < numPropOwnedOther; i++) {
                                                if (otherSquares[numPropOwnedOther] -> getName() == command[3]) {
                                                        square_index_other = i;
                                                        break;
                                                }
                                        }
                                        if (square_index_other == -1) {
                                                cout << command[1] << " doesn't own this square." << endl;
                                                continue;
                                        }

                                        if (squaresOwned[square_index] -> isImprovable()) {
                                                string mono_block = squaresOwned[square_index] -> getMonopolyBlock();
                                                for (int i = 0; i < numPropOwned; i++) {
                                                        if (squaresOwned[i] -> getMonopolyBlock() == mono_block && squaresOwned[i] -> getImprovementLevel() > 0) {
                                                                cout << "Cannot trade when the property, or properties in the same block, have improvements" << endl;
                                                                continue;
                                                        }
                                                }
                                        }

                                        if (otherSquares[square_index_other] -> isImprovable()) {
                                                string mono_block = otherSquares[square_index_other] -> getMonopolyBlock();
                                                for (int i = 0; i < numPropOwnedOther; i++) {
                                                        if (otherSquares[i] -> getMonopolyBlock() == mono_block && otherSquares[i] -> getImprovementLevel() > 0) {
                                                                cout << "Cannot trade when the property, or properties in the same block, have improvements" << endl;
                                                                continue;
                                                        }
                                                }
                                        }
                                        cout << "Does " << command[1] << " accept the trade (type accept to accept)" << endl;
                                        getline(cin, accept);
                                        if (accept != "accept") {
                                                cout << command[1] << " has not accepted." << endl;
                                                continue;
                                        }
                                        transferProperty(other, squaresOwned[square_index], otherPlayers);
                                        other -> transferProperty(shared_from_this(), otherSquares[square_index_other], otherPlayers);
                                        continue;
                                }
			}
			else if (command[0] == "all") {
                        	int numPlayers = otherPlayers.size();
                                for (int i = 0; i < numPlayers; i++) {
                                         otherPlayers[i] -> printPlayerAssets();
                                         cout << endl;
                                }

                        }
                        cout << "Enter a valid command: " << endl;        
                }
                money -= amount;
                cout << "You raised enough money, and paid the transaction. Your current balance is now: " << money << endl;
        }
}

void Player::move(int pos){
	position+=pos;
}


vector<int> Player::getJailLastRoll(){
	return jailLastRoll;
}
void Player::setJailLastRoll(vector<int> roll){
	jailLastRoll.clear();
	jailLastRoll.push_back(roll[0]);
	jailLastRoll.push_back(roll[1]);
}

