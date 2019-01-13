#include "game.h"
#define For(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void printSubRow() {
    For(i, 28) {
        if (i%4) {
            cout << ' ';
        } else {
            cout << '|';
        }
    }
    cout << '|' << endl;
}

void printRow(int n) {
    cout << "   ";
    printSubRow();
    char c = 'A' + n;
    cout << ' ' << c << ' ';
    printSubRow();
    cout << "   ";
    For(i, 28) {
        if (i%4) {
            cout << '_';
        } else {
            cout << '|';
        }
    }
    cout << '|' << endl;
}

Game::Game() {
    For(i, 6) {
        printRow(i);
    }
    cout << "  ";
    for (int i = 2; i < 32; ++i) {
        if (i%4 == 1) {
            cout << (i-5)/4;
        } else {
            cout << ' ';
        }
    }
    cout << endl << endl;
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