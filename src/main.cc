#include<iostream>
#include<fstream>
#include<cmath>

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"
#include "material.h"

int main(int argc, char *argv[]) {
    camera cam(1280);

    auto world = hittable_list(make_shared<sphere>(point3(0,0,-1), 0.5, make_shared<lambertian>(color(0.5,0.5,0.5))));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100, make_shared<lambertian>(color(0.5,0.5,0.5))));

    cam.render(world);

    return 0;
}

