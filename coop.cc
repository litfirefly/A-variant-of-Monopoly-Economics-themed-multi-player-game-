#include <string>  
#include "osap.h" 
#include <vector>
#include <memory>
using namespace std;  

Coop::Coop(string &name, int position) : name{name}, position{position}, monopolyBlock{""}, ownable{false}, improvable{false} {}  

void Coop::payBack(Player &player){
	player->subtractMoney(money);  
}

string Coop::getName(){
        return name;
}

int Coop::getPosition(){
        return position;
}
bool Coop::getImprovable(){
        return improvable;
}
bool Coop::getOwnable(){
        return ownable;
}
