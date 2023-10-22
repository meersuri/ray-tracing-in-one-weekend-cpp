#ifndef UTILS_H
#define UTILS_H

#include <limits>
#include <cmath>
#include <random>

constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

inline double random_double(double min, double max) {
    return (max - min) * random_double() + min;
}

#endif


