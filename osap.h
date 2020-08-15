#ifndef _OSAP_H_
#define _OSAP_H_
#include <iostream>
#include "square.h"

class Osap : public Square {
  const static int money = 200;

  public:
 	Osap(Board * board,std::string name, int position);
	virtual void action(std::shared_ptr<Player> player) override;
	void collectMoney(std::shared_ptr<Player> player);
};

#endif

