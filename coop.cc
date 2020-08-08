#include <string>  
#include "coop.h" 
#include <vector>
#include <memory>
using namespace std;  


Coop::Coop(std::shared_ptr<Board> board,string &name, int position) : Square{board, name, "", position, -1, nullptr, -1, false, false} {}

void Coop::action(Player &player, vector<shared_ptr<Player>> otherPlayers){
	payBack(player, otherPlayers);
}
void Coop::payBack(Player &player, vector<shared_ptr<Player>> otherPlayers){
	player->subtractMoney(payMoney, otherPlayers);
}

