#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include "cell.h"
using std::vector;

class Game {

    vector<vector<Cell>> board;
    bool turn;
    void printRow(int i);
    char vertWinner();
    char horizWinner();
    char diagWinner();

    public:
    Game();
    void start();
    char winner();
    void print();
    void updateWithMove(std::string move);
    bool hasNoMoves();
    void end();
    bool moveTaken(std::string move);
};