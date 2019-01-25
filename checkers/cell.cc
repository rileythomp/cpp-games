#include "cell.h"

using namespace std;

Cell::Cell() {
    filled = false;
    piece = ' ';
}

Cell::Cell(char c) {
    filled = true;
    piece = c;
}