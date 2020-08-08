#include "needleshall.h"
#include "player.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

NeedlesHall::NeedlesHall(std::shared_ptr<Board> board, string &name, int position) : Square{board, "", position, -1, nullptr, -1, false, false} {}

void NeedlesHall::action(Player &player){
        srand (time(NULL));
        int val = rand() % 100 + 1;
        if(val == 100 && rollUpCards != 4){
                player->rollUp++;
                rollUpCards++;
        }
        else{
                val = rand() % 100 + 1;

                if(val >= 1 && val < 5){
                        player->subtractMoney(200);
                }
                else if(val >= 5 && val < 16){
                        player->subtractMoney(100);
                }
                else if(val >= 16 && val < 33){
                        player->subtractMoney(50);
                }
                else if(val >= 33 && val < 66){
                        player->addMoney(25);
                }
                else if(val >= 66 && val < 83){
                        player->addMoney(50);
		}
		else if(val >= 83 && val < 94){ 
			player->addMoney(100); 
		}
		else{
			player->addMoney(200);
		}
	}
}

}


