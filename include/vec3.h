#include <iostream>

#ifndef VEC3_HPP
#define VEC3_HPP

#include "utils.h"

class vec3 {
    public:
        vec3() = default;
        vec3(double x, double y, double z): e_{x, y, z} {};
        vec3& operator+=(const vec3& other);
        vec3& operator*=(const double c);
        vec3& operator/=(const double c);
        double x() const;
        double y() const;
        double z() const;
        double length() const;
        double length_squared() const;
        bool near_zero() const;
        static vec3 random() { return vec3(random_double(), random_double(), random_double()); }
        static vec3 random(double min, double max) { return vec3(random_double(min, max), random_double(min, max), random_double(min, max)); }
    private:
        double e_[3];
};

std::ostream& operator<<(std::ostream& os, const vec3& v);
vec3 operator+(const vec3& a, const vec3& b);
vec3 operator-(const vec3& a, const vec3& b);
vec3 operator-(const vec3& a);
vec3 operator*(const vec3& a, double c);
vec3 operator*(double c, const vec3& a);
vec3 operator*(const vec3& a, const vec3& c);
vec3 operator/(const vec3& a, double c);
double dot(const vec3& a, const vec3& b);
vec3 cross(const vec3& a, const vec3& b);
vec3 unit_vector(vec3 v);
vec3 random_in_unit_sphere();
vec3 random_unit_vector();
vec3 random_on_hemisphere(const vec3& normal);

using point3 = vec3;
using color = vec3;

#endif
