#include "goToTims.h"
using namespace std;


GoToTims::GoToTims(std::shared_ptr<Board> board,string name, int position) : Square{board, name, "", position, 0, nullptr, 0, false, false} {}

void GoToTims::action(shared_ptr<Player> player){
	cout << "You are going to jail." << endl;
	player->setPosition(getBoard()->getSquares()[10]->getPosition());
	player->setJail(true);
	player->setJailTurns(0);

	getBoard()->getSquares()[player->getPosition()]->notifyObservers();

}


