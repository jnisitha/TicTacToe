#include "stdafx.h"
#include "Master.h"


void Master::init(int masterPlayer) {
	_masterPlayer = masterPlayer;
	if (_masterPlayer == X_MARK) {
		_otherPlayer = O_MARK;
	} else {
		_otherPlayer = X_MARK;
	}
}

void Master::makeMove(Board & board, int masterPlayer) {
	Master::init(masterPlayer);

	MasterMove bestMove = _getBest(board, _masterPlayer);
	board.setVal(bestMove.x, bestMove.y, _masterPlayer);
}

Master::Master() {}


Master::~Master() {}

MasterMove Master::_getBest(Board & board, int player) {
	
	int rv = board.checkVictory();
	if (rv == WON_GAME && player == _masterPlayer) { //This is to see if the previous move was a win. by this time the player has changed.
		return MasterMove(-10);
	} else if (rv == WON_GAME && player == _otherPlayer) {
		return MasterMove(10);
	} else if (rv == TIE_GAME) {
		return MasterMove(0);
	}

	std::vector<MasterMove> moves;

	//recursive function to get moves vector
	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) {

			if (board.getVal(i,j) == EMPTY) {

				MasterMove move;
				move.x = i;
				move.y = j;
				board.setVal(i, j, player);
				if (player == _masterPlayer) {
					move.score = _getBest(board, _otherPlayer).score;
				} else {
					move.score = _getBest(board, _masterPlayer).score;
				}
				moves.push_back(move);
				board.setVal(i, j, EMPTY);
			}
		}
	}

	//pick the best move for the current player
	int bestMove = 0;
	if (player == _masterPlayer) {
		int bestScore = -1000000;
		for (int i = 0; i < moves.size(); i++) {
			if (moves[i].score > bestScore) {
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	} else {
		int bestScore = 1000000;
		for (int i = 0; i < moves.size(); i++) {
			if (moves[i].score < bestScore) {
				bestMove = i;
				bestScore = moves[i].score;
			}
		}

	}
	//return the best move
	return moves[bestMove];
	
}
