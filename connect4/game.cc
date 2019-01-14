#include "game.h"
#define For(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void printSubRow(char c) {
    For(i, 28) {
        if (i%4 == 0) {
            cout << '|';
        } 
        else {
            cout << c;
        }
    }
    cout << '|' << endl;
}

void Game::printRow(int i) {
    printSubRow(' ');
    vector<Cell> row = board[i];
    for (Cell cell : row) {
        cout << "| " << cell.letter << ' ';
    }
    cout << '|' << endl;
    printSubRow('_');
}

void Game::print() {
    for (int i = 5; i >= 0; --i) {
        printRow(i);
    }
    for (int i = 0; i < 28; ++i) {
        if (i%4 == 2) {
            cout << (i-2)/4;
        } else {
            cout << ' ';
        }
    }
    cout << endl << endl;  
    cout << (turn ? 'X' : 'O') << "'s turn" << endl << endl;
}

Game::Game() {
    For(i, 6) {
        vector<Cell> row;
        For(j, 7) {
            row.push_back(Cell());
        }
        board.push_back(row);
    }
    print();
}

char Game::diagWinner() {
    // down to right
    for (int i = 3; i < 6; ++i) {
        For(j, 4) {
            if ((board[i][j].letter == 'X' || board[i][j].letter == 'O') &&
                board[i][j].letter == board[i-1][j+1].letter && 
                board[i][j].letter == board[i-2][j+2].letter &&
                board[i][j].letter == board[i-3][j+3].letter) {
                return board[i][j].letter;
            }
        }
    }
    // up to the right
    For(i, 3) {
        For(j, 4) {
            if ((board[i][j].letter == 'X' || board[i][j].letter == 'O') &&
                board[i][j].letter == board[i+1][j+1].letter && 
                board[i][j].letter == board[i+2][j+2].letter &&
                board[i][j].letter == board[i+3][j+3].letter) {
                return board[i][j].letter;
            }
        }
    }
    return ' ';
}

char Game::horizWinner() {
    For(i, 6) {
        For(j, 4) {
            if ((board[i][j].letter == 'X' || board[i][j].letter == 'O') &&
                board[i][j].letter == board[i][j+1].letter && 
                board[i][j].letter == board[i][j+2].letter &&
                board[i][j].letter == board[i][j+3].letter) {
                return board[i][j].letter;
            }
        }
    }
    return ' ';
}

char Game::vertWinner() {
    For(i, 7) {
        for (int j = 5; j > 2; --j) {
            if ((board[j][i].letter == 'X' || board[j][i].letter == 'O') && 
                board[j][i].letter == board[j-1][i].letter &&
                board[j][i].letter == board[j-2][i].letter &&
                board[j][i].letter == board[j-3][i].letter) {
                return board[j][i].letter;
            }
        }

    }
    return ' ';
}

char Game::winner() {
    char win = vertWinner();
    if (win != ' ') {
        return win;
    }
    win = horizWinner();
    if (win != ' ') {
        return win;
    }
    return diagWinner();
}

void Game::updateWithMove(string move) {
    For(i, 6) {
        if (!board[i][move[0]-'0'].filled) {
            board[i][move[0]-'0'].filled = true;
            board[i][move[0]-'0'].letter = (turn ? 'X' : 'O');
            break;
        }
    }
    turn = !turn;
    print();
}

bool Game::hasNoMoves() {
    For(i, 7) {
        if (!board[5][i].filled) {
            return false;
        }
    }
    return true;
}

void Game::end() {
    cout << "game has ended, type new to play again" << endl;
}

bool Game::moveTaken(string move) {
    return board[5][move[0]-'0'].filled;
}