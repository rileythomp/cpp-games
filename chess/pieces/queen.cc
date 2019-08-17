#include "queen.h"
#include <iostream>

Queen::Queen(int r, int c, bool _p1_piece) : row{r}, col{c}, letter{'q'}, p1_piece{_p1_piece} {}

void Queen::move() {
    std::cout << 1234 << std::endl;
}

char Queen::get_letter() {
    if (p1_piece) {
        return letter;
    }
    return toupper(letter);
}
