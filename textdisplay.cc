#include "textdisplay.h"
#include "observer.h"
#include "subject.h"
#include <cstddef> 
#include <vector>
#include <fstream>
using namespace std;

TextDisplay::TextDisplay(shared_ptr<Board> game): game{game} {
	ifstream board_text("board.txt");
	string line;
	while (getline(board_text, line)){
		vector<char> row;
		int string_size = line.length();
		for (int i=0; i<string_size; i++){
			row.push_back(line[i]);
		}
		board.push_back(row);
	}
}



void TextDisplay::notify( Subject & whoNotified){
	//UpdateThisSquare
}

void TextDisplay::notify(){}

void TextDisplay::updateSquare(shared_ptr<Square> square, int rown, int coln){
		int row = (rown*6)+1;
		int col = (coln*9);
		
		if (square->getOwner()!=nullptr){
			//O:79
			//::58	
			board[row+3][col+1]=79;
			board[row+3][col+2]=58;
			board[row+3][col+3]=square->getOwner()->getPiece();
		}
		else{
			board[row+3][col+1]=32;
			board[row+3][col+2]=32;
			board[row+3][col+3]=32;
		}
		
		board[row+3][col+4]=32;
		if (square->getImprovementLevel()>0){
			//I:73
			//V:86
			if (square->getImprovementLevel()==1){
				board[row-3][col+5]=73;
				board[row+3][col+6]=32;
				board[row+3][col+7]=32;
			}
			else if (square->getImprovementLevel()==1){
				board[row+3][col+5]=73;
				board[row+3][col+6]=73;
				board[row+3][col+7]=32;
			}
			else if (square->getImprovementLevel()==1){
				board[row+3][col+5]=73;
				board[row+3][col+6]=73;
				board[row+3][col+7]=73;
			}
			else if (square->getImprovementLevel()==4){
				board[row+3][col+5]=73;
				board[row+3][col+6]=86;
				board[row+3][col+7]=32;
			}
			else if (square->getImprovementLevel()>4){
				board[row+3][col+5]=86;
				board[row+3][col+6]=32;
				board[row+3][col+7]=32;
			}
		}
		else{
				board[row+3][col+5]=32;
				board[row+3][col+6]=32;
				board[row+3][col+7]=32;
		}
		if (square->isOwnable() && square->isMortgaged()){
			//M: 77
			board[row+3][col+8] = 77;
		}
	
		int count=0;
		auto players = game->getPlayers();
		int playerssize = players.size();
		for (int i=0; i<playerssize; i++){
			if (players[i]->getPosition()==square->getPosition()){
				board[row+4][col+1+count]=players[i]->getPiece();
				count++;
			}
		}
		for (int i=count; i<9;i++){
			board[row+4][col+1+count]=32;
		}
}
void TextDisplay::print(){
	auto squares = game->getSquares();
	
	for (int i=0; i<=10; i++){
		updateSquare(squares[i], 10, 10-i);	
	}
	for (int i=11; i<=20; i++){
		updateSquare(squares[i], 20-i, 0);
	}
	for (int i=21; i<=31; i++){
		updateSquare(squares[i], 0, i-21);
	}
	for (int i=30; i<=39; i++){
		updateSquare(squares[i], i-30, 10);
	}
	
	
	int numrows = board.size();
	for (int i=0; i<numrows; i++){
		int numcols = board[i].size();
		for (int j=0; j<numcols; j++){
			cout<<board[i][j];
		}
		cout << endl;
	}
}
