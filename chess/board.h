#include <vector>
#include "cell.h"
#include "pieces/pawn.h"
#include "pieces/rook.h"
#include "pieces/knight.h"
#include "pieces/bishop.h"
#include "pieces/king.h"
#include "pieces/queen.h"

class Board {
    std::vector<std::vector<Cell>> board;

    public:
    Board();

    void print();
};