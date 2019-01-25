#include "cell.h"

#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */

using namespace std;

Cell::Cell() {
    filled = false;
    piece = ' ';
}

Cell::Cell(char c) {
    filled = true;
    piece = c;
}