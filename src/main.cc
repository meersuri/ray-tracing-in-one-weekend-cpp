#include<iostream>
#include<fstream>
#include<cmath>

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"
#include "material.h"

int main(int argc, char *argv[]) {
    camera cam(1280);

    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<lambertian>(color(0.7, 0.3, 0.3));
    auto material_left = make_shared<metal>(color(0.8, 0.8, 0.8));
    auto material_right = make_shared<metal>(color(0.8, 0.6, 0.2));
    auto world = hittable_list(make_shared<sphere>(point3(0,0,-1), 0.5, material_center));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100, material_ground));
    world.add(make_shared<sphere>(point3(-1,0,-1), 0.5, material_left));
    world.add(make_shared<sphere>(point3(1,0,-1), 0.5, material_right));

    cam.render(world);

    return 0;
}

