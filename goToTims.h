#ifndef _GOTOTIMS_H_  
#define _GOTOTIMS_H_ 
#include <string> 
#include <vector>  
#include <memory>
#include "square.h"

class GoToTims : public Square {  
public:    
	GoToTims(std::string &name, int position);  
	void moveToJail(Player &player);
	string getName();
        int getPosition();
        bool getImprovable();
        bool getOwnable(); 
};

#endif
