#include <string>
#include "osap.h"
#include <vector>
#include <memory>
using namespace std;


Osap::Osap(std::shared_ptr<Board> board,string &name, int position) : Square{board, name, "", position, -1, nullptr, -1, false, false} {}
void Osap::action(Player &player){
	player->addMoney(money);
}


