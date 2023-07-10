#include<iostream>
#include<fstream>

#include "vec3.hpp"
#include "color.hpp"

int main(int argc, char *argv[]) {
    const int height = 256;
    const int width = 256;
    std::cout << "P3\n" << width << " " << height << "\n255\n";
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            color pixel_color(float((row + 1))/height, float((col + 1))/width, 128/255.0);
            write_color(std::cout, pixel_color);
        }
    }
    return 0;
}

