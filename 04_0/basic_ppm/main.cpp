#include "canvas.hpp"
#include "color.hpp"
#include <iostream>

int main(int, char **) {
    Canvas write_canvas;
    const Color magenta = {255, 0, 255};
    const char *ppm_filename = "test.ppm";
    write_canvas.set_color(magenta);
    write_canvas.write_to_file(ppm_filename);
    Canvas read_canvas;
    read_canvas.read_from_file(ppm_filename);
    if (write_canvas != read_canvas) {
        std::cerr << "Read and write canvases are different!" << std::endl;
        return 1;
    }
    return 0;
}
