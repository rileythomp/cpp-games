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

void Game::printboard() {
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
    xleft = 12;
    oleft = 12;
    printboard();
    play();
}

void Game::update() {
    startcol = pmove[0] - '0';
    startrow = pmove[1] - '0';
    nextcol = pmove[3] - '0';
    nextrow = pmove[4] - '0';
    board[startrow][startcol] = Cell();
    board[nextrow][nextcol] = Cell((turn ? 'X' : 'O'));

    bool jumping = startcol+2 == nextcol || startcol-2 == nextcol;
    if (jumping) {
        jumpedrow = startrow+(turn ? -1: 1);
        jumpedcol = startcol+(startcol+2 == nextcol ? 1 : -1);
        board[jumpedrow][jumpedcol] = Cell();
        turn ? oleft-- : xleft--;
    }

    turn = !turn;
    printboard();
}

bool Game::validmove() {
    if (pmove.length() != 5) {return false;}
    For(i,5) {
        if (i == 2 && pmove[i] != ',') {return false;}
        else if (i != 2 && (!isdigit(pmove[i]) || pmove[i]-'0' > 7)) {return false;}
    }
    return true;
}

bool Game::canjump() {
    bool wrongcolumn = startcol+2 != nextcol && startcol-2 != nextcol;
    if (wrongcolumn) {return false;}
    jumpedrow = startrow+(turn ? -1: 1);
    jumpedcol = startcol+(startcol+2 == nextcol ? 1 : -1);
    bool jumpingRightPiece =  board[jumpedrow][jumpedcol].piece == (turn ? 'O' : 'X');
    return jumpingRightPiece;
}

bool Game::canmove() {
    startcol = pmove[0] - '0';
    startrow = pmove[1] - '0';
    char startpiece = board[startrow][startcol].piece;
    bool movingWrongPiece = turn ? startpiece != 'X' : startpiece != 'O';
    if (movingWrongPiece) {return false;}

    nextcol = pmove[3] - '0';
    nextrow = pmove[4] - '0';
    bool nextfilled = board[nextrow][nextcol].filled;
    if (nextfilled) {return false;}

    bool attemptingJump = (turn ? startrow-2 == nextrow : startrow+2 == nextrow);
    if (attemptingJump) {
        return canjump();
    }

    bool legalmove = (turn ? startrow-1 == nextrow : startrow+1 == nextrow) && 
                     (startcol+1 == nextcol || startcol-1 == nextcol);
    return legalmove;
}

bool Game::haswinner() {
    if (oleft == 0 || xleft == 0) {
        winner = turn ? 'O': 'X';
        return true;
    }
    return false;
}



void Game::play() {
    while (1) {
        cin >> pmove;
        if (validmove() && canmove()) { 
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