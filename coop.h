#ifndef _COOP_H_
#define _COOP_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class Coop : public Square {
  const static int payMoney = 150;

 public:
        Coop(std::shared_ptr<Board> board,std::string &name, int position);
        virtual void action(Player &player, vector<shared_ptr<Player>> otherPlayers) override;
	void payBack(Player &player, vector<shared_ptr<Player>> otherPlayers);
};

#endif

