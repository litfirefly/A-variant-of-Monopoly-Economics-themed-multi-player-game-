#include "slc.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

SLC::SLC(string &name, int position) : name{name}, position{position}, monopolyBlock{""}, ownable{false}, improvable{false} {}

void SLC::getSLCEffect(Player &player){
	srand (time(NULL)); 
	int val = rand() % 100 + 1;
	if(val == 100 && rollUpCards != 4){
		player->rollUp++;
		rollUpCards++;
	}
	else{
		val = rand() % 1000 + 1;
		
		if(val >= 1 && val < 126){
			player->move(-3);	
		}
		else if(val >= 126 && val < 291){
			// back 2
			player->move(-2);
		}
		else if(val >= 291 && val < 458){
			// back 1
			player->move(-1);
		}
		else if(val >= 458 && val < 583){
			// forward 1
			player->move(1);
		}
		else if(val >= 583 && val < 750){ 
			// forward 2 
			player->move(2);  
		} 
		else if(val >= 750 && val < 916){   
			// forward 3
			player->move(3);
		} 
		else if(val >= 916 && val < 958){  
			// go to dc tims line
			player->move(-200);
		}
		else{
			// advance to collect osap
			player->move(200);
		}
	}
}

string SLC::getName(){
	return name;
}

int SLC::getPosition(){
	return position;
}
bool SLC::getImprovable(){
	return improvable;
}
bool SLC::getOwnable(){
	return ownable;
}
