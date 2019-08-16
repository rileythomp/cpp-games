#include "player.h"
#include "board.h"
#include <iostream>

class Game {
    Board board;
    Player p1;
    Player p2;

    public:
    Game(Board _board, Player _p1, Player _p2) : p1{_p1}, p2{_p2}, board{_board} {}

    void print() {
        std::cout << p1.name << std::endl;
        std::cout << p2.name << std::endl;
    }

    void play() {
        board.print();
    }
};