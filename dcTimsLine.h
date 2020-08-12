#ifndef _DCTIMSLINE_H_
#define _DCTIMSLINE_H_
#include <string>
#include <vector>
#include <memory>
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
