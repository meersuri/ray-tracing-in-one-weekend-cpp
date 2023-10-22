#ifndef HITTABLE_H
#define HITTABLE_H

#include <memory>
#include "ray.h"
#include "interval.h"
#include "utils.h"

using std::shared_ptr;

class material;

class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t;
        bool front_face;
        shared_ptr<material> mat;
        void set_face_normal(const ray& r, const vec3& outward_normal) {
            if (dot(r.direction(), outward_normal) < 0.0) {
                front_face = true; 
                normal = outward_normal;
            }
            else {
                front_face = false;
                normal = -outward_normal;
            }
        }

};

class hittable {
    public:
        virtual ~hittable() = default;
        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif
