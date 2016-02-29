#pragma once

#include"Board.h"

struct MasterMove {
	MasterMove() {};
	MasterMove(int Score) : score(Score) {};
	int x;
	int y;
	int score;
};

class Master {
public:
	//Initialize master player
	void init(int masterPlayer);
	void makeMove(Board& board, int masterPlayer);
	Master();
	~Master();

private:
	MasterMove _getBest(Board& board, int player);
	int _masterPlayer;
	int _otherPlayer;
};



