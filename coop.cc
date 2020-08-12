#include <string>  
#include "coop.h" 
#include <vector>
#include <memory>
#include <iostream>
using namespace std;  


Coop::Coop(std::shared_ptr<Board> board,string name, int position) : Square{board, name, "", position, -1, nullptr, -1, false, false} {}

void Coop::action(shared_ptr<Player> player){
	player->subtractMoney(payMoney, getBoard()->getPlayers());
	if (player->isBankrupt()){
		cout << "You have been bankruptted, your properties will be auctionned, your other assets will return to the bank." << endl;
		vector<shared_ptr<Square>> squares = player->getSquares();
                int numProperties = squares.size();
                for (int i=0; i<numProperties; i++){
                       auto square = squares[i];
		       square->auction();
                }
		getBoard()->setRollUpCards(getBoard()->getRollUpCards()-1);
	}
}
