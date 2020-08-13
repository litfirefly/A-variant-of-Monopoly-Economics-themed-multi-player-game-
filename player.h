#ifndef PLAYER_H
#define PLAYER_H

#include "square.h"
#include <string>
#include <vector>
#include <memory>
class Square;

class Player : public std::enable_shared_from_this<Player>{
	char piece;
	std::string name;
	int position;
	bool inJail;
	int jailTurns;
	bool bankrupt;
	int money;
	int numOfResidences;
	int numOfGyms;
	int timCups;
	std::vector<std::shared_ptr<Square>> squaresOwned;
	std::vector<int> jailLastRoll;
public:
	Player(char piece, std::string name, int money, int position, int timCups);
	std::vector<std::shared_ptr<Square>> getSquares();
	int getMoney();
	std::string getName();
	char getPiece();
	int getPosition();
	int getWorth();
	int getTimCups();
	int getGymNum();
	void addGym();
	void setGymNum(int num);
	int getResNum();
	void setPosition(int pos);
	void addResNum();
	bool isBankrupt();
	int getJailTurns();
	void setJailTurns(int jt);
	bool isInJail();
	void setJail(bool jail);
	void addTimCup();
	void useTimCup();
	void printPlayerAssets();
	void transferMoney(std::shared_ptr<Player> to, int amount, std::vector<std::shared_ptr<Player>> otherPlayers);
	void transferProperty(std::shared_ptr<Player> to,std::shared_ptr<Square> square, std::vector<std::shared_ptr<Player>> players);
	void addSquare(std::shared_ptr<Square>);
	void addMoney(int amount);
	void subtractMoney(int amount, std::vector<std::shared_ptr<Player>> otherPlayers);
	void move(int position);
	std::vector<int> getJailLastRoll();
	void setJailLastRoll(std::vector<int> roll);	
};

#endif
