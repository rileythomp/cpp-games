#include "game.h"
using namespace std;

void Game::start() {
    cout << "start of game" << endl;
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
    return true;
}

void Game::end() {
    cout << "game has ended" << endl;
}