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
    if (b[n].played) {
        std::cout << b[n].val;
    } else {
        std::cout << ' ';
    }
    std::cout << " | ";
    if (b[n+1].played) {
        std::cout << b[n+1].val;
    } else {
        std::cout << ' ';
    }
    std::cout << " | ";
    if (b[n+2].played) {
        std::cout << b[n+2].val;
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
    return board[move].played;
}

void Board::update(int move, bool turn) {
    board[move].played = true;
    if (turn) {
        board[move].val = 'X';
    } else {
        board[move].val = 'O';
    }
}

char Board::getVal(int cell) {
    return board[cell].val;
}