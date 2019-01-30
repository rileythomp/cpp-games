#include <stack>
#include "board.h"

class Game {
    bool turn = true; 
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