#ifndef VEC3_HPP
#define VEC3_HPP

class vec3 {
    public:
        vec3() = default;
        vec3(float x, float y, float z): e_{x, y, z} {};
        vec3& operator+=(const vec3& other);
        vec3& operator*=(const float c);
        vec3& operator/=(const float c);
        float x() const;
        float y() const;
        float z() const;
        float length() const;
        float length_squared() const;
    private:
        float e_[3];
};

std::ostream& operator<<(std::ostream& os, const vec3& v);
vec3 operator+(const vec3& a, const vec3& b);
vec3 operator-(const vec3& a, const vec3& b);
vec3 operator*(const vec3& a, float c);
vec3 operator/(const vec3& a, float c);
float dot(const vec3& a, const vec3& b);
vec3 cross(const vec3& a, const vec3& b);
vec3 unit_vector(vec3 v);

using point3 = vec3;
using color = vec3;

#endif
