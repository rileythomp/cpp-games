#ifndef KING_H
#define KING_H

#include "piece.h"

class King: public Piece {
  public:
  King(int r, int c, bool _p1_piece);
  void move() override;
  char get_letter() override;

  private:
  int row;
  int col;
  char letter;
  bool p1_piece;

};

#endif