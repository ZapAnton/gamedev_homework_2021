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

void Canvas::read_from_file(const std::string &filename) {
    std::ifstream file;
    file.open(filename);
    std::string ppm_header;
    size_t image_width = 0;
    size_t image_height = 0;
    std::string color_format;
    file >> ppm_header >> image_width >> std::ws >> image_height >>
        color_format;
    if (image_width * image_height != this->pixels.size()) {
        throw std::runtime_error("Image size did not match the canvas!");
    }
    for (size_t i = 0; i < this->pixels.size(); ++i) {
        auto r = 0;
        auto g = 0;
        auto b = 0;
        file >> r >> std::ws >> g >> std::ws >> b;
        this->pixels[i] = {static_cast<uint8_t>(r), static_cast<uint8_t>(g),
                           static_cast<uint8_t>(b)};
    }
    file.close();
}

bool operator!=(const Canvas &l_canvas, const Canvas &r_canvas) {
    return l_canvas.pixels != r_canvas.pixels;
}
