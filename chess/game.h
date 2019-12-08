#include "player.h"
#include "board.h"
#include <iostream>

class Game {
    typedef std::pair<std::pair<int, int>, std::pair<int, int>> Move;

    Board board;
    Player p1;
    Player p2;
    std::string move_input;
    bool turn;
    Move move;
    void build_move();
    bool move_valid();
    void get_input();
    void print();

    public:
    Game(Board _board, Player _p1, Player _p2); 
    void play();

};