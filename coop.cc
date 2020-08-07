#include <string>  
#include "coop.h" 
#include <vector>
#include <memory>
using namespace std;  


Coop::Coop(string &name, int position) : Square{name, "", position, -1, nullptr, -1, false, false} {}

void Coop::payBack(Player &player, vector<shared_ptr<Player>> otherPlayers){
	player->subtractMoney(payMoney, otherPlayers);
}

