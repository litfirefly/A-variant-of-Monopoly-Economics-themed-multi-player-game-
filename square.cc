#include "square.h"
 

Square::Square(std::string name, std::string monopolyBlock, int position, bool ownable, bool improvable): name{name}, monopolyBlock{monopolyBLock},
       	position{position}, ownable{ownable}, improvable{improvable}{}
std::string Square::getName(){
	return name;
}
std::string Square::getMonopolyBlock(){
	return monopolyBlock;
}
int getPosition(){
	return position;
}
bool getOwnable(){
	return ownable;
}
bool getImprovable(){
	return improvable;
}
