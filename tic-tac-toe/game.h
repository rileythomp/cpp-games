#include <stack>
#include "board.h"

class Game {
    bool turn = true; // true is X false is O
    Board board;
    int moves = 0;
    public:
    void turnMessage();
    void update(int move);
    bool hasWinner();
    void printWinner();
    void printDraw();
    void printBoard();
    int numMoves();
};