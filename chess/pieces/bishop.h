#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop: public Piece {
  public:
  Bishop(int r, int c, bool _p1_piece);
  void move() override;
  char get_letter() override;

  private:
  int row;
  int col;
  char letter;
  bool p1_piece;

};

#endif