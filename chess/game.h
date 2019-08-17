#include "player.h"
#include "board.h"
#include <iostream>

class Game {
    Board board;
    Player p1;
    Player p2;

    public:
    Game(Board _board, Player _p1, Player _p2); 

    void print();

    void play();
};