#include "canvas.hpp"
#include <algorithm>

Canvas::Canvas() {
    Color black = {0, 0, 0};
    this->set_color(black);
}

void Canvas::set_color(const Color &color) {
    std::fill(this->pixels.begin(), this->pixels.end(), color);
}
