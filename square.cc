#include "square.h"
 
::xSquare::Square(std::string name, std::string monopolyBlock, int position, int cost, string owner, int improvement_level, bool ownable, bool improvable):
	name{name}, monopolyBlock{monopolyBlock}, position{position}, cost{cost}, owner{owner}, improvement_level{improvement_level}, improvable{improvable}{}

std::string Square::getName(){
	return name;
}

std::string Square::getMonopolyBlock(){
	return monopolyBlock;
}

int Square::getPosition(){
	return position;
}

int Square::getCost(){
	return cost;
}

std::shared_ptr<Player> Square::getOwner(){
	return owner;
}

int Square::getImprovementLevel(){
	return improvement_level;
}

bool Square::getOwnable(){
	return ownable;
}

bool Square::getImprovable(){
	return improvable;
}

