#include "board.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 8; ++i) {
        std::vector<Cell> row;
        for (int j = 0; j < 8; ++j) {
            // Pawns rows
            Cell cell;
            Piece* p = nullptr;
            if (i%5 == 1) {
                p = new Pawn(i, j, i  < 2);
            } else if (i%7 == 0) {
                if (j%7 == 0) {
                    p = new Rook(i, j, i  < 2);
                }
                else if (j%5 == 1) {
                    p = new Knight(i, j, i  < 2);
                }
                else if (j%3 == 2) {
                    p = new Bishop(i, j, i  < 2);
                }
                else if (j == 3) {
                    p = new Queen(i, j, i  < 2);
                }
                else if (j == 4) {
                    p = new King(i, j, i  < 2);
                }   
            }
            cell = Cell(p);
            row.push_back(cell);
        }
        board.push_back(row);
    }
}

void Board::print() {
    int i = 8;
    std::cout << "     a   b   c   d   e   f   g   h  " << std::endl;
    std::cout << "    ___ ___ ___ ___ ___ ___ ___ ___ " << std::endl;
    for (auto row : board) {
        std::cout << "   |   |   |   |   |   |   |   |   |" << std::endl;
        std::cout << " " << i << " |";
        for (auto cell : row) {
            std::cout << ' ' << cell.letter() << " |";
        }
        std::cout << std::endl;
        std::cout << "   |___|___|___|___|___|___|___|___|" << std::endl;
        --i;
    }
}