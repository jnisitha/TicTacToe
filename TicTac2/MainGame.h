#pragma once
#include<string>
#include<iostream>
#include"Board.h"
#include"Amateur.h"
#include"Master.h"

enum class GameState{MENU, AMATEUR, MASTER, TRAIN_NN,TRAIN_GA, EXIT};

class MainGame {
public:

	
	void run();
	MainGame();
	~MainGame();

private:

	void _handleMenu();
	//void _gameLoop();
	void _changePlayer();
	void _displayresult(int gameEnd);
	void _amateurMove();
	void _humanMove();
	void _masterMove();


	Board _board;
	GameState _gameState;
	int _currentPlayer;
	int _pcPlayer;
	int _humanPlayer;
	Amateur _amateur;
	Master _master;

};

