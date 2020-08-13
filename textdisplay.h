#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <cstddef> 
#include <iostream>
#include <vector>
#include "observer.h"
#include "square.h"
class Board;

class TextDisplay: public Observer {
	    std::shared_ptr<Board> game;
	    std::vector<std::shared_ptr<Player>> players;
	    std::vector<std::vector<char>> board;
    	    void updateSquare(std::shared_ptr<Square>, int row, int col);
 public:
    TextDisplay(std::shared_ptr<Board> game);
    virtual void notify(std::shared_ptr<Subject>  whoNotified ) override;
    virtual void notify() override;
    void print();
};


#endif
