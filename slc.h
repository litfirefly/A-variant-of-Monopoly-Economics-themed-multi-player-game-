#ifndef _SLC_H_
#define _SLC_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class SLC : public Square {

 public:
        SLC(std::shared_ptr<Board> board,std::string &name, int position);
        virtual void action(Player &player) override;
};

#endif

