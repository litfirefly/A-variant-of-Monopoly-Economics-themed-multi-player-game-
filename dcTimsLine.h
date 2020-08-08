#ifndef _DCTIMSLINE_H_
#define _DCTIMSLINE_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class DCTimsLine : public Square {
	const int jailFee = 50;
public:
        DCTimsLine(std::shared_ptr<Board> board,std::string &name, int position);
        virtual void action(Player &player) override;
	void rollDice(Player &player);
	void payJailFee(Player &player);
	void useRollUp(Player &player);
};

#endif

