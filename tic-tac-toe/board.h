#include <vector>
#include "cell.h"

class Board {
    std::vector<Cell> board = std::vector<Cell>(9);
    
    public:
    void print();
    void update(int move, bool turn);
    bool isPlayed(int move);
    char getVal(int cell);
};