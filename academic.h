#ifndef _ACADEMICPROPERTY_H_
#define _ACADEMICPROPERTY_H_

#include "square.h"

class AcademicProperty: public Square {
	int improvementCost;
	vector<int> tuition;
	Player owner;
	bool owned;
	bool monopolyBlockValid; 
	bool mortgaged;
	int improvementLevel;
	
public:
  AcademicProperty(std::string name, std::string monopolyBlock, int position, std::string owner, int improvementCost, vector<int> tuition, std::string monopolyBlock);
  void buy(std::string player);
  void buyImprovement(std::string player);
  void sellImprovement(std::string player);
  void mortgage(std::string player);
  void unmortgage(std::string player);
  void payTuition(std::string player);
  void auction(std::string player);

  std::string getName();
  int getPosition();
  bool getOwnable();
  bool getImprovable();
  int getImprovementCost(); 
  vector<int> getTuition(); 
  std::string getOwner();
  bool isOwned();  
  bool isMortaged();
  int getImprovementLevel();
  bool isMonopolyBlockValid();
};

#endif
