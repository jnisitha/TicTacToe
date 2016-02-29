#include "stdafx.h"
#include "MainGame.h"


void MainGame::_handleMenu() {

	printf(" WELCOME TO TIC TACT TOE\n");
	printf("Enter 'Master' to play against master, \n 'Amateur' to play against amateur, \n'TrainNN' to train the neural net, 'TrainGA' to train using Genetics, 'Exit' to quit\n");

	std::string userInput;
	std::cin >> userInput;

	if (userInput == "Exit") {
		_gameState = GameState::EXIT;
	}

	if (userInput == "Amateur") {
		_gameState = GameState::AMATEUR;
	}
	
	if (userInput == "Master") {
		_gameState = GameState::MASTER;
	}

	if (userInput == "TrainNN") {
		_gameState = GameState::TRAIN_NN;
	}

	if (userInput == "TrainGA") {
		_gameState = GameState::TRAIN_GA;
	}

	bool isValid;
	char input = ' ';

	if (userInput != "Exit" && userInput != "TrainNN" && userInput != "TrainGA") {
		// COPIED FROM BEN---------
		printf("\nWould you like to be X or O: (O goes first!!)");
		do {
			isValid = true;
			if (!(std::cin >> input)) {
				std::cout << "Invalid input!";
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				isValid = false;
			} else if (input == 'x' || input == 'X') {
				_humanPlayer = X_MARK;
				_pcPlayer = O_MARK;
				_currentPlayer = _pcPlayer;
			} else if (input == 'o' || input == 'O') {
				_humanPlayer = O_MARK;
				_pcPlayer = X_MARK;
				_currentPlayer = _humanPlayer;
			} else {
				std::cout << "Must enter X or O!";
				isValid = false;
			}
		} while (isValid == false);
		//END OF COPY FROM BEN---------
	}
	
}

void MainGame::_changePlayer() {
	if (_currentPlayer == _humanPlayer) {
		_currentPlayer = _pcPlayer;
	} else {
		_currentPlayer = _humanPlayer;
	}
}

void MainGame::_displayresult(int gameEnd) {
	if (gameEnd == WON_GAME) {
		if (_currentPlayer == _humanPlayer) {
			printf("YOU WON!!");
		} else {
			printf("you lost :(");
		}
	} else {
		printf("Game Drawn");
	}
}

void MainGame::_amateurMove() {
	_amateur.move(_board,_pcPlayer);
}

void MainGame::_humanMove() {
	bool moveMade = false;
	while (moveMade == false) {
		
		int x, y;
		
		printf("Enter X: ");
		std::cin >> x;
		printf("Enter Y: ");
		std::cin >> y;
		x--;
		y--;
		
		if (_board.getVal(x, y) == EMPTY) {
			_board.setVal(x, y, _humanPlayer);
			moveMade = true;
		} else {
			printf("place taken!! try another spot");
		}
	} 
	
}

void MainGame::_masterMove() {
	_master.makeMove(_board, _pcPlayer);
}

void MainGame::run() {
	_handleMenu();
	_board.init();
	while (_gameState != GameState::EXIT) {

		//print the board

		_board.print();

		//players move
		if (_gameState == GameState::AMATEUR) {
			if (_currentPlayer == _humanPlayer) {
				_humanMove();
			} else {
				_amateurMove();
			}
		} else if (_gameState== GameState::MASTER) {
			if (_currentPlayer == _humanPlayer) {
				_humanMove();
			} else {
				_masterMove();
			}
		}

		//Check for a win situation
		int gameEnd = _board.checkVictory();

		if (gameEnd == WON_GAME || gameEnd == TIE_GAME) {
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			_board.print();
			_displayresult(gameEnd);//change this 
			system("PAUSE");
		} else {
		    _changePlayer();

			//cheap way to clear the command prompt
			for (int i = 0; i < 3; i++) {
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			}
		}

	}

}

MainGame::MainGame() {}


MainGame::~MainGame() {}
