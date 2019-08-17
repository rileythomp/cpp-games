#include "king.h"
#include <iostream>

King::King(int r, int c, bool _p1_piece) : row{r}, col{c}, letter{'k'}, p1_piece{_p1_piece} {}

void King::move() {
    std::cout << 1234 << std::endl;
}

char King::get_letter() {
    if (p1_piece) {
        return letter;
    }
    return toupper(letter);
}
