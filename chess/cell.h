#include "piece.h"
#include <string>

class Cell {
    bool hasPiece;
    Piece* piece;

    public:
    Cell() : hasPiece{false}, piece{nullptr} {}

    Cell(Piece* _piece) : hasPiece{true}, piece{_piece} {}

    char letter() {
        return piece->get_letter();
    }


};
