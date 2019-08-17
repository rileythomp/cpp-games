#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight: public Piece {
  public:
  Knight(int r, int c, bool _p1_piece);
  void move() override;
  char get_letter() override;

  private:
  int row;
  int col;
  char letter;
  bool p1_piece;

};

#endif