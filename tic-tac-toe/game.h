#include <stack>
#include "board.h"

class Game {
    bool turn = true; // true is X false is O
    std::stack<int> moves;
    Board board;
    public:
    void turnMessage();
    bool update(int move);
    bool hasWinner();
    void printWinner();
    void printBoard();
};