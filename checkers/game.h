#include <string>
#include <iostream>
#include <vector>

#include "cell.h"

using std::vector;
using std::string;

class Game {
    bool turn;
    int xleft;
    int oleft;
    int nextrow;
    int nextcol;
    int startrow;
    int startcol;
    int jumpedrow;
    int jumpedcol;
    string pmove;
    vector<vector<Cell*>> board;

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