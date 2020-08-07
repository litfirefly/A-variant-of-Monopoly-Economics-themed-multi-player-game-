#ifndef _GOOSENESTING_H_
#define _GOOSENESTING_H_
#include <string>
#include <vector>
#include <memory>
#include "square.h"

class GooseNesting : public Square {
 public:
        GooseNesting(std::string &name, int position);
        void displayGeese(Player &player);
};

#endif

