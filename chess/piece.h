#ifndef PIECE_H
#define PIECE_H

class Piece {
    public:
    virtual void move() = 0;
    char get_letter() {
        return letter;
    }

    protected:
    int row;
    int col;
    char letter;
};

#endif