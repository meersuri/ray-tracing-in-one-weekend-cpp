#include<iostream>
#include<fstream>
#include<cmath>

#include "utils.h"
#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"

int main(int argc, char *argv[]) {
    camera cam;

    auto world = hittable_list(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    cam.render(world);

    return 0;
}

