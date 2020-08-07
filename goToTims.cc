#include "goToTims.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


GoToTims::GoToTims(string &name, int position) : Square{name, "", position, -1, nullptr, -1, false, false} {}

void GoToTims::moveToJail(Player &player, const DCTimsLine &dc){
	player->position = dc.position;
	player->inJail = true;
	player->jainTurns = 0;
}


