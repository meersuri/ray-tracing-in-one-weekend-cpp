#include<cmath>
#include<iostream>

#include "vec3.h"

float vec3::x() const { return e_[0]; }

float vec3::y() const { return e_[1]; }

float vec3::z() const { return e_[2]; }

float vec3::length() const { return sqrt(length_squared()); }

float vec3::length_squared() const { return (e_[0]*e_[0] + e_[1]*e_[1] + e_[2]*e_[2]); }

vec3 operator+(const vec3& a, const vec3& b) { 
    return vec3(a.x() + b.x(), a.y() + b.y(), a.z() + b.z());
}

vec3 operator-(const vec3& a, const vec3& b) { 
    return vec3(a.x() - b.x(), a.y() - b.y(), a.z() - b.z());
}

vec3 operator*(const vec3& a, const float c) { 
    return vec3(a.x()*c, a.y()*c, a.z()*c);
}

vec3 operator/(const vec3& a, const float c) { 
    return vec3(a.x()/c, a.y()/c, a.z()/c);
}

vec3& vec3::operator+=(const vec3& other) { 
    e_[0] += other.x();
    e_[1] += other.y();
    e_[2] += other.z();
    return *this;
}
vec3& vec3::operator*=(const float c) { 
    e_[0] *= c;
    e_[1] *= c;
    e_[2] *= c;
    return *this;
}

vec3& vec3::operator/=(const float c) { 
    *this *= (1/c);
    return *this;
}

float dot(const vec3& a, const vec3& b) {
    return a.x()*b.x() + a.y()*b.y() + a.z()*b.z();
}

vec3 cross(const vec3& a, const vec3& b) {
    return vec3(
            a.y()*b.z() - a.z()*b.y(),
            a.z()*b.x() - a.x()*b.z(),
            a.x()*b.y() - a.y()*b.x()
            );
}

vec3 unit_vector(vec3 a) {
    a = a/a.length();
    return a;
}


std::ostream& operator<<(std::ostream& os, const vec3& v) {
    os << "<" << v.x() << "," << v.y() << "," << v.z() << ">\n";
    return os;
}
