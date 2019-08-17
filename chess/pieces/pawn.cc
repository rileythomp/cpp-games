#include "pawn.h"
#include <iostream>

Pawn::Pawn(int r, int c, bool _p1_piece) : row{r}, col{c}, letter{'p'}, p1_piece{_p1_piece} {}

void Pawn::move() {
    std::cout << 1234 << std::endl;
}

char Pawn::get_letter() {
    if (p1_piece) {
        return letter;
    }
    return toupper(letter);
}
