#include <string>
#include "osap.h"
#include <vector>
#include <memory>
using namespace std;

Osap::Osap(string &name, int position) : name{name}, position{position}, monopolyBlock{""}, ownable{false}, improvable{false} {}

void Osap::collectMoney(Player &player){
	player->addMoney(money);
}

string Osap::getName(){
        return name;
}

int Osap::getPosition(){
        return position;
}
bool Osap::getImprovable(){
        return improvable;
}
bool Osap::getOwnable(){
        return ownable;
}
