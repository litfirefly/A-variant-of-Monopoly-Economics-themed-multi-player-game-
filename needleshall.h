#ifndef _NEEDLESHALL_H_
#define _NEEDLESHALL_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class NeedlesHall : public Square {

 public:
        NeedlesHall(std::shared_ptr<Board> board,std::string name, int position);
        virtual void action(std::shared_ptr<Player> player) override;
};

#endif
