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

bool Board::legal_move(Move move, bool turn) {
    // there needs to be a piece that is urs that is on the start sqr.
    Cell start_cell = board[move.first.first][move.first.second];
    std::cout << "get letter  " << start_cell.piece->get_letter() << std::endl;
    std::cout << "p1 piece: " << start_cell.piece->p1_piece << std::endl;

    if (!start_cell.has_piece) {
        return false;
    }

    std::cout << "turn: " << turn << std::endl;
    std::cout << "p1 piece: " << start_cell.piece->p1_piece << std::endl;

    // it needs to be ur piece
    if (start_cell.piece->p1_piece == turn) {
        std::cout << "illegal move" << std::endl;
        return false;
    }

    return true;
}

// move is ((start row, start col), (end row, end col))
void Board::make_move(Move move, bool turn) {
    if (legal_move(move, turn)) {
        std::pair<int, int> start = move.first;
        std::pair<int, int> end = move.second;

        Cell& start_cell = board[start.first][start.second];
        Cell& end_cell = board[end.first][end.second];

        end_cell.piece = start_cell.piece;
        end_cell.has_piece = true;
        start_cell.has_piece = false;
        start_cell.piece = nullptr;
    }
    else {
        
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