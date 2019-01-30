#include "game.h"
#include <exception>

#define For(i, n) for(int i = 0; i < (n); ++i)

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      

using namespace std;

void printSubRow(char c) {
    For(i, 48) {
        if (i%6 == 0) {cout << '|';} 
        else {cout << c;}
    }
    cout << '|' << endl;
}

char printChecker(Cell* cell) {
    return cell->checker->letter + (cell->checker->isKing ? -32 : 0);
}

void Game::printrow(int i) {
    printSubRow(' ');
    vector<Cell*> row = board[i];
    for (auto cell : row) {
        cout << '|' << "  " << (cell->checker && cell->checker->isKing ? BOLDRED : "") << (cell->hasChecker ? printChecker(cell) : ' ') << (cell->checker && cell->checker->isKing ? RESET : "") << "  ";
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
    cout << (turn ? 'x' : 'o') << "'s turn";
    cout << endl << endl;
}

Game::Game() {
    For(i,  8) {
        vector<Cell*> row;
        For(j, 8) {
            Cell* cell = new Cell();
            if (i < 3 && ((i+j)%2)) {
                cell->hasChecker = true;
                cell->checker = new Checker('o');
            } 
            else if (i > 4 && ((i+j)%2)) {
                cell->hasChecker = true;
                cell->checker = new Checker('x');
            } 
            row.push_back(cell);
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

    board[nextrow][nextcol]->checker = board[startrow][startcol]->checker;
    board[nextrow][nextcol]->hasChecker = true;
    board[startrow][startcol]->hasChecker = false;
    board[startrow][startcol]->checker = nullptr;

    if (nextrow == 0 || nextrow == 7) {board[nextrow][nextcol]->checker->isKing = true;}

    bool jumping = startcol+2 == nextcol || startcol-2 == nextcol;
    if (jumping) {
        jumpedrow = startrow+(startrow+2 == nextrow ? 1 : -1);
        jumpedcol = startcol+(startcol+2 == nextcol ? 1 : -1);
        Cell* jumpedCell = board[jumpedrow][jumpedcol];
        jumpedCell->hasChecker = false;
        jumpedCell->checker = nullptr;
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

bool Game::jumpingRightPiece() {
    jumpedrow = startrow+(startrow+2 == nextrow ? 1: -1);
    jumpedcol = startcol+(startcol+2 == nextcol ? 1 : -1);
    Cell* jumpedpiece = board[jumpedrow][jumpedcol];
    if (!jumpedpiece->hasChecker) {return false;}
    return jumpedpiece->checker->letter == (turn ? 'o' : 'x');
}

bool Game::canmove() {
    startcol = pmove[0] - '0';
    startrow = pmove[1] - '0';
    Cell* startcell = board[startrow][startcol];
    if (!startcell->hasChecker) {return false;}

    bool wrongPiece = (turn ? startcell->checker->letter != 'x' : startcell->checker->letter != 'o');
    if (wrongPiece) {return false;}

    nextcol = pmove[3] - '0';
    nextrow = pmove[4] - '0';
    Cell* nextcell = board[nextrow][nextcol];
    if (nextcell->hasChecker) {return false;}

    bool tryingKingJump = (startrow+2 == nextrow || startrow-2 == nextrow) &&
                          (startcol+2 == nextcol || startcol-2 == nextcol) &&
                          (startcell->checker->isKing);
    bool tryingJump = (turn ? startrow-2 == nextrow : startrow+2 == nextrow) && 
                      (startcol+2 == nextcol || startcol-2 == nextcol);
    if (tryingJump || tryingKingJump) {return jumpingRightPiece();}

    bool tryingKingMove = (startrow-1 == nextrow || startrow+1 == nextrow) &&
                          (startcol-1 == nextcol || startcol+1 == nextcol) &&
                          (startcell->checker->isKing);
    bool tryingMove = (turn ? startrow-1 == nextrow : startrow+1 == nextrow) && 
                      (startcol+1 == nextcol || startcol-1 == nextcol);
    return tryingMove || tryingKingMove;
}

bool Game::haswinner() {
    return oleft == 0 || xleft == 0;
}

void Game::play() {
    while (1) {
        cin >> pmove;
        if (validmove() && canmove()) { 
            update();
            if (haswinner()) {
                cout << (turn ? 'o' : 'x') << " wins!" << endl;
                break;
            }
        } else {
            cout << "Please enter a valid pmove" << endl;
        }
    }
}