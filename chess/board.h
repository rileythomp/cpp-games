#include <vector>
#include "cell.h"
#include "pieces/pawn.h"
#include "pieces/rook.h"
#include "pieces/knight.h"
#include "pieces/bishop.h"
#include "pieces/king.h"
#include "pieces/queen.h"

class Board {
    typedef std::pair<std::pair<int, int>, std::pair<int, int>> Move;
    std::vector<std::vector<Cell>> board;
    bool legal_move(Move move, bool turn);

    public:
    Board();
    // move is ((start row, start col), (end row, end col))
    void make_move(Move move, bool turn);
    void print();
};