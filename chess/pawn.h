#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn: public Piece {
  public:
  Pawn(int r, int c) : row{r}, col{c}, letter{'p'} {}
  void move() override;

  private:
  int row;
  int col;
  char letter;

};

#endif