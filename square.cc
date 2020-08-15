#include "square.h"
 
Square::Square(Board * board, std::string name, std::string monopolyBlock, int position, int cost, std::shared_ptr<Player> owner, 
		int improvement_level, bool ownable, bool improvable):
	board{board}, name{name}, monopolyBlock{monopolyBlock}, position{position}, cost{cost}, owner{nullptr}, 
	improvement_level{0},ownable{ownable}, improvable{improvable}{}

Board* Square::getBoard(){
	return board;
}

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

void Square::setOwner(std::shared_ptr<Player> player){
	owner = player;
	notifyObservers();
}

int Square::getImprovementLevel(){
	return improvement_level;
}

void Square::setImprovementLevel(int level){
	improvement_level = level;
	notifyObservers();
}
	
bool Square::isOwnable(){
	return ownable;
}

bool Square::isImprovable(){
	return improvable;
}

bool Square::isMortgaged(){
	return improvement_level==-1;
}

int Square::getValue(){
	return cost;
}

bool Square::isGym(){
	return false;
}

void Square::mortgage(std::shared_ptr<Player> player){}
void Square::unmortgage(std::shared_ptr<Player> player){}
void Square::improveBuy(std::shared_ptr<Player> player){}
void Square::improveSell(std::shared_ptr<Player> player){}
void Square::action(std::shared_ptr<Player> player){}
void Square::auction(){}
Square::~Square(){}
