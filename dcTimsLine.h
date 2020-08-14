#ifndef _DCTIMSLINE_H_
#define _DCTIMSLINE_H_

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "player.h"
#include "square.h"

class DCTimsLine : public Square {
	const int jailFee = 50;
public:
        DCTimsLine(std::shared_ptr<Board> board,std::string name, int position);
        virtual void action(std::shared_ptr<Player> player) override;
	void rollDice(std::shared_ptr<Player> player);
	void payJailFee(std::shared_ptr<Player> player);
	void useRollUp(std::shared_ptr<Player> player);
};

#endif

