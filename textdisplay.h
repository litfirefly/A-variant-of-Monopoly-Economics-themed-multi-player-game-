#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <cstddef> 
#include <iostream>
#include <vector>
#include "observer.h"
#include "square.h"


class TextDisplay: public Observer {
	    std::vector<std::shared_ptr<Square>> squares;
	    std::vector<std::shared_ptr<Player>> players;
	    std::vector<std::vector<char>> board;
    	    void updateSquare(std::shared_ptr<Square>, int row, int col);
 public:
    explicit TextDisplay(std::vector<std::shared_ptr<Square>> squares);
    virtual void notify( Subject & whoNotified ) override;
    virtual void notify() override;
    void print();
};


#endif
