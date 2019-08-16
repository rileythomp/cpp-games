#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "window.h"

class Graphics {
    public:
    Graphics(int x, int y, int width, int height, Xwindow *xw);
    void draw();

    private:
    int x, y, w, h;
    Xwindow* xw;
};

#endif