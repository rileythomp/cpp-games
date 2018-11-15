#include "board.h"

class Game {
    bool turn = true; // true is X false is O
    public:
    Board board;
    void turnMessage();
    bool update(int move);
    bool winner = false;
    bool hasWinner();
    void printWinner();
};