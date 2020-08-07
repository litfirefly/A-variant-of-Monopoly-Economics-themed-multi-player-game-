#include "textdisplay.h"
#include "info.h"
#include "observer.h"
#include "subject.h"
#include <cstddef> 
#include <vector>

using namespace std;

    explicit TextDisplay(std::vector<std::vector<Square>> textdisplay);
    virtual void notify( Subject & whoNotified ) override;
    virtual void notify() override;

    void printSquare(shared_ptr<Square> square);
    void print();

TextDisplay::TextDisplay(vector<shared_ptr<Square>> textdisplay): textdisplay{textdisplay} {
	ifstream board_text("board.txt");
	string line;
	int row=0;
	while (getline(board_text,line)){
		char c;
		int col=0;
		while (file.get(c)){
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
		row = (rown+1)*10;
		col = (coln+1)*10;
		if (square->owned){
			board[row-3][col-9]="O";
			board[row-3][col-8]=":";
			board[row-3][col-7]=square->owned->getPiece();
		}
		else{
			board[row-3][col-9]=" ";
			board[row-3][col-8]=" ";
			board[row-3][col-7]=" ";
		}

		if (squares->improvement_level>0){
			if (improvement_level==1){
				board[row-3][col-6]="I";
			}
			else if (improvement_level==1){
				board[row-3][col-6]="I";
				board[row-3][col-5]="I";
			}
			else if (improvement_level==1){
				board[row-3][col-6]="I";
				board[row-3][col-5]="I";
				board[row-3][col-4]="I";
			}
			else if (improvement_level==4){
				board[row-3][col-6]="I";
				board[row-3][col-5]="V";
			}
			else if (improvement_level>4){
				board[row-3][col-6]="V";
			}
		}
		if (squares->mortgaged){
			board[row-3][col-2] = "M";
		}
		int count=0;
		for (int j=0; i<players.size(); i++){
			if (players[j]->getPosition()==squares->getPosition()){
				board[row-2][col-9+count]=players[j]->getPiece();
				count++;
			}
		}
		

}
void print(){
	vector<vector<char>> board;
	ifstream board_text("board.txt");
	string line;
	int row=0;
	while (getline(board_text,line)){
		char c;
		int col=0;
		while (file.get(c)){
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
		updateSquare(squares[sidel+i], 8-i; 0);
		updateSquare(squares[39-i], 8-i; 9);
	}
	
	//TopRow
	for (int i=0; i<sidel; i++){
		updateSquare([19+i],0,i);
	}

	for (int i=0; i<board.size(); i++){
		for (int j=0; j<board[i].size(); j++){
			cout<<board[i][j]<<endl;
		}
		cout << endl;
	}
}



