#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include "cell.h"
using std::vector;
using std::string;

class Game {

    vector<vector<Cell>> board;
    string move;
    bool turn;
    void printrow(int i);
    void print();
    void play();
    void update();
    bool canmove();
    bool haswinner();
    char winner;

    public:
    Game();
};