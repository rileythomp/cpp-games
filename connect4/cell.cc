#include "cell.h"

Cell::Cell() {
    filled = false;
    letter = ' ';
}

Cell::Cell(char c) {
    filled = true;
    letter = c;
}