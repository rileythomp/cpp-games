#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn: public Piece {
  public:
  Pawn(int r, int c, bool _p1_piece);
  void move() override;
  char get_letter() override;

  private:
  int row;
  int col;
  char letter;
  bool p1_piece;

};

#endif