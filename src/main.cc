#include<iostream>
#include<fstream>
#include<cmath>

#include "vec3.h"
#include "color.h"
#include "ray.h"

double hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0*dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return -1.0;
    }
    return (-b - sqrt(discriminant)) / (2.0*a);
}

color ray_color(const ray& ray) {
    auto unit_dir = unit_vector(ray.direction());
    auto t = hit_sphere(point3(0, 0, -1), 0.5, ray);
    if (t > 0.0 ) {
        vec3 N = unit_vector(ray.at(t) - vec3(0, 0, -1));
        return 0.5*color(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    auto a = 0.5*(unit_dir.y() + 1.0);
    return (1.0 - a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main(int argc, char *argv[]) {
    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    int image_height = static_cast<int>(image_width/aspect_ratio);
    image_height = image_height > 1 ? image_height : 1;

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height*(static_cast<double>(image_width)/image_height);

    point3 camera_center = point3(0, 0, 0);
    vec3 viewport_u(viewport_width, 0, 0);
    vec3 viewport_v(0, -viewport_height, 0);
    auto pixel_delta_u = viewport_u/image_width;
    auto pixel_delta_v = viewport_v/image_height;

    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + pixel_delta_u/2.0 + pixel_delta_v/2.0;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int row = 0; row < image_height; row++) {
        std::clog << "Scan lines remaining: " << (image_height - row) << std::endl;
        for (int col = 0; col < image_width; col++) {
            auto pixel_center = pixel00_loc + (row*pixel_delta_v) + (col*pixel_delta_u);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }
    return 0;
}

