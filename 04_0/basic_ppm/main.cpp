#include "canvas.hpp"
#include "color.hpp"
#include <iostream>

int main(int, char **) {
    Canvas canvas;
    const Color magenta = {255, 0, 255};
    canvas.set_color(magenta);
    return 0;
}
