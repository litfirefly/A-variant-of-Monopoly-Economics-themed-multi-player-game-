#ifndef _BOARD_H_
#define _BOARD_H_
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "square.h"

class Board {
	const int maxNumOfPlayers = 8;
  	int numOfPlayers;
  	vector<shared_ptr<Player>> playerList;
	vector<shared_ptr<Square>> squares;
	const vector<string> pieces = {"car", "iron", "lantern", "thimble", "shoe", "tophat", "horse", "battleship"};
	vector<bool> piecesChosen;
	bool testMode = false;

	const vector<int> AL = {2, 10, 30, 90, 160, 250};
	const vector<int> ML = {4, 20, 60, 180, 320, 450};
	const vector<int> ECH = {6, 30, 90, 270, 400, 550};
	const vector<int> PAS = {6, 30, 90, 270, 400, 550};
	const vector<int> HH = {8, 40, 100, 300, 450, 600};
	const vector<int> RCH = {10, 50, 150, 450, 625, 750};
	const vector<int> DWE = {10, 50, 150, 450, 625, 750};
	const vector<int> CPH = {12, 60, 180, 500, 700, 900};
	const vector<int> LHI = {14, 70, 200, 550, 750, 950};
	const vector<int> BMH = {14, 70, 200, 550, 750, 950};
	const vector<int> OPT = {16, 80, 220, 600, 800, 1000};
	const vector<int> EV1 = {18, 90, 250, 700, 875, 1050};
        const vector<int> EV2 = {18, 90, 250, 700, 875, 1050};
	const vector<int> EV3 = {20, 100, 300, 750, 925, 1100};
	const vector<int> PHYS = {22, 110, 330, 800, 975, 1150};
	const vector<int> B1 = {22, 110, 330, 800, 975, 1150};
	const vector<int> B2 = {24, 120, 360, 850, 1025, 1200};
	const vector<int> EIT = {26, 130, 390, 900, 1100, 1275};
	const vector<int> ESC = {26, 130, 390, 900, 1100, 1275};
	const vector<int> C2 = {28, 150, 450, 1000, 1200, 1400};
	const vector<int> MC = {35, 175, 500, 1100, 1300, 1500};
	const vector<int> DC = {50, 200, 600, 1400, 1700, 2000};

  public:
        void initialize(int numOfPlayers);
	void setTesting(int numOfPlayers);
	void playTurn();
	void loadGame();
	void saveGame();
	void rollDice();
};

#endif
