#ifndef _TUITION_H_
#define _TUITION_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class Tuition : public Square {
 public:
        Tuition(std::string &name, int position);
        void payTuition(Player &player);
	string getName();
        int getPosition();
        bool getImprovable();
        bool getOwnable();
};

#endif
