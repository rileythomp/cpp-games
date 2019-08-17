#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen: public Piece {
  public:
  Queen(int r, int c, bool _p1_piece);
  void move() override;
  char get_letter() override;

  private:
  int row;
  int col;
  char letter;
  bool p1_piece;

};

#endif