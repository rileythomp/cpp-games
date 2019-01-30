#include "game.h"
using namespace std;
#define For(n) for(int i = 0; i < (n); ++i)

void printStart() {
	For(44) {
		if (i != 0) {cout << '_';} 
        else {cout << ' ';}
	}
	cout << endl << '|';
	For(43) {cout << ' ';}
	cout << '|' << endl << '|';
	For(17) {cout << " ";}
	cout << "Connect 4";
  	For(17) {cout << " ";}
	cout << '|' << endl << '|';
	For(43) {cout << '_';}
	cout << '|' << endl << endl << "Type new to start a game!" << endl;
	cout << "To drop a piece, enter it's column number" << endl << endl;;
}

bool invalidMove(string move) {
    return move.length() != 1 || move[0]-'0' < 0 || move[0]-'0' > 6;
}

int main() {
    printStart();
    string cmd;
    while (cin >> cmd) {
        if (cmd == "new") {
            Game game;
            while (1) {
                string move;
                cin >> move;
                if (invalidMove(move)) {cout << "Please enter a valid move" << endl;} 
                else if (game.moveTaken(move)) {cout << "Column full, try again" << endl;} 
                else {
                    game.updateWithMove(move);
                    char winner = game.winner();
                    if (winner == 'X' || winner == 'O') {
                        cout << winner << " wins! Type new to play again" << endl << endl;;
                        break;
                    } else if (game.hasNoMoves()) {
                        cout << "No Moves left, type new to play again" << endl;
                        break;
                    }
                } 
            }
        }
    }
}