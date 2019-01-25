#include "cell.h"

Cell::Cell() {
    filled = false;
    piece = ' ';
    isking = false;
}

Cell::Cell(char c) {
    filled = true;
    piece = c;
    isking = false;
}