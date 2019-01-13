#include "game.h"
#define For(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void printRow() {
    For(i, 22) {
        if (i%4) {
            cout << ' ';
        } else {
            cout << '|';
        }
    }
    cout << endl;
}

Game::Game() {
    cout << "start of game, print the board" << endl;
    For(i, 15){
        if (i%2) {
            cout <<  '_';
        } else {
            cout << ' ';
        }
    }
    cout << endl;
}

bool Game::hasWinner() {
    return false;
}

void Game::print() {
    cout << "print the board and who's move it is" << endl;
}

void Game::updateWithMove(string move) {
}

bool Game::hasNoMoves() {
    return false;
}

void Game::end() {
    cout << "game has ended, type new to play again" << endl;
}