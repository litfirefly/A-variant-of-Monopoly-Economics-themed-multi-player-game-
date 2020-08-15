#ifndef _TUITION_H_
#define _TUITION_H_
#include <iostream>
#include "square.h"

class Tuition : public Square {
 public:
        Tuition(Board * board,std::string name, int position);
        virtual void action(std::shared_ptr<Player> player) override;
};

#endif

