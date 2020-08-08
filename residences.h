#ifndef _RESIDENCES_H_
#define _RESIDENCES_H_
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Residences : public Square{
 private:
  static int price = 200;
  bool owned;
  bool mortgaged;
  Player owner;
 public:
  Residences(std::string &name, int position);
  void buy(Player &player);
  void payRent(Player &player);
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
