#ifndef _GOTOTIMS_H_  
#define _GOTOTIMS_H_ 
#include <string> 
#include <vector>  
#include <memory>
#include "square.h"

class GoToTims : public Square {  
public:    
	GoToTims(std::shared_ptr<Board> board,std::string &name, int position);  
	virtual void action(Player &player) override;
};

#endif

