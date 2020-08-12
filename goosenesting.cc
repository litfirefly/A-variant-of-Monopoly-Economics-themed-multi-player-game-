#include "goosenesting.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


GooseNesting::GooseNesting(std::shared_ptr<Board> board,string name, int position) : Square{board, name, "", position, -1, nullptr, -1, false, false} {}

void GooseNesting::action(shared_ptr<Player> player){
	cout << "A flock geese is attacking. Take cover!" << endl;
}
