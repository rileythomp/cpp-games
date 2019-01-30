#include "game.hh"

using namespace std;

Game::Game() {

    turn = true;
    xLeft = 15;
    oLeft = 15;
    play();
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
    time_t seedtime = time(NULL);
    srand(seedtime);
    while (1) {
        cout << "Enter roll to roll the dice: ";
        string proll;
        cin >> proll;
        if (proll != "roll") {continue;}
        roll1 = rand()%6 + 1;
        roll2 = rand()%6 + 1;
        cout << "You rolled a " << roll1 << " and a " << roll2 << endl;
        cout << "Enter your move: ";
        string pmove;
        // string stream stuff
        cout << "pmove was: " << pmove << endl;
        // cin >> pmove;
        // if (validmove() && canMove()) { 
        //     update();
        //     if (hasWinner()) {
        //         cout << (turn ? 'o' : 'x') << " wins!" << endl;
        //         break;
        //     }
        // } else {
        //     cout << "Please enter a valid pmove" << endl;
        // }
    }
}