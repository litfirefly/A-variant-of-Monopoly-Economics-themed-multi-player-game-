#include "gym.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Gym::Gym(std::shared_ptr<Board> board,std::string name, int position, shared_ptr<Player> owner, bool mortgaged): 
	Square{board, name, "", position, gym_price, owner,0, true, false}, owned{false}, mortgaged{mortgaged} {
		if(owner){
			owned=true;
		}	
}

void Gym::action(shared_ptr<Player> player){
		if (getImprovementLevel()==-1){
			mortgaged=true;
		}
                cout << "You have landed on " << getName() << "." << endl;
                if (getOwner()==nullptr){
                        cout << "Noone owns this property yet, you can choose to buy it. Enter \"buy\" to buy the property." << endl;
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
                        cout << "The property is owned by " << getOwner()->getName() <<  "." << endl;
                        payFee(player);
                }

}
bool Gym::isGym(){
	return gym;
}
void Gym::buy(shared_ptr<Player> player, int price){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
        if(!isOwned()){
                if(player->getMoney() - price >= 0){
                        player->subtractMoney(price, getBoard()->getPlayers());
                        owned = true;
                        mortgaged = false;
                        setOwner(player);
                        player->addGym();
			player->addSquare(getBoard()->getSquares()[getPosition()]);
                        cout << "You bought this property for " << price << endl;
                }
                else{
                        cout << "You do not have enough funds to purchase " << getName() << "." << endl;
                }
        }
        else{
                cout << player->getName() << " owns " << getName() << "." << endl;
        }
}

void Gym::payFee(shared_ptr<Player> tenant){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
        if(owned && !mortgaged){
                int subMoneyTimes = 0;
		
		srand (time(NULL));
		int die1 = rand() % 6 + 1;
		int die2 = rand() % 6 + 1;
		int dieSum = die1 + die2;

                if(getOwner()->getGymNum() == 1)
                        subMoneyTimes = 4;
                else if(getOwner()->getGymNum() == 2)
                        subMoneyTimes = 10;
                
		int subMoney = subMoneyTimes * dieSum;

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

void Gym::auction(){
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
                        if (newBid>currBid){
                                currBid=newBid;
                        }
                        else{
                                cout << "This bid is not higher than the previous bid, your turn will be skipped." << endl;
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


void Gym::mortgage(shared_ptr<Player> player){
        if(!mortgaged){
                player->addMoney(gym_price / 2);
                mortgaged = true;
        	setImprovementLevel(-1);
	}
}

void Gym::unmortgage(shared_ptr<Player> player){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
        if(mortgaged){
                int subMoney = (gym_price / 2) + (gym_price * 0.1);
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

bool Gym::isOwned(){
	return owned;
}

bool Gym::isMortgaged(){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
	return mortgaged;
}

