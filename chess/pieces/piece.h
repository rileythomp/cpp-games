#ifndef PIECE_H
#define PIECE_H

class Piece {
    public:
    virtual ~Piece() {};
    virtual void move() = 0;
    virtual char get_letter() = 0;

    protected:
    int row;
    int col;
    char letter;
    bool p1_piece;
};

#endif