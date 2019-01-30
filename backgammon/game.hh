#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include "point.hh"

using std::vector;
using std::string;

class Game {
    bool turn;
    string pmove;
    int oLeft;
    int xLeft;
    // inner vector is a stripe (max 15) 
    // outer vector is all the stripes making the board
    vector<Point> board; 
    vector<Checker*> xBar;
    vector<Checker*> oBar;
    int roll1;
    int roll2;


    public:
    Game();
    bool canMove();
    void update();
    bool hasWinner();
    void play();
};