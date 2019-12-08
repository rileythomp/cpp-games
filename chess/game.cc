#include "game.h"

Game::Game(Board _board, Player _p1, Player _p2) : board{_board}, p1{_p1}, p2{_p2}, turn{true} {}

void Game::print() {
  std::cout << p1.name << std::endl;
  std::cout << p2.name << std::endl;
}

void Game::build_move() {
  int sr = 8 - (move_input[1] - '0');
  int sc = move_input[0] - 'a';
  int er = 8 - (move_input[4] - '0');
  int ec = move_input[3] - 'a';
  move = {{sr, sc}, {er, ec}};
}

void Game::play() {
  board.print();

  while (true) {
      get_input();

      if (move_valid()) {
        // move is ((start row, start col), (end row, end col))
        build_move();
        board.make_move(move, turn);
      }
      else {
        std::cout << "Please enter a valid move" << std::endl;
        continue;
      }
      board.print();
      turn = !turn;
  }
}

bool Game::move_valid() {
  return 
    'a' <= move_input[0] && move_input[0] <= 'h' &&
    '1' <= move_input[1] && move_input[1] <= '8' &&
    move_input[2] == ' ' &&
    'a' <= move_input[3] && move_input[3] <= 'h' &&
    '1' <= move_input[4] && move_input[4] <= '8';
}

void Game::get_input() {
  std::cout << (turn ? p1.name : p2.name) << "'s turn: ";
  getline(std::cin, move_input);
}
