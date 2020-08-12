#ifndef _ACADEMICPROPERTY_H_
#define _ACADEMICPROPERTY_H_

#include "square.h"

class AcademicProperty: public Square {
	int improvementCost;
	std::vector<int> tuition;
	bool owned;
	bool mortgaged;
	
public:
  AcademicProperty(std::shared_ptr<Board> board, std::string name, std::string monopolyBlock, int position, int cost, std::shared_ptr<Player> owner, int improvement_level, 
		  int improvementCost, std::vector<int> tuition, bool mortgaged);

  virtual void action(std::shared_ptr<Player> player);
  void buy(std::shared_ptr<Player> player, int price);
  void auction();
  virtual void improveBuy(std::shared_ptr<Player> player);
  virtual void improveSell(std::shared_ptr<Player> player);
  void payTuition(std::shared_ptr<Player> tenant);
  virtual void unmortgage(std::shared_ptr<Player> player);
  virtual void mortgage(std::shared_ptr<Player> player) override;

  virtual int getValue() override; 
  int getImprovementCost(); 
  std::vector<int> getTuition(); 
  bool isOwned();  
  virtual bool isMortgaged() override;
  bool isMonopolyBlockValid();
};

#endif
