#include "canvas.hpp"
#include <algorithm>
#include <fstream>

Canvas::Canvas() {
    const Color black = {0, 0, 0};
    this->set_color(black);
}

void Canvas::set_color(const Color &color) {
    std::fill(this->pixels.begin(), this->pixels.end(), color);
}

void Canvas::write_to_file(const std::string &filename) {
    std::ofstream file;
    file.open(filename);
    file << "P3\n"
         << BUFFER_WIDTH << ' ' << BUFFER_HEIGHT << '\n'
         << 255 << std::endl;
    for (const auto &pixel : this->pixels) {
        file << static_cast<int>(pixel.r) << ' ' << static_cast<int>(pixel.g)
             << ' ' << static_cast<int>(pixel.b) << std::endl;
    }
    file.close();
}
