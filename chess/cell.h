#include "pieces/piece.h"
#include <string>

class Cell {
    public:
    bool has_piece;
    Piece* piece;

    Cell() : has_piece{false}, piece{nullptr} {}

    Cell(Piece* _piece) : has_piece{true}, piece{_piece} {}

    char letter() {
        if (piece) {
            return piece->get_letter();
        }
        return ' ';
    }


};
