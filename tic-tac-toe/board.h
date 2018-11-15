#include <vector>
#include "cell.h"

class Board {
    std::vector<Cell> board = std::vector<Cell>(9);
    public:
    void print();
    bool isPlayed(int move);
    void update(int move, bool turn);
    char getVal(int cell);
};