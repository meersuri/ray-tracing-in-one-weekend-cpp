#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"
#include "hittable_list.h"

class camera {
    int m_image_width{400};
    int m_image_height;
    double m_viewport_width;
    double m_viewport_height{2.0};
    double m_aspect_ratio{16.0 / 9.0};
    double m_focal_length{1.0};
    point3 m_center{point3(0,0,0)};
    vec3 m_viewport_u;
    vec3 m_viewport_v;
    vec3 m_pixel_delta_u;
    vec3 m_pixel_delta_v;
    point3 m_viewport_upper_left;
    point3 m_pixel00_loc;
    ray get_ray(point3 origin, vec3 direction) const;
    color ray_color(const ray& r, const hittable& world) const;
    public:
        camera();
        void render(const hittable& world) const;

};

#endif
