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
 public:
  Residences(std::shared_ptr<Board> board,std::string &name, int position, shared_ptr<Player> owner, bool mortgaged);
  virtual void action(shared_ptr<Player> player) override;
  void buy(Player &player);
  void payRent(Player &player);
  void auction(vector<shared_ptr<Player>> players);
  void mortgage(Player &player);
  void unmortgage(Player &player);

  bool isOwned();
  bool isMortgaged();
};

#endif
