#include "square.h"
 
Square::Square(std::shared_ptr<Board> board, std::string name, std::string monopolyBlock, int position, int cost, std::shared_ptr<Player> owner, int improvement_level, bool ownable, bool improvable):
	board{board}, name{name}, monopolyBlock{monopolyBlock}, position{position}, cost{cost}, owner{owner}, improvement_level{improvement_level}, improvable{improvable}{}

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

int Square::getValue(){
	return cost;
}

std::shared_ptr<Player> Square::getOwner(){
	return owner;
}

void Square::setImprovementLevel(int level){
	improvement_level = level;
}
void Square::setOwner(std::shared_ptr<Player> player){
	owner = player;
}	

int Square::getImprovementLevel(){
	return improvement_level;
}

bool Square::isOwnable(){
	return ownable;
}

bool Square::isImprovable(){
	return improvable;
}

std::shared_ptr<Board> Square::getBoard(){
	return board;
}




bool Square::isGym(){
	return false;
}
bool Square::isMortgaged(){
	return false;
}
void Square::mortgage(std::shared_ptr<Player> player){}
void Square::unmortgage(std::shared_ptr<Player> player){}
void Square::improveBuy(std::shared_ptr<Player> player){}
void Square::improveSell(std::shared_ptr<Player> player){}
void Square::action(std::shared_ptr<Player> player){}
void Square::auction(){}



