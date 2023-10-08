#include <iostream>

#ifndef VEC3_HPP
#define VEC3_HPP

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
    private:
        double e_[3];
};

std::ostream& operator<<(std::ostream& os, const vec3& v);
vec3 operator+(const vec3& a, const vec3& b);
vec3 operator-(const vec3& a, const vec3& b);
vec3 operator*(const vec3& a, double c);
vec3 operator*(double c, const vec3& a);
vec3 operator/(const vec3& a, double c);
double dot(const vec3& a, const vec3& b);
vec3 cross(const vec3& a, const vec3& b);
vec3 unit_vector(vec3 v);

using point3 = vec3;
using color = vec3;

#endif
