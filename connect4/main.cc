#include <string>
#include <iostream>
#include "game.h"
using namespace std;

void printStart() {
    cout << "Start of game" << endl;
}

bool validMove(string move) {
    return move == "x";
}

int main() {
    printStart();
    string cmd;
    while (cin >> cmd) {
        if (cmd == "new") {
            Game game;
            game.start();
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