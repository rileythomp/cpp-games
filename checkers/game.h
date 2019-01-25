#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include "cell.h"
using std::vector;
using std::string;

class Game {

    vector<vector<Cell>> board;
    string pmove;
    bool turn;
    void printrow(int i);
    void print();
    void play();
    void update();
    bool validmove();
    bool canmove();
    bool haswinner();
    char winner;
    bool wrongpiece(char piece);
    bool invalidmove(int a, int b, int c, int d);

    public:
    Game();
};