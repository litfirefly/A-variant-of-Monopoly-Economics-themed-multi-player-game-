#ifndef _ACADEMICPROPERTY_H_
#define _ACADEMICPROPERTY_H_

#include "square.h"

class AcademicProperty: public Square {
	int improvementCost;
	vector<int> tuition;
	std::string owner;
	bool owned;
	bool mortgaged;
	int improvementLevel;
	
public:
  AcademicProperty(std::string value, std::shared_ptr<Tree> left, std::shared_ptr<Tree> right);
  AcademicProperty(std::string name, std::string monopolyBlock, int position, std::string owner, int improvementCost, vector<int> tuition, std::string monopolyBlock);
  int getImprovementCost();
  vector<int> getTuition();
  std::string getOwner();
  bool isOwned();
  bool isMortaged();
  int getImprovementLevel();
  void buy(std::string player);
  void sell(std::string player);
  void buyImprovement(std::string player);
  void sellImprovement(std::string player);
  void mortgage(std::string player);
  void unmortgage(std::string player);
  void payTuition(std::string player);
  void auction(std::string player);

  Square(std::string name,mb, int position, bool ownable, bool improvable);
  std::string getName();
  int getPosition();
  bool getOwnable();
  bool getImprovable();
  virtual ~Square()=0;
};

#endif

