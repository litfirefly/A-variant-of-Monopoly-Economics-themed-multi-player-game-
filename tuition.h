#ifndef _TUITION_H_
#define _TUITION_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class Tuition : public Square {
 public:
        Tuition(std::shared_ptr<Board> board,std::string name, int position);
        virtual void action(std::shared_ptr<Player> player) override;
};

#endif

