#ifndef _COOP_H_
#define _COOP_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class Coop : public Square {
  const static int payMoney = 150;

 public:
        Coop(std::string &name, int position);
        void payBack(Player &player);
	string getName();
        int getPosition();
        bool getImprovable();
        bool getOwnable();
};

#endif
