#include "cell.h"

bool Cell::isPlayed() {return played;}

char Cell::getVal() {return val;}

void Cell::setPlayed(bool b) {played = b;}

void Cell::setVal(char c) {val = c;}