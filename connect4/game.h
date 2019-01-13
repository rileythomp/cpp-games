#include <string>
#include <iostream>
#include <cmath>


class Game {
    public:
    Game();
    void start();
    bool hasWinner();
    void print();
    void updateWithMove(std::string move);
    bool hasNoMoves();
    void end();
};