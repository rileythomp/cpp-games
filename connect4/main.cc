#include "game.h"
using namespace std;
#define For(n) for(int i = 0; i < (n); ++i)

void printStart() {
	For(44) {
		if (i != 0) {
			cout << '_';
		} else {
			cout << ' ';
		}
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
	cout << "Moves should be entered in the form LetterNumber (B3)" << endl;
}

bool validMove(string move) {
    return move == "x"; 
}

int main() {
    printStart();
    string cmd;
    while (cin >> cmd) {
        if (cmd == "new") {
            Game game; // print board 
            while (!game.hasWinner()) {
                string move;
                cin >> move;
                if (validMove(move)) {
                    game.updateWithMove(move);
                    if (game.hasWinner() || game.hasNoMoves()) {
                        game.end();
                        break;
                    }
                    game.print();
                } else {
                    cout << "Please enter a valid move" << endl;
                }
            }
        }
    }
}