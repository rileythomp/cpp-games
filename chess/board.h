#include <vector>
#include "cell.h"

class Board {
    std::vector<std::vector<Cell>> board;

    public:
        Board() {
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    // Pawns rows
                    if (i%6 == 1) {
                        Cell();
                    }
                }
            }
        }
};