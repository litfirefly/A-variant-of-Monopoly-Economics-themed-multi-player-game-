#ifndef _SQUARE_H_
#define _SQUARE_H_
#include "board.h"
#include "subject.h"
#include <string>
#include <vector>
#include <memory>
class Player;
class Board;
class Square: public Subject{
	std::shared_ptr<Board> board;	
	std::string name;
	std::string monopolyBlock;	
	int position;
	int cost;
	std::shared_ptr<Player> owner;
	int improvement_level;	
	bool ownable;
	bool improvable;
 public:
  Square(std::shared_ptr<Board> board, std::string name, std::string monopolyBlock, int position, int cost, 
		  std::shared_ptr<Player> owner, int improvement_level, bool ownable, bool improvable);

  std::shared_ptr<Board> getBoard();
  virtual std::string getName() override;
  std::string getMonopolyBlock();
  int getPosition();
  int getCost();
  std::shared_ptr<Player> getOwner();
  void setOwner(std::shared_ptr<Player> player);
  int getImprovementLevel();
  void setImprovementLevel(int level);
  bool isOwnable();
  bool isImprovable();
  bool isMortgaged();  
  virtual int getValue();
  virtual bool isGym();
  virtual void mortgage(std::shared_ptr<Player> player);
  virtual void unmortgage(std::shared_ptr<Player> player);
  virtual void improveBuy(std::shared_ptr<Player> player);
  virtual void improveSell(std::shared_ptr<Player> player);
  virtual void action(std::shared_ptr<Player> player);
  virtual void auction();
  virtual ~Square()=0;

};

#endif

