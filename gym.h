#ifndef _GYM_H_
#define _GYM_H_
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Gym : public Square{
 private:
  static int price = 150;
 
  int improvementCost;
  vector<int> tuition;
  bool owned;
  bool mortgaged;
  int auctionner(vector<shared_ptr<Player>> &players, int index, int auctioneers, int currBid, vector<bool> &withdraw);
	
 public:
  Gym(std::string name, int position, shared_ptr<Player> owner, bool mortgaged);
  
  void buy(Player &player);
  void payFee(Player &player);
  void auction(vector<shared_ptr<Player>> players);
  void mortgage(Player &player);
  void unmortgage(Player &player);
  
  bool isOwned();
  bool isMortgaged();
};

#endif

