#include "rook.h"
#include <iostream>

Rook::Rook(int r, int c, bool _p1_piece) : row{r}, col{c}, letter{'r'}, p1_piece{_p1_piece} {}

void Rook::move() {
    std::cout << 1234 << std::endl;
}

char Rook::get_letter() {
    if (p1_piece) {
        return letter;
    }
    return toupper(letter);
}
