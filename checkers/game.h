#include <string>
#include <iostream>
#include <vector>

#include "cell.h"

using std::vector;
using std::string;

class Game {
    vector<vector<Cell*>> board;
    string pmove;
    int xleft;
    int oleft;
    int startrow;
    int startcol;
    int nextrow;
    int nextcol;
    int jumpedrow;
    int jumpedcol;
    bool turn;

    void printrow(int i);
    void printboard();
    void play();
    void update();
    bool validmove();
    bool canmove();
    bool jumpingRightPiece();
    bool haswinner();

    public:
    Game();
};