#include "textdisplay.h"
#include "info.h"
#include "observer.h"
#include "subject.h"
#include <cstddef> 
#include <vector>

using namespace std;

TextDisplay::TextDisplay(size_t n): n{n} {
	for (size_t row = 0; row < n; row++){
		vector<char> row_vec;
		for (size_t col = 0; col < n; col++){	
			row_vec.push_back(95);
		}
		textdisplay.push_back(row_vec);
	}
}

void TextDisplay::notify( Subject & whoNotified){
	Info temp = whoNotified.getInfo();
	if (temp.state==State::Alive){
		textdisplay[temp.row][temp.col] = 88;
	}
	else {
		textdisplay[temp.row][temp.col] = 95;
	}
}

void TextDisplay::notify(){}

ostream &operator<<(ostream &out, const TextDisplay &td){
	for (size_t row =0; row < td.n; row++){
		for (size_t col=0; col < td.n; col++){
			out << td.textdisplay[row][col];
		}
		if (row!=(td.n-1)){
			out << endl;
		}
	}
	return out;
}


