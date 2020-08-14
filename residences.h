#ifndef _RESIDENCES_H_
#define _RESIDENCES_H_

#include <iostream>
#include "player.h"
#include "square.h"


class Residences : public Square{
 private:
  static const int res_price = 200;
  bool gym=false;
 public:
  Residences(std::shared_ptr<Board> board,std::string name, int position);
  virtual void action(std::shared_ptr<Player> player) override;
  virtual bool isGym() override;
  void buy(std::shared_ptr<Player> player, int price);
  void auction();
  void payRent(std::shared_ptr<Player> player);
  void mortgage(std::shared_ptr<Player> player);
  void unmortgage(std::shared_ptr<Player> player);
};

#endif
