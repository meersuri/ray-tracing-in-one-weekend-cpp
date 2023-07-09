#include<iostream>

#include "vec3.hpp"

int main() {
    vec3 x;
    std::cout << x;
    vec3 a(1.3, 4.6, 7.7);
    std::cout << a;
    std::cout << a + vec3(1.5, 2.8, 3.9);
    std::cout << a - vec3(1.5, 2.8, 3.9);
    std::cout << a*3;
    a /= 3;
    std::cout << a;
    return 0;
}
