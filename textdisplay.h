#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <cstddef> 
#include <iostream>
#include <vector>
#include "observer.h"
#include "square.h"

class Cell;

class TextDisplay: public Observer {
	    std::vector<std::shared_ptr<Square>> squares;
	    std::vector<std::shared_ptr<Player>> players;
	    vector<vector<char>> board;
    	    void updateSquare(int row, int col);
 public:
    explicit TextDisplay(std::vector<std::vector<Square>> textdisplay);
    virtual void notify( Subject & whoNotified ) override;
    virtual void notify() override;
    void print();
};


#endif
