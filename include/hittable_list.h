#ifndef HITTABLE_LIST
#define HITTABLE_LIST

#include <vector>
#include <memory>

#include "hittable.h"

using std::vector, std::shared_ptr, std::make_shared;

class hittable_list: public hittable {
    vector<shared_ptr<hittable>> m_objects;
    public:
        hittable_list() = default;
        hittable_list(shared_ptr<hittable> object) { add(object); }
        void add(shared_ptr<hittable> object) { m_objects.push_back(object); }
        void clear() { m_objects.clear(); }
        bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
            bool hit_anything = false;
            double closest_hit = ray_tmax;
            hit_record temp;
            for (const auto& obj: m_objects) {
                if (obj->hit(r, ray_tmin, closest_hit, temp)) {
                    hit_anything = true;
                    closest_hit = temp.t;
                    rec = temp;
                }
            }
            return hit_anything;
        }
};

#endif

