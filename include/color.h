#ifndef COLOR_H
#define COLOR_H

#include<iostream>

#include "vec3.h"

inline double linear_to_gamma(double val) {
    return sqrt(val);
}

void write_color(std::ostream& os, color pixel_color, int samples) {
    double scale = 1.0 / samples;
    auto r = linear_to_gamma(pixel_color.x() * scale);
    auto g = linear_to_gamma(pixel_color.y() * scale);
    auto b = linear_to_gamma(pixel_color.z() * scale);
    static const interval intensity(0, 0.999);
    os << static_cast<int>(256*intensity.clamp(r)) << ' '
        << static_cast<int>(256*intensity.clamp(g)) << ' '
        << static_cast<int>(256*intensity.clamp(b)) << '\n';
}

#endif
