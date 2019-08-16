#include <vector>
#include "cell.h"
#include "pawn.h"

class Board {
    std::vector<std::vector<Cell>> board;

    public:
        Board() {
            for (int i = 0; i < 8; ++i) {
                std::vector<Cell> row;
                for (int j = 0; j < 8; ++j) {
                    // Pawns rows
                    if (i%6 == 1) {
                        Piece* pawn = new Pawn(i, j);
                        Cell cell = Cell(pawn);
                        row.push_back(cell);
                    }
                }
                board.push_back(row);
            }
        }

        void print() {
            for (auto row : board) {
                for (auto cell : row) {
                    std::cout << cell.letter() << std::endl;
                }
            }
        }
};