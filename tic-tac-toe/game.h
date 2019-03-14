#include <stack>
#include "board.h"

class Game {
    Board board;
    bool turn = true; 
    int moves = 0;

    public:
    void turnMessage();
    void update(int move);
    void printWinner();
    void printDraw();
    void printBoard();
    bool hasWinner();
    int numMoves();
};