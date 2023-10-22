#ifndef COLOR_H
#define COLOR_H

#include<iostream>

#include "vec3.h"

void write_color(std::ostream& os, color pixel_color, int samples) {
    double scale = 1.0 / samples;
    auto r = pixel_color.x() * scale;
    auto g = pixel_color.y() * scale;
    auto b = pixel_color.z() * scale;
    static const interval intensity(0, 0.999);
    os << static_cast<int>(256*intensity.clamp(r)) << ' '
        << static_cast<int>(256*intensity.clamp(g)) << ' '
        << static_cast<int>(256*intensity.clamp(b)) << '\n';
}

#endif
