#ifndef _SQUARE_H_
#define _SQUARE_H_
#include "player.h"
#include "board.h"
#include <string>
#include <vector>
#include <memory>

class Square{
	std::shared_ptr<Board> board;
	static int rollUpCards = 0;
	static int gymsOwned = 0;
	std::string name;
	std::string monopolyBlock;	
	int position;
	int cost;
	shared_ptr<Player> owner;
	int improvement_level;	
	bool ownable;
	bool improvable;
 public:
  Square(std::shared_ptr<Board> board, std::string name, std::string monopolyBlock, int position, int cost, shared_ptr<Player> owner, int improvement_level, bool ownable, bool improvable);
  std::string getName();
  std::string getMonopolyBlock();
  int getPosition();
  int getCost();
  shared_ptr<Player> getOwner();
  int getImprovementLevel();
  bool getOwnable();
  bool getImprovable();
  virtual action(shared_ptr<Player> player);
  virtual ~Square()=0;
  
};

#endif

