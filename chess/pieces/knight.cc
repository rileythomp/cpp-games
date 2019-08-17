#include "knight.h"
#include <iostream>

Knight::Knight(int r, int c, bool _p1_piece) : row{r}, col{c}, letter{'n'}, p1_piece{_p1_piece} {}

void Knight::move() {
    std::cout << 1234 << std::endl;
}

char Knight::get_letter() {
    if (p1_piece) {
        return letter;
    }
    return toupper(letter);
}
