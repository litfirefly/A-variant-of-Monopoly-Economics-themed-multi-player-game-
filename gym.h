#ifndef _GYM_H_
#define _GYM_H_
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Gym : public Square{
 private:
  static int price = 150;
  bool owned;
  bool mortgaged;
  Player owner;
 public:
  Gym(std::string &name, int position);
  void buy(Player &player);
  void payFee(Player &player);
  void auction(vector<shared_ptr<Player>> players);
  void mortgage(Player &player);
  void unmortgage(Player &player);
  
  string getName();
  int getPosition();
  bool getImprovable();
  bool getOwnable();
  bool isOwned();
  bool isMortgaged();
};

#endif
