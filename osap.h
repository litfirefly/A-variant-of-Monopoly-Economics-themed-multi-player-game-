#ifndef _SQAURE_H_
#define _SQUARE_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class Osap : public Square {
  const static int money = 200;

  public:
 	Osap(std::shared_ptr<Board> board,td::string &name, int position);
	virtual void action(Player &player) override;
};

#endif

