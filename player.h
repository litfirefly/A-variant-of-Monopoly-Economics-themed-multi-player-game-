#ifndef PLAYER_H
#define PLAYER_H

#include "Square.h"
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
	void printPlayerAssets();
	int transferMoney(std::shared_ptr<Player> to, int amount);
	int transferProperty(std::shared_ptr<Player> to,std::shared_ptr<int>);
	void addSquare(std::shared_ptr<Square>);
	void addMoney(int amount);
	int subtractMoney(int amount);
};

#endif
