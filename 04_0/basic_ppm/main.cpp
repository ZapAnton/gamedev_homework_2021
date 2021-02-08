#include "canvas.hpp"
#include "color.hpp"
#include <iostream>

int main(int, char **) {
    Canvas canvas;
    const Color magenta = {255, 0, 255};
    const char *ppm_filename = "test.ppm";
    canvas.set_color(magenta);
    canvas.write_to_file(ppm_filename);
    return 0;
}
