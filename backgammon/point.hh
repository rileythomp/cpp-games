#include <vector>
#include "checker.hh"

using std::vector;

class Point {
    vector<Checker*> checkers;
    bool isOccupied;

    public:
    Point();
};