#ifndef _GYM_H_
#define _GYM_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"
class Gym : public Square{
 private:
  static const int gym_price = 150;
 
  int improvementCost;
  std::vector<int> tuition;
  bool gym = true;
  bool owned;
  bool mortgaged;	
 public:
  Gym(std::shared_ptr<Board> board,std::string name, int position,  std::shared_ptr<Player> owner, bool mortgaged);
 
  virtual void action(std::shared_ptr<Player> player) override; 
  virtual bool isGym() override;
  void buy(std::shared_ptr<Player> player, int price);
  void payFee(std::shared_ptr<Player> player);
  void auction();
  void mortgage(std::shared_ptr<Player> player);
  void unmortgage(std::shared_ptr<Player> player);
  
  bool isOwned();
  bool isMortgaged();
};

#endif

