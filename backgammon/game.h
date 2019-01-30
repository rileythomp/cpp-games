#include <string>
#include <iostream>
#include <vector>

class Game {
    bool turn;
    string pmove;
    int oLeft;
    int xLeft;


    public:
    Game();
    bool canMove();
    void update();
    bool hasWinner();
    void play();
};