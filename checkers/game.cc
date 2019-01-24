#include "game.h"

#define For(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

void printSubRow(char c) {
    For(i, 48) {
        if (i%6 == 0) {cout << '|';} 
        else {cout << c;}
    }
    cout << '|' << endl;
}

void Game::printrow(int i) {
    printSubRow(' ');
    for (auto cell : board[i]) {
        cout << '|' << "  " << cell.colour << "  ";
    }
    cout << "| " << i << endl;
    printSubRow('_');
}

void Game::print() {
    cout << ' ';
    For(i,47) {cout << '_';}
    cout << endl;
    For(i, 8) {printrow(i);}
    For(i, 48) {
        if (i%6 == 3) {cout << (i-3)/6;} 
        else {cout << ' ';}
    }
    cout << endl << endl;  
    cout << (turn ? 'X' : 'O') << "'s turn";
    cout << endl << endl;
}

Game::Game() {
    For(i,  8) {
        vector<Cell> row;
        For(j, 8) {
            if (i < 3 && ((i+j)%2)) {row.push_back(Cell('O'));} 
            else if (i > 4 && ((i+j)%2)) {row.push_back(Cell('X'));} 
            else {row.push_back(Cell());}
        }
        board.push_back(row);
    }
    turn = true;
    print();
    play();
}

void Game::update() {
    turn = !turn;
}

bool validmove(string move) {
    return true;
}

bool Game::canmove() {
    return true;
}

bool Game::haswinner() {
    winner = ' ';
    return false;
}



void Game::play() {
    while (1) {
        string playermove;
        cin >> playermove;
        if (validmove(move)) { // move valid
            move = playermove;
            if (canmove()) {
                update();
                if (haswinner()) {
                    cout << winner << " wins!" << endl;
                    break;
                }
            } 
            else {cout << "Sorry, you can't go there" << endl;}
        } else {
            cout << "Please enter a valid move" << endl;
        }
    }
}