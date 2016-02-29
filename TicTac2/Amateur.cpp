#include "stdafx.h"
#include "Amateur.h"

void Amateur::move(Board& board,int amateurPlayer) {
	int x, y;
	bool isDone = false;
	while (isDone == false) {
		x = rand() % SIZE;
		y = rand() % SIZE;
		if (board.getVal(x,y) == EMPTY) {
			board.setVal(x, y, amateurPlayer);
			isDone = true;
		}
	}
}

Amateur::Amateur() {}


Amateur::~Amateur() {}
