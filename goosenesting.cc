#include "goosenesting.h"
#include <memory>
#include <string>
#include <vector>
using namespace std;

GooseNesting::GooseNesting(string &name, int position) : name{name}, position{position}, monopolyBlock{""}, ownable{false}, improvable{false} {} 

void GooseNesting::displayGeese(Player &player){
	cout << "A flock geese is attacking. Take cover!" << endl;
}

string GooseNesting::getName(){
	        return name;
}

int GooseNesting::getPosition(){
	        return position;
}
bool GooseNesting::getImprovable(){
	        return improvable;
}
bool GooseNesting::getOwnable(){
	        return ownable;
}
