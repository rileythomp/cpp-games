#include "game.h"

using namespace std;

Game::Game() {
    turn = true;
    xLeft = 15;
    oLeft = 15;
}

bool validmove() {
    return true;
}

bool Game::canMove() {
    return true;
}

void Game::update() {

}

bool Game::hasWinner() {
    return false;
}



void Game::play() {
    while (1) {
        cin >> pmove;
        if (validmove() && canMove()) { 
            update();
            if (hasWinner()) {
                cout << (turn ? 'o' : 'x') << " wins!" << endl;
                break;
            }
        } else {
            cout << "Please enter a valid pmove" << endl;
        }
    }
}