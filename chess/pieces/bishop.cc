#include "bishop.h"
#include <iostream>

Bishop::Bishop(int r, int c, bool _p1_piece) : row{r}, col{c}, letter{'b'}, p1_piece{_p1_piece} {}

void Bishop::move() {
    std::cout << 1234 << std::endl;
}

char Bishop::get_letter() {
    if (p1_piece) {
        return letter;
    }
    return toupper(letter);
}
