#ifndef MATERIAL_H
#define MATERIAL_H

#include "utils.h"
#include "ray.h"
#include "hittable.h"

class material {
    public:
        virtual ~material() = default;
        virtual ray scatter(const ray& r, const hit_record& rec, color& attenuation) const = 0;
};

class lambertian: public material {
    color m_albedo;
    public:
        lambertian(const color& albedo): m_albedo(albedo) {}
        ray scatter(const ray& r, const hit_record& rec, color& attenuation) const override {
            vec3 direction = rec.normal + random_unit_vector();
            if (direction.near_zero()) {
                direction = rec.normal;
            }
            attenuation = m_albedo;
            return ray(rec.p, direction);
        }
};

class metal: public material {
    color m_albedo;
    public:
        metal(const color& albedo): m_albedo(albedo) {}
        ray scatter(const ray& r, const hit_record& rec, color& attenuation) const override {
            vec3 reflected = reflect(unit_vector(r.direction()), rec.normal);
            attenuation = m_albedo;
            return ray(rec.p, reflected);
        }
};


#endif

