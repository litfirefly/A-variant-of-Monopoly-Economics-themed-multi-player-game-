#ifndef _BOARD_H_
#define _BOARD_H_
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "square.h"
#include "player.h"

class Square;
class Player;
class Board : public std::enable_shared_from_this<Board>{
	const int maxNumOfPlayers = 8;
  	int numOfPlayers;
	int rollUpCards=0;
	std::vector<std::shared_ptr<Player>> playerList;
	std::vector<std::shared_ptr<Square>> squares;
	const std::vector<std::string> pieces = {"G", "B", "D", "P", "S", "$", "L", "T"};
	std::vector<bool> piecesChosen;
	bool testMode = false;

	const std::vector<int> AL = {2, 10, 30, 90, 160, 250};
	const std::vector<int> ML = {4, 20, 60, 180, 320, 450};
	const std::vector<int> ECH = {6, 30, 90, 270, 400, 550};
	const std::vector<int> PAS = {6, 30, 90, 270, 400, 550};
	const std::vector<int> HH = {8, 40, 100, 300, 450, 600};
	const std::vector<int> RCH = {10, 50, 150, 450, 625, 750};
	const std::vector<int> DWE = {10, 50, 150, 450, 625, 750};
	const std::vector<int> CPH = {12, 60, 180, 500, 700, 900};
	const std::vector<int> LHI = {14, 70, 200, 550, 750, 950};
	const std::vector<int> BMH = {14, 70, 200, 550, 750, 950};
	const std::vector<int> OPT = {16, 80, 220, 600, 800, 1000};
	const std::vector<int> EV1 = {18, 90, 250, 700, 875, 1050};
        const std::vector<int> EV2 = {18, 90, 250, 700, 875, 1050};
	const std::vector<int> EV3 = {20, 100, 300, 750, 925, 1100};
	const std::vector<int> PHYS = {22, 110, 330, 800, 975, 1150};
	const std::vector<int> B1 = {22, 110, 330, 800, 975, 1150};
	const std::vector<int> B2 = {24, 120, 360, 850, 1025, 1200};
	const std::vector<int> EIT = {26, 130, 390, 900, 1100, 1275};
	const std::vector<int> ESC = {26, 130, 390, 900, 1100, 1275};
	const std::vector<int> C2 = {28, 150, 450, 1000, 1200, 1400};
	const std::vector<int> MC = {35, 175, 500, 1100, 1300, 1500};
	const std::vector<int> DC = {50, 200, 600, 1400, 1700, 2000};
	
	void trade(std::vector<std::string> command);
  public:
        void initialize(int numOfPlayers);
	void setTesting();
	void playTurn();
	void loadGame(std::string load);
	std::string saveGame();
	std::vector<int> rollDice(int d1, int d2);
	std::vector<std::shared_ptr<Player>> getPlayers();
	std::vector<std::shared_ptr<Square>> getSquares();
	int getRollUpCards();
	void setRollUpCards(int cards);
};

#endif

