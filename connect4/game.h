#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include "cell.h"
using std::vector;

class Game {
    vector<vector<Cell>> board;
    bool turn = true;
    void printRow(int i);
    char vertWinner();
    char horizWinner();
    char diagWinner();

    public:
    Game();
    void start();
    void print();
    void updateWithMove(std::string move);
    void end();
    bool hasNoMoves();
    bool moveTaken(std::string move);
    char winner();
};
