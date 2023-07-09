#include<iostream>
#include<fstream>

int main(int argc, char *argv[]) {
    std::string fname("pic.ppm");
    if (argc > 1)
        fname = argv[1];
    std::ofstream file(fname);
    if (!file.is_open())
        std::cerr << "Failed to open file " << fname << "\n";
    const int height = 256;
    const int width = 256;
    file << "P3\n" << width << " " << height << "\n255\n";
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int r = static_cast<int>(255.0*(row + 1)/height);
            int g = static_cast<int>(255.0*(col + 1)/width);
            int b = 128;
            file << r << " " << g << " " << b << '\n';
        }
    }
    file.close();
    return 0;
}

