#include "game.h"

Game::Game(Board _board, Player _p1, Player _p2) : board{_board}, p1{_p1}, p2{_p2} {}

void Game::print() {
    std::cout << p1.name << std::endl;
    std::cout << p2.name << std::endl;
}

void Game::play() {
    board.print();
}
