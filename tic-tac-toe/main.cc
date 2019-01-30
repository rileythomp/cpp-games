#include <string>
#include <iostream>
#include <exception>
#include "game.h"
using namespace std;

#define For(i,n) for(int i = 0; i < (n); ++i)

void printStart() {
	For(i, 42) {
		if (i != 0) {cout << '_';} 
		else {cout << ' ';}
	}
	cout << endl << '|';
	For(i, 41) {cout << ' ';}
	cout << '|' << endl << '|';
	For(i, 15) {cout << " ";}
	cout << "Tic-Tac-Toe";
  	For(i, 15) {cout << " ";}
	cout << '|' << endl << '|';
	For(i, 41) {cout << '_';}
	cout << '|' << endl << endl << "Type new to start a game!" << endl;
	cout << "Moves are integers, where 0 is the top left cell, 2 is top middle, 4 is middle left, etc." << endl;
}

int main () {
  printStart();
  string cmd;
    while (cin >> cmd) {
		if (cmd == "new") {
			Game game;
			game.printBoard();
			game.turnMessage();
			while (!game.hasWinner()) {
				string num;
				int move;
				cin >> num;
				try {move = stoi(num);} 
				catch (exception& e) {
					cout << "Please enter a valid move" << endl;
					continue;
				}
				if (move > -1 && move < 9) {
					game.update(move);
					if (game.hasWinner()) {
						game.printWinner();
						break;
					} else if (game.numMoves() > 8) {
						game.printDraw();
						break;
					} 
					else {game.turnMessage();}
				} else {cout << "Please enter a valid move" << endl;}
			}
		} else if (cmd == "quit") {
			cout << "Thanks for playing!" << endl;
			break;
		}
    }
  return 0;
}
