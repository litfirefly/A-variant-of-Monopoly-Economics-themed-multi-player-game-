#ifndef PLAYER_H
#define PLAYER_H

#include "square.h"
#include <string>
#include <vector>
#include <memory>
class Player{
	char piece;
	std::string name;
	int position;
	bool inJail;
	int jailTurns;
	bool isBankrupt;
	int money;
	int numOfResidences;
	int numOfGyms;
	std::vector<std::shared_ptr<Square>> squaresOwned;
public:
	Player(char piece, std::string name);
	int getMoney();
	int getWorth(player);
	void printPlayerAssets();
	void transferMoney(std::shared_ptr<Player> to, int amount);
	void transferProperty(std::shared_ptr<Player> to,std::shared_ptr<int>);
	void addSquare(std::shared_ptr<Square>);
	void addMoney(int amount);
	void subtractMoney(int amount);
	void move(position);
	
};

#endif
