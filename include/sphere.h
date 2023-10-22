#ifndef SPHERE_H
#define SPHERE_H

#include <memory>

#include "vec3.h"
#include "hittable.h"

using std::shared_ptr;

class material;

class sphere: public hittable {
    point3 m_center;
    double m_radius;
    shared_ptr<material> m_material;
    public:
        sphere(point3 center, double radius, shared_ptr<material> material): m_center(center),
        m_radius(radius), m_material(material) {}
        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            vec3 oc = r.origin() - m_center;
            auto a = r.direction().length_squared();
            auto half_b = dot(oc, r.direction());
            auto c = oc.length_squared() - m_radius*m_radius;
            auto discriminant = (half_b*half_b - a*c);
            if (discriminant < 0) {
                return false;
            }
            auto sqrtd = sqrt(discriminant);
            auto root = (-half_b - sqrtd) / a;
            if (!ray_t.surrounds(root)) {
                root = (-half_b + sqrtd) / a;
                if (!ray_t.surrounds(root)) {
                    return false;
                }
            }

            rec.t = root;
            rec.p = r.at(root);
            vec3 outward_normal = (rec.p - m_center) / m_radius;
            rec.set_face_normal(r, outward_normal);
            rec.mat = m_material;

            return true;
        }
};

#endif

