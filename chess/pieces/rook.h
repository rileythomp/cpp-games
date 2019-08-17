#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook: public Piece {
  public:
  Rook(int r, int c, bool _p1_piece);
  void move() override;
  char get_letter() override;

  private:
  int row;
  int col;
  char letter;
  bool p1_piece;
};

#endif