#ifndef _NEEDLESHALL_H_
#define _NEEDLESHALL_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class NeedlesHall : public Square {
  static int rollUpCards = 0;

 public:
        NeedlesHall(std::string &name, int position);
        void getNeedlesHallEffect(Player &player);
	string getName();
	int getPosition();
	bool getImprovable();
	bool getOwnable();
};

#endif
