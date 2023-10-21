#ifndef UTILS_H
#define UTILS_H

#include <limits>

constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

#include "ray.h"
#include "vec3.h"

#endif


