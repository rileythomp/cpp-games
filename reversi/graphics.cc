#include "graphics.h"

Graphics::Graphics(int x, int y, int width, int height, Xwindow *xw) : x{x}, y{y}, w{w}, h{h}, xw{xw} {};

void Graphics::draw() {
    xw->drawLine(x, y-1, x + w, y-1);
    xw->drawLine(x-1, y, x-1, h + y);
    xw->drawLine(x, y + h, x + w, y + h);
    xw->drawLine(x + w, y, x + w, y + h);
}