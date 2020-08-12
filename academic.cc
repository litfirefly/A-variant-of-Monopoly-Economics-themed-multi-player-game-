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
	
AcademicProperty::AcademicProperty(std::shared_ptr<Board> board,std::string name, std::string monopolyBlock, int position, int cost, shared_ptr<Player> owner, int improvement_level, int improvementCost, vector<int> tuition, bool mortgaged): Square{board, name, monopolyBlock, position, cost, owner, improvement_level, true, true}, improvementCost{improvementCost}, tuition{tuition}, owned{false}, mortgaged{mortgaged}{
		if(getOwner()){
			owned=true;
		}	
}


void AcademicProperty::action(shared_ptr<Player> player){
		if (getImprovementLevel()==-1){
			mortgaged=true;
		}
		cout << "You have landed on " << getName() <<  "." << endl;
		if (getOwner()==nullptr){
			cout << "No one owns this property yet, you can choose to buy it. Enter \"buy\" to buy the property." << endl;
			string line = "";
			cin >> line;
			if (line=="buy"){
				buy(player, getCost());
			}
			else{
				cout << "Since you didn't buy the property, we will now auction it." << endl;
				auction();
			}
		}
		else if (getOwner()==player){
			cout << "You own this property, no action is to be taken." << endl;
		}
		else{
			cout << "The property is owned by " << getOwner()->getName() <<  ". The tuition is currently " << tuition[getImprovementLevel()] << "." << endl;
			payTuition(player);
		}
}

void AcademicProperty::buy(shared_ptr<Player> player, int price){
        if(!isOwned()){
                if(player->getMoney() - price >= 0){
                        player->subtractMoney(price, getBoard()->getPlayers());
                        owned = true;
                        mortgaged = false;
                        setOwner(player);
                        player->addSquare(getBoard()->getSquares()[getPosition()]);
			cout << "You bought this property for " << price << endl;
                }
                else{
                        cout << "You do not have enough funds to purchase " << getName() << "." << endl;
                }
        }
        else{
                cout << getOwner()->getName() << " owns " << getName() << "." << endl;
        }
}

void AcademicProperty::auction(){
        auto players = getBoard()->getPlayers();
        int numPlayers = players.size();
        int auctioneers = players.size();
        vector<bool> withdraw;
        for(int i = 0; i < auctioneers; i++){
                withdraw.push_back(false);
        }
        int currBid = 0;
        cout << "The starting bid is: $ " << currBid << "." << endl;
        int index=0;
        while (auctioneers!=1){
                string option;
                cout << "The current bid is: $ " << currBid << "." << endl;
                cout << players[index]->getName() << ": Enter 'withdraw' to withdraw from the bid or 'bid' to bid a higher value. " << endl;
                cin >> option;
                if(option == "withdraw"){
                        withdraw[index] = true;
                        auctioneers--;
                }
                // Excepting the user to enter a higher, positive valid bid than previous user
                else if(option == "bid"){
                        int newBid=0;
                        cout << "Enter bid value: " << endl;
                        cin >> newBid;
			while( true ){
				if (newBid>currBid){
                                	currBid=newBid;
					break;
                        	}
                        	else{
                                	cout << "This bid is not higher than the previous bid. Enter a value higher than a previous value: " << endl;
                        	}

			}
              
                }
                index++;
                if(index == numPlayers){
                        index = 0;
                }
        }
        int winner = 0;
        for (int i=0; i<numPlayers; i++){
                if(!withdraw[i]){
                        winner=i;
                        break;
                }
        }
        buy(players[winner], currBid);


}

void AcademicProperty::improveBuy(shared_ptr<Player> player){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
	if(!isMortgaged() && isOwned() && player->getName() == getOwner()->getName() && isMonopolyBlockValid()){
		int subMoney = tuition[getImprovementLevel() + 1];
		int max_imp_level = tuition.size()-1;
		if(getImprovementLevel() < max_imp_level && player->getMoney()- subMoney >= 0){
			player->subtractMoney(subMoney, getBoard()->getPlayers());
			setImprovementLevel(getImprovementLevel()+1);
		}
		else{
			cout << "Not enough money to improve. " << endl;
		}
	}
}

void AcademicProperty::improveSell (shared_ptr<Player> player){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
        if(!isMortgaged() && isOwned() && player->getName() == getOwner()->getName() && isMonopolyBlockValid() && getImprovementLevel()>0){
                int add = improvementCost * 0.5; 
		player->addMoney(add);  
		setImprovementLevel(getImprovementLevel()-1);
        }
}

void AcademicProperty::payTuition(shared_ptr<Player> tenant){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
        if(isOwned() && !isMortgaged() && tenant->getName() != getOwner()->getName()){    
		int subMoney = 0;
		subMoney = tuition[getImprovementLevel()];
                
		tenant->subtractMoney(subMoney, getBoard()->getPlayers());
                if(tenant->isBankrupt()){
                        cout << tenant->getName() << " is now bankrupt. All assets go to " << getOwner()->getName() << endl;
                        getOwner()->addMoney(tenant->getMoney());
                        vector<shared_ptr<Square>> squares = tenant->getSquares();
                        int numPropertiesTenant = squares.size();
                        for (int i=0; i<numPropertiesTenant; i++){
                                auto square = squares[i];
                                tenant->transferProperty(getOwner(), square);
                        }
                        for (int i=0; i<tenant->getTimCups(); i++){
                                getOwner()->addTimCup();
                        }
                }
                else{
                        getOwner()->addMoney(subMoney);
                }

        }
}

void AcademicProperty::unmortgage(shared_ptr<Player> player){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
        if(isMortgaged() && player->getName() == getOwner()->getName()){
                int subMoney = (getCost() / 2) + (getCost() * 0.1);
                if(player->getMoney() - subMoney >= 0){
                        player->subtractMoney(subMoney, getBoard()->getPlayers());
                        mortgaged = false;
			setImprovementLevel(0);
                }
                else{
                        cout << "You do not have enough funds to unmortgage " << getName() << "." << endl;
                }
        }
}

void AcademicProperty::mortgage(shared_ptr<Player> player){
        if(!mortgaged && getOwner()->getName() == player->getName()){
                player->addMoney(getCost() / 2);
                mortgaged = true;
        	setImprovementLevel(-1);
	}
}


int AcademicProperty::getImprovementCost(){
	return improvementCost;
}

int AcademicProperty::getValue(){
	return getCost() + (improvementCost*getImprovementLevel());
}

vector<int> AcademicProperty::getTuition(){
	return tuition;
}
bool AcademicProperty::isOwned(){
        return owned;
}

bool AcademicProperty::isMortgaged(){
        if (getImprovementLevel()==-1){
		mortgaged=true;
	}
	return mortgaged;
}

bool AcademicProperty::isMonopolyBlockValid(){
	auto squares = getBoard()->getSquares();
	int numSquares = squares.size();
	for(int i = 0; i < numSquares; i++){
		auto square = squares[i];
		if(square->getMonopolyBlock() == getMonopolyBlock() && !(square->getOwner()==getOwner())){
				return false;
		}
	}
	return true;
	
}
