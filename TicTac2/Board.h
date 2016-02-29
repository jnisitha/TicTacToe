#pragma once
#include <vector>

//board states and cell states

const int EMPTY = 0;
const int X_MARK = 1;
const int O_MARK = 2;

const int TIE_GAME = -1;
const int WON_GAME = 10;
const int SIZE = 3; //maximum 9

//how many in a row to win
const int IN_A_ROW = 3;

class Board {
public:

	Board();
	~Board();

	// Initializes the board
	void init();
	// Clears the board
	void clear();
	// Prints the board to standard output
	void print() const;

	// If no player won, returns NO_VAL. Otherwise returns X_VAL, O_VAL or TIE_VAL
	int checkVictory() const;

	// Sets value at x,y spot
	void setVal(int x, int y, int cellState) {
		_board[x][y] = cellState;
	}

	// Gets value at x,y spot
	int getVal(int x, int y) const {
		return _board[x][y];
	}

	// Getters WTF is this?
	//int getSize() const { return _size; }



private:
	// Adds a horizontal line to string for printing
	void addHorizontalLine(std::string& s) const;
	// Adds a horizontal axis guide line to string for printing
	void addGuide(std::string& s) const;

	std::vector< std::vector<int>> _board;
	

};

