#ifndef _SLC_H_
#define _SLC_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class SLC : public Square {
  static int rollUpCards = 0;

 public:
        SLC(std::string &name, int position);
        void getSLCEffect(Player &player);
	string getName();
	int getPosition();
	bool getImprovable();
	bool getOwnable();
};

#endif
