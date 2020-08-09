#ifndef _RESIDENCES_H_
#define _RESIDENCES_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"
using namespace std;

class Residences : public Square{
 private:
  static const int res_price = 200;
  bool gym=false;
  bool owned;
  bool mortgaged;
 public:
  Residences(std::shared_ptr<Board> board,std::string name, int position, shared_ptr<Player> owner, bool mortgaged);
  virtual void action(std::shared_ptr<Player> player) override;
  virtual bool isGym() override;
  void buy(std::shared_ptr<Player> player, int price);
  void payRent(std::shared_ptr<Player> player);
  void auction();
  void mortgage(std::shared_ptr<Player> player);
  void unmortgage(std::shared_ptr<Player> player);

  bool isOwned();
  bool isMortgaged();
};

#endif
