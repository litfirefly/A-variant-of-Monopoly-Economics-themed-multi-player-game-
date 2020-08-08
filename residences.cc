#include "residences.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


Residences::Residences(std::shared_ptr<Board> board,std::string name, int position, shared_ptr<Player> owner, bool mortgaged): Square{board, name, "", position, price, owner, improvement_level, true, false}, 
	owned{false}, mortgaged{mortgaged} {
		if(owner){
			owned=true;
		}	
}

void Residences::action(Player &player){
                cout << "You have landed on " << name "." << endl;
                if (owner==nullptr){
                        cout << "Noone owns this property yet, you can choose to buy it. Enter \"buy\" to buy the property." << endl;
                        string line = "";
                        cin >> line;
                        if (line=="buy"){
                                buy(player);
                                cout << "You bought this property for " << cost << endl;
                        }
                        else{
                                cout << "Since you didn't buy the property, we will now auction it." << endl;
                                auction(players);
                        }
                }
                else if (owner==player){
                        cout << "You own this property, no action is to be taken." << endl;
                }
                else{
                        cout << "The property is owned by " << owner->getName() "." << endl;
                        payRent(player);
                }
}

void Residences::buy(Player &player){
	if(!isOwned()){
		if(player->money - price >= 0){
			player->subtractMoney(price);
			owned = true;
			mortgaged = false;
			owner = player;
			player->numOfResidences++;
		}
		else{
			cout << "You do not have enough funds to purchase " << name << "." << endl;
		}	
	}
	else{
		cout << player->name << " owns " << name << "." << endl;
	}
}

void Residences::payRent(Player &tenant){
	if(isOwned() && !isMortgaged() && tenant->name == player->name){
		int subMoney = 0;
		if(owner->numOfResidences == 1)
			subMoney = 25;
		else if(owner->numOfResidences == 2)
			subMoney = 50;
		else if(owner->numOfResidences == 3)
			subMoney = 100;
		else if(owner->numOfResidences == 4)
			subMoney = 200;

		if(tenant->money - subMoney >= 0){
			tenant->subtractMoney(subMoney);
			owner->addMoney(subMoney);
		}
		else{
			// give user options
		}	
	}
}

void Residences::auction(vector<shared_ptr<Player>> players){
	int auctioneers = players.size();
	vector<bool> withdraw;
	for(int i = 0; i < players.size(); i++){
		withdraw.push_back(false);
	}
	int bid = 0;
	cout << "The starting bid is: $ " << bid << "." << endl;
	int index = auctionner(players, auctioneers - auctioneers, auctioneers, bid, withdraw);
	buy(players[index]);
}

int Residences::auctionner(vector<shared_ptr<Player>> &players, int index, int auctioneers, int currBid, vector<bool> &withdraw){
	if(auctioneers == 1){
		for(int i = 0; i < players.size(); i++){
			if(withdraw[i] == false){
				return i;
			}
		}
	}
	else{
		string option;
		cout << "The current bid is: $ " << bid << "." << endl;
		cout << players[index]->name << ": Enter 'withdraw' to withdraw from the bid or 'bid' to bid a higher value. " << endl;
        	cin << option;
        	if(option == "withdraw"){
        		withdraw[i] = true;
			auctioneers--;
        	}
		// Excepting the user to enter a higher, positive valid bid than previous user
        	else if(option == "bid"){ 
			cout << "Enter bid value: " << endl;
                	cin << currBid;
		}
		index++;
		if(index == players.size()){
                        index = 0;
                }
		return auctionner(players, index, auctioneers, currBid, withdraw) + 0;
	}
}

void Residences::mortgage(Player &player){
	if(!mortgaged){
		player->addMoney(price / 2);
		mortgaged = true;
	}
}

void Residences::unmortgage(Player &player){
	if(mortgaged){
		int subMoney = (price / 2) + (price * 0.1);
		if(player->money - subMoney >= 0){
			player->subtractMoney(subMoney);
			mortgaged = false;
		}
		else{
			cout << "You do not have enough funds to unmortgage " << name << "." << endl;
		}
	}
}

bool Residences::isOwned(){
	return owned;
}

bool Residences::isMortgaged(){
	return mortgaged;
}
