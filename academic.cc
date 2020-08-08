#include "academic.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>              
using namespace std;

int improvementCost;
vector<int> tuition;
bool owned;
bool mortgaged;
	
AcademicProperty::AcademicProperty(std::shared_ptr<Board> board,std::string name, std::string monopolyBlock, int position, int cost, shared_ptr<Player> owner, int improvement_level, 
		  int improvementCost, vector<int> tuition, bool mortgaged): Square{board, name, monopolyBlock, position, cost, owner, improvement_level, true, true}, 
									     improvementCost{improvementCost}, tuition{tuition}, owned{false}, mortgaged{mortgaged}{
		if(owner){
			owned=true;
		}	
}


void AcademicProperty::action(Player &player){
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
			cout << "The property is owned by " << owner->getName() ". The tuition is currently " << tuition[improvement_level] << "." << endl;
			payTuition(player);
		}
}

void AcademicProperty::buy(Player &player){
        if(!isOwned()){
                if(player->money - price >= 0){
                        player->subtractMoney(cost);
                        owned = true;
                        mortgaged = false;
                        owner = player;
                        player->squaresOwned.push_back(this);
                }
                else{
                        cout << "You do not have enough funds to purchase " << name << "." << endl;
                }
        }
        else{
                cout << player->name << " owns " << name << "." << endl;
        }
}

void AcademicProperty::auction(vector<shared_ptr<Player>> players){
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

int AcademicProperty::auctionner(vector<shared_ptr<Player>> &players, int index, int auctioneers, int currBid, vector<bool> &withdraw){
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
                return auctionner(players, index, auctioneers, currBid, withdraw);
        }
}

void improveBuy(Player &player){
	if(!isMortgaged() && isOwned() && player->name == owner->name && isMonopolyBlockValid()){
		int subMoney = tuition[getImprovementLevel() + 1];
		if(getImprovementLevel() < tuition.size() - 1 && player->money - subMoney >= 0){
			player->subtractMoney(subMoney);
			improvementLevel++;
		}
		else{
			// Player does not have enough money to make improvements
		}
	}
}

void improveSell(Player &player){
        if(!isMortgaged() && isOwned() && player->name == owner->name && isMonopolyBlockValid()){
                int add = tuition[getImprovementLevel()] * 0.5; 
		player->addMoney(add);  
		improvementLevel--;
        }
}

void AcademicProperty::payTuition(Player &tenant){
        if(isOwned() && !isMortgaged() && tenant->name != owner->name){    
		int subMoney = 0;
		subMoney = tuition[getImprovementLevel()];
                
		if(tenant->money - subMoney >= 0){
                        tenant->subtractMoney(subMoney);
                        owner->addMoney(subMoney);
                }
                else{
                        // give user options
                }
        }
}

void AcademicProperty::unmortgage(Player &player){
        if(isMortgaged() && player->name && owner->name){
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

void AcademicProperty::mortgage(Player &player){
        if(!mortgaged && owner->name == player->name){
                player->addMoney(price / 2);
                mortgaged = true;
        }
}


int AcademicProperty::getImprovementCost(){
	return improvementCost;
}

vector<int> AcademicProperty::getTuition(){
	return tuition;
}
bool AcademicProperty::isOwned(){
        return owned;
}

bool AcademicProperty::isMortgaged(){
        return mortgaged;
}

bool AcademicProperty::isMonopolyBlockValid(Player &player, vector<shared_ptr<Square>> &square){
	if(owned && player->name == owner->name){
		int counter = 0;
		for(int i = 0; i < square.size(); i++){
			auto block = square[i];
			if(block->getMonopolyBlock() == getMonopolyBlock())
				counter++;
		}
		return (counter == getMonopolyBlockSize());
	}
}

