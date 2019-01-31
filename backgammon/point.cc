#include "point.hh"
#include <iostream>
using std::cout;
using std::endl;
#define For(i, n) for(int i = 0; i < (n); ++i)

Point::Point(int n, char c) {
    For(i, n) {
        checkers.push_back(new Checker(c));
    }
    occupied = true;
    owned = true;
    length = n;
}

Point::Point() {
    occupied = false;
    owned = false;
    length = 0;
}

char Point::letter() {
    if (occupied) { return checkers[0]->letter; }
    return ' ';
}

char Point::ownedBy() {
    if (owned) { return checkers[0]->letter; }
    return ' ';
}