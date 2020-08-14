#ifndef _ACADEMICPROPERTY_H_
#define _ACADEMICPROPERTY_H_


#include <iostream>              
#include "player.h"
#include "square.h"

class AcademicProperty: public Square {
	int improvementCost;
	std::vector<int> tuition;
	
public:
  AcademicProperty(std::shared_ptr<Board> board, std::string name, std::string monopolyBlock, int position, int cost, int improvementCost, std::vector<int> tuition);

  virtual void action(std::shared_ptr<Player> player);
  void buy(std::shared_ptr<Player> player, int price);
  void auction();
  void payTuition(std::shared_ptr<Player> tenant);
  virtual void improveBuy(std::shared_ptr<Player> player);
  virtual void improveSell(std::shared_ptr<Player> player);
  virtual void mortgage(std::shared_ptr<Player> player) override;
  virtual void unmortgage(std::shared_ptr<Player> player);

  virtual int getValue() override; 
  int getImprovementCost(); 
  std::vector<int> getTuition(); 
  bool hasMonopoly();

};

#endif

