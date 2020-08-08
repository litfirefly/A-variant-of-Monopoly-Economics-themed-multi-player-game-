#ifndef _DCTIMSLINE_H_
#define _DCTIMSLINE_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class DCTimsLine : public Square {
	const int jailFee = 50;
public:
        DCTimsLine(std::string &name, int position);
        void option(Player &player);
	void rollDice(Player &player);
	void payJailFee(Player &player);
	void useRollUp(Player &player);
	string getName();
        int getPosition();
        bool getImprovable();
        bool getOwnable();
};

#endif
