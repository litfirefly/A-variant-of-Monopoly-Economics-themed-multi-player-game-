#include <string>
#include "osap.h"
#include <vector>
#include <memory>
using namespace std;


Osap::Osap(string &name, int position) : Square{name, "", position, -1, nullptr, -1, false, false} {}
void Osap::collectMoney(Player &player){
	player->addMoney(money);
}


