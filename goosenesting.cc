#include "goosenesting.h"
#include <memory>
#include <string>
#include <vector>
using namespace std;


GooseNesting::GooseNesting(string &name, int position) : Square{name, "", position, -1, nullptr, -1, false, false} {}

void GooseNesting::displayGeese(Player &player){
	cout << "A flock geese is attacking. Take cover!" << endl;
}

