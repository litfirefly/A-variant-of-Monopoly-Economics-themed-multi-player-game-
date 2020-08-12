#include "goToTims.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


GoToTims::GoToTims(std::shared_ptr<Board> board,string name, int position) : Square{board, name, "", position, -1, nullptr, -1, false, false} {}

void GoToTims::action(shared_ptr<Player> player){
	player->setPosition(getBoard()->getSquares()[10]->getPosition());
	player->setJail(true);
	player->setJailTurns(0);
}
