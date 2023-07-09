#ifndef VEC3_HPP
#define VEC3_HPP

class vec3 {
    float e[3];
    public:
        vec3();
        vec3(float x, float y, float z);
        vec3(const vec3& other);
        vec3 operator+(const vec3& other);
        vec3& operator+=(const vec3& other);
        vec3 operator-(const vec3& other);
        vec3 operator*(const float c);
        vec3& operator*=(const float c);
        vec3& operator/=(const float c);
        float x() const;
        float y() const;
        float z() const;
        float length() const;
        float length_squared() const;
};

std::ostream& operator<<(std::ostream& os, const vec3& v);

using point3 = vec3;
using color = vec3;

#endif
