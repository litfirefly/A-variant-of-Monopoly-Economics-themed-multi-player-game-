#ifndef _ACADEMICPROPERTY_H_
#define _ACADEMICPROPERTY_H_

#include "square.h"

class AcademicProperty: public Square {
	int improvementCost;
	vector<int> tuition;
	bool owned;
	bool mortgaged;
  	int auctionner(vector<shared_ptr<Player>> &players, int index, int auctioneers, int currBid, vector<bool> &withdraw);
	
public:
  AcademicProperty(std::string name, std::string monopolyBlock, int position, int cost, shared_ptr<Player> owner, int improvement_level, 
		  int improvementCost, vector<int> tuition, bool mortgaged)

     
  void buy(Player &player);
  void auction(vector<shared_ptr<Player>> player);
  void improveBuy(Player& player);
  void improveSell(Player& player);
  void payTuition(Player& tenant);
  void unmortgage(Player& player);
  void mortgage(Player& player);

  
  int getImprovementCost(); 
  vector<int> getTuition(); 
  bool isOwned();  
  bool isMortaged();
  bool isMonopolyBlockValid();
};

#endif

