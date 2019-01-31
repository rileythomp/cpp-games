#include <vector>
#include "checker.hh"

using std::vector;

class Point {
    public:
    Point(int n, char c);
    Point();
    char letter();
    char ownedBy();
    bool occupied;
    bool owned;
    vector<Checker*> checkers;
    int length;
};