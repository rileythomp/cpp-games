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
        cout << '|' << "  " << cell.piece << "  ";
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
    //turn = !turn;
}

bool Game::validmove() {
    if (pmove.length() != 5) {return false;}
    For(i,5) {
        if (i == 2 && pmove[i] != ',') {return false;}
        else if (i != 2 && (!isdigit(pmove[i]) || pmove[i]-'0' > 7)) {return false;}
    }
    return true;
}

bool Game::wrongpiece(char piece) {
    return (turn && piece != 'X') ||  (!turn && piece != 'O');
}

bool Game::canmove() {
    int startcol = pmove[0] - '0';
    int startrow = pmove[1] - '0';
    Cell startcell = board[startrow][startcol];
    if (wrongpiece(startcell.piece)) {return false;}

    int nextcol = pmove[3] - '0';
    int nextrow = pmove[4] - '0';
    Cell nextcell = board[nextrow][nextcol];
    if (nextcell.filled) {return false;}

    // jump move
    if (turn && startrow-2 == nextrow) {
        // check col was proper
        if (startcol+2 != nextrow && startcol-2 != nextrow) {return false;}
        // check jumped piece is correct
    } else if (!turn && startrow+2 == nextrow){
        // check col was proper
        if (startcol+2 != nextrow && startcol-2 != nextrow) {return false;}
        // check jumped piece is correct
    }
    return (startrow-1 == nextrow || startrow+1 == nextrow) && 
           (startcol+1 == nextcol || startcol-1 == nextcol);
}

bool Game::haswinner() {
    winner = ' ';
    return false;
}



void Game::play() {
    while (1) {
        cin >> pmove;
        if (validmove() && canmove()) { // pmove valid
            update();
            if (haswinner()) {
                cout << winner << " wins!" << endl;
                break;
            }
        } else {
            cout << "Please enter a valid pmove" << endl;
        }
    }
}