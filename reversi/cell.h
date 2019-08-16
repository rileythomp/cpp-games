#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
    public:
        bool empty;
        std::string colour; // B or W

        Cell() {
            empty = true;
            colour = " ";
        }

        Cell(std::string _colour) {
            empty = false;
            colour = _colour;
        }
};

#endif