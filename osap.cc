#include <string>
#include "osap.h"
#include <vector>
#include <memory>
#include <iostream>
using namespace std;


Osap::Osap(std::shared_ptr<Board> board,string name, int position) : Square{board, name, "", position, -1, nullptr, -1, false, false} {}
void Osap::action(shared_ptr<Player> player){
	collectMoney(player);
}
void Osap::collectMoney(shared_ptr<Player> player){
	cout << "Collected Money from OSAP!!!" << endl;
	player->addMoney(money);
}


