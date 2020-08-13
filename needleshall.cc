#include "needleshall.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

NeedlesHall::NeedlesHall(std::shared_ptr<Board> board, string name, int position) : Square{board,name, "", position, 0, nullptr, 0, false, false} {}

void NeedlesHall::action(shared_ptr<Player> player){
        srand (time(NULL));
        int val = rand() % 100 + 1;
        if(val == 100 && getBoard()->getRollUpCards() != 4){
                player->addTimCup();
		getBoard()->setRollUpCards(getBoard()->getRollUpCards()+1);
        }
        else{
                val = rand() % 1000 + 1;

                if(val >= 1 && val < 56){
                        player->subtractMoney(200, getBoard()->getPlayers());
                }
                else if(val >= 56 && val < 167){
                        player->subtractMoney(100, getBoard()->getPlayers());
                }
                else if(val >= 167 && val < 334){
                        player->subtractMoney(50, getBoard()->getPlayers());
                }
                else if(val >= 334 && val < 667){
                        player->addMoney(25);
                }
                else if(val >= 667 && val < 834){
                        player->addMoney(50);
		}
		else if(val >= 834 && val < 945){ 
			player->addMoney(100); 
		}
		else{
			player->addMoney(200);
		}

		if (player->isBankrupt()){
                        if (getBoard()->getPlayers().size()<3){
				cout << "Game has ended." << endl;
				return;
			}
			cout << "You have been bankruptted, your properties will be auctionned, your other assets will return to the bank." << endl;
			vector<shared_ptr<Square>> squares = player->getSquares();
        	        int numProperties = squares.size();
                	for (int i=0; i<numProperties; i++){
                       		auto square = squares[i];
		       		square->auction();
                	}
			getBoard()->setRollUpCards(getBoard()->getRollUpCards()-player->getTimCups());
		}
	}
}




