#include <iostream>
#include <string>
#include "board.h"

void p3() {
    std::cout << ' ' << ' ' << ' ';
}

void printRow() {
    p3();
    std::cout << '|';
    p3();
    std::cout << '|';
    p3();
    std::cout << std::endl << ' ';
}

void printVal(std::vector<Cell> b, int n) {
    if (b[n].isPlayed()) {
        std::cout << b[n].getVal();
    } else {
        std::cout << ' ';
    }
    std::cout << " | ";
    if (b[n+1].isPlayed()) {
        std::cout << b[n+1].getVal();
    } else {
        std::cout << ' ';
    }
    std::cout << " | ";
    if (b[n+2].isPlayed()) {
        std::cout << b[n+2].getVal();
    } else {
        std::cout << ' ';
    }
    std::cout << ' ' << std::endl;
    if (n < 6) {
        std::cout << "___|___|___" << std::endl;
    } else {
        std::cout << "   |   |   " << std::endl;
    }
}

void printer(std::vector<Cell> b, int n) {
    printRow();
    printVal(b, n);
}

void Board::print() {
    std::cout << std::endl;
    for (int i = 0; i < 9; i+=3) {
        printer(board, i);
    }
    std::cout << std::endl;
}

bool Board::isPlayed(int move) {
    return board[move].isPlayed();
}

void Board::update(int move, bool turn) {
    board[move].setPlayed(true);
    if (turn) {
        board[move].setVal('X');
    } else {
        board[move].setVal('0');
    }
}

char Board::getVal(int cell) {
    return board[cell].getVal();
}