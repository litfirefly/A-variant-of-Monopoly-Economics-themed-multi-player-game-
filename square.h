#ifndef _SQAURE_H_
#define _SQUARE_H_

#include <string>
#include <vector>
#include <memory>

class Square{
	std::string name;
	std::string monopolyBlock;	
	int position;
	bool ownable;
	bool improvable;
 public:
  Square(std::string name, std::string monopolyBlock, int position, bool ownable, bool improvable);
  std::string getName();
  std::string getMonopolyBlock();
  int getPosition();
  bool getOwnable();
  bool getImprovable();
  virtual void printSquare()=0;
  virtual ~Square()=0;
  
};

#endif

