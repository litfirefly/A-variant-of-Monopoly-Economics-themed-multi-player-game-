#ifndef _GOOSENESTING_H_
#define _GOOSENESTING_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class GooseNesting : public Square {
 public:
        GooseNesting(std::shared_ptr<Board> board,std::string name, int position);
        virtual void action(std::shared_ptr<Player> player) override;
};

#endif
