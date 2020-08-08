#include "goToTims.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

GoToTims::GoToTims(string &name, int position) : name{name}, position{position}, monopolyBlock{""}, ownable{false}, improvable{false} {}

void GoToTims::moveToJail(Player &player, const DCTimsLine &dc){
	player->position = dc.position;
	player->inJail = true;
	player->jainTurns = 0;
}

string GoToTims::getName(){
	return name;
}

int GoToTims::getPosition(){
	return position;
}
bool GoToTims::getImprovable(){
	return improvable;
}
bool GoToTims::getOwnable(){
	return ownable;
}
