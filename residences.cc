#include "residences.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


Residences::Residences(std::shared_ptr<Board> board,std::string name, int position, shared_ptr<Player> owner, bool mortgaged): 
	Square{board, name, "", position, res_price, owner, 0, true, false}, 
	owned{false}, mortgaged{mortgaged} {
		if(getOwner()){
			owned=true;
		}	
}

bool Residences::isGym(){
	return gym;
}

void Residences::action(shared_ptr<Player> player){
		if (getImprovementLevel()==-1){
			mortgaged=true;
		}
                
		cout << "You have landed on " << getName() << "." << endl;
		if (getOwner()==nullptr && getCost()>player->getMoney()){
			cout << "No one owns this property but you don't have enough money to normally buy it, so it will be auctioned." << endl;
			auction();
		}
		else if (getOwner()==nullptr){
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
                        payRent(player);
                }
}

void Residences::buy(shared_ptr<Player> player, int price){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
	if(!getOwner()){
		if(player->getMoney() - price >= 0){
			player->subtractMoney(price, getBoard()->getPlayers());
			owned = true;
			mortgaged = false;
			setOwner(player);
			player->addResNum();
                        player->addSquare(getBoard()->getSquares()[getPosition()]);
                        cout << "You bought this property for " << getCost() << endl;
		}
		else{
			cout << "You do not have enough funds to purchase " << getName() << "." << endl;
		}	
	}
	else{
		cout << getOwner()->getName() << " owns " << getName() << "." << endl;
	}
	notifyObservers();
}

void Residences::payRent(shared_ptr<Player> tenant){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
	if(getOwner() && !isMortgaged() && tenant->getName() != getOwner()->getName()){
		int subMoney = 0;
		int res = getOwner()->getResNum();
		if(res == 1)
			subMoney = 25;
		else if(res == 2)
			subMoney = 50;
		else if(res == 3)
			subMoney = 100;
		else if(res == 4)
			subMoney = 200;

		tenant->subtractMoney(subMoney, getBoard()->getPlayers());
                if(tenant->isBankrupt()){
                        if (getBoard()->getPlayers().size()<3){
				cout << "Game has ended." << endl;
				return;
			}
                        cout << tenant->getName() << " is now bankrupt. All assets go to " << getOwner()->getName() << endl;
                        getOwner()->addMoney(tenant->getMoney());
                        vector<shared_ptr<Square>> squares = tenant->getSquares();
                        int numPropertiesTenant = squares.size();
                        for (int i=0; i<numPropertiesTenant; i++){
                                auto square = squares[i];
                                tenant->transferProperty(getOwner(), square, getBoard()->getPlayers());
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

void Residences::auction(){ 

	setImprovementLevel(0);
	mortgaged=false;
   	auto players = getBoard()->getPlayers();
        int numPlayers = players.size();
        int auctioneers = players.size();
        vector<bool> withdraw;
        for(int i = 0; i < auctioneers; i++){
                withdraw.push_back(false);
        }
        int currBid = 0;
	bool noBids = true;
        cout << "The starting bid is: $ " << currBid << "." << endl;
        int index=0;
        while (auctioneers != 0){
                string option;
		if (players[index]->isBankrupt()){
			auctioneers--;
			withdraw[index]=true;
			index = (index+1)%numPlayers;
			while (withdraw[index]){
				index=(index+1)%numPlayers;
			}
			continue;
		}
		if (auctioneers==1 && !noBids){
			break;
		}
                cout << "The current bid is: $ " << currBid << "." << endl;
                cout << players[index]->getName() << ": Enter 'withdraw' to withdraw from the bid or 'bid' to bid a higher value. " << endl;
                cin >> option;
		if(option == "withdraw"){
                        withdraw[index] = true;
                        auctioneers--;
                }
                else if(option == "bid"){
                        while( true ){
				string newBid;        
                        	cout << "Enter bid value: " << endl;
                        	cin >> newBid;
                        	if(newBid == "withdraw"){
                                	withdraw[index] = true;
                                	auctioneers--;
                                	break;
                        	}
				try{
					int newBidInt = stoi(newBid);
					if (newBidInt>players[index]->getMoney()){
						cout << "You cant afford this bid, withdraw, or enter a lower bid" << endl;
						continue;	
					}
					if (newBidInt>currBid){
						noBids=false;
						currBid=newBidInt;
						break;
					}
					else{
                                        	cout << "This bid is not higher than the previous bid. Enter a value higher than the preivous bid or 'withdraw': " << endl;
						continue;
					}

				}
				catch(invalid_argument &ia){	
                                        cout << "Enter a valid bid  or 'withdraw': " << endl;
					continue;
				}
                   	}
		}
		else{
			cout << "Enter either 'bid' or 'withdraw'" << endl;
		}
		if (auctioneers==1){
			continue;
		}
		index = (index+1)%numPlayers;
		while (withdraw[index]){
			index=(index+1)%numPlayers;
		}

        }
	if (noBids){
		return;
	}
        int winner = 0;
        for (int i=0; i<numPlayers; i++){
                if(!withdraw[i]){
                        winner=i;
                        break;
                }
	}
        buy(players[winner], currBid);
	notifyObservers();
}


void Residences::mortgage(shared_ptr<Player> player){
	if(!mortgaged){
		player->addMoney(res_price / 2);
		mortgaged = true;
		setImprovementLevel(-1);
	}
	notifyObservers();
}

void Residences::unmortgage(shared_ptr<Player> player){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
	if(mortgaged){
		int subMoney = (res_price / 2) + (res_price * 0.1);
		if(player->getMoney() - subMoney >= 0){
			player->subtractMoney(subMoney, getBoard()->getPlayers());
			mortgaged = false;
			setImprovementLevel(0);
		}
		else{
			cout << "You do not have enough funds to unmortgage " << getName() << "." << endl;
		}
	}
	notifyObservers();
}

bool Residences::isOwned(){
	return owned;
}

bool Residences::isMortgaged(){
	if (getImprovementLevel()==-1){
		mortgaged=true;
	}
	return mortgaged;
}
