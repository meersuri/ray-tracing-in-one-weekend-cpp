#include "camera.h"
#include "hittable_list.h"
#include "color.h"

camera::camera() {
    m_image_height = static_cast<int>(m_image_width/m_aspect_ratio);
    m_image_height = m_image_height > 1 ? m_image_height : 1;
    m_viewport_width = m_viewport_height*(static_cast<double>(m_image_width)/m_image_height);
    m_viewport_u = vec3(m_viewport_width, 0, 0);
    m_viewport_v = vec3(0, -m_viewport_height, 0);
    m_pixel_delta_u = m_viewport_u/m_image_width;
    m_pixel_delta_v = m_viewport_v/m_image_height;
    m_viewport_upper_left = m_center - vec3(0, 0, m_focal_length) - m_viewport_u/2 - m_viewport_v/2;
    m_pixel00_loc = m_viewport_upper_left + m_pixel_delta_u/2.0 + m_pixel_delta_v/2.0;
}

ray camera::get_ray(point3 origin, vec3 dir) const {
    return ray(origin, dir);
}

color camera::ray_color(const ray& r, const hittable& world) const {
    auto unit_dir = unit_vector(r.direction());
    hit_record rec;
    if (world.hit(r, interval(0, +infinity), rec)) {
        return 0.5*(rec.normal + color(1,1,1));
    }
    auto a = 0.5*(unit_dir.y() + 1.0);
    return (1.0 - a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

void camera::render(const hittable& world) const {
    std::cout << "P3\n" << m_image_width << ' ' << m_image_height << "\n255\n";
    for (int row = 0; row < m_image_height; row++) {
        std::clog << "Scan lines remaining: " << (m_image_height - row) << std::endl;
        for (int col = 0; col < m_image_width; col++) {
            auto pixel_center = m_pixel00_loc + (row*m_pixel_delta_v) + (col*m_pixel_delta_u);
            auto ray_direction = pixel_center - m_center;
            ray r = get_ray(m_center, ray_direction);
            color pixel_color = ray_color(r, world);
            write_color(std::cout, pixel_color);
        }
    }
}
