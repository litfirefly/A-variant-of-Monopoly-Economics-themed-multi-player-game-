#include "textdisplay.h"
#include "observer.h"
#include "subject.h"
#include <cstddef> 
#include <vector>
#include <fstream>
using namespace std;

TextDisplay::TextDisplay(vector<shared_ptr<Square>> textdisplay): squares{squares} {
	ifstream board_text("board.txt");
	string line;
	int row=0;
	while (getline(board_text,line)){
		char c;
		int col=0;
		while (board_text.get(c)){
			board[row][col]=c;
			col++;
		}
		row++;
	}
}



void TextDisplay::notify( Subject & whoNotified){
	//UpdateThisSquare
}

void TextDisplay::notify(){}

void TextDisplay::updateSquare(shared_ptr<Square> square, int rown, int coln){
		int row = (rown+1)*10;
		int col = (coln+1)*10;
		if (square->getOwner()!=nullptr){
			//O:79
			//::58
			board[row-3][col-9]=79;
			board[row-3][col-8]=58;
			board[row-3][col-7]=square->getOwner()->getPiece();
		}
		else{
			// 32
			board[row-3][col-9]=32;
			board[row-3][col-8]=32;
			board[row-3][col-7]=32;
		}
		
		if (square->getImprovementLevel()>0){
			//I:73
			//V:86
			if (square->getImprovementLevel()==1){
				board[row-3][col-6]=73;
			}
			else if (square->getImprovementLevel()==1){
				board[row-3][col-6]=73;
				board[row-3][col-5]=73;
			}
			else if (square->getImprovementLevel()==1){
				board[row-3][col-6]=73;
				board[row-3][col-5]=73;
				board[row-3][col-4]=73;
			}
			else if (square->getImprovementLevel()==4){
				board[row-3][col-6]=73;
				board[row-3][col-5]=86;
			}
			else if (square->getImprovementLevel()>4){
				board[row-3][col-6]=86;
			}
		}
		if (square->isOwnable() && square->isMortgaged()){
			//M: 77
			board[row-3][col-2] = 77;
		}
		int count=0;
		int playerssize = players.size();
		for (int i=0; i<playerssize; i++){
			if (players[i]->getPosition()==square->getPosition()){
				board[row-2][col-9+count]=players[i]->getPiece();
				count++;
			}
		}
}
void TextDisplay::print(){
	vector<vector<char>> board;
	ifstream board_text("board.txt");
	string line;
	int row=0;
	while (getline(board_text,line)){
		char c;
		int col=0;
		while (board_text.get(c)){
			board[row][col]=c;
			col++;
		}
		row++;
	}
	int sidel = squares.size()/4;
	
	//botRows
	for (int i=0; i<sidel; i++){
		updateSquare(squares[i], 9, 9-i);	
	}

	//colRows
	for (int i=0; i<sidel-2; i++){
		updateSquare(squares[sidel+i], 8-i, 0);
		updateSquare(squares[39-i], 8-i, 9);
	}
	
	//TopRow
	for (int i=0; i<sidel; i++){
		updateSquare(squares[19+i],0,i);
	}
	int numrows = board.size();
	for (int i=0; i<numrows; i++){
		int numcols = board[i].size();
		for (int j=0; j<numcols; j++){
			cout<<board[i][j]<<endl;
		}
		cout << endl;
	}
}



