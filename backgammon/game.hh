#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "point.hh"

using std::vector;
using std::string;

class Game {
    bool turn;
    int oLeft;
    int xLeft;
    vector<string> movelist;
    vector<Point> board; 
    vector<Checker*> xBar;
    vector<Checker*> oBar;
    int roll1;
    int roll2;
    void printBoard();
    void getRolls();
    void getMoves();
    bool canMove(string move);
    bool validMove(string move);
    bool legalJumps();
    void update();
    bool hasWinner();
    void play();


    public:
    Game();
};