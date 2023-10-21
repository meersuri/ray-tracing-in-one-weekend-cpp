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
        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            bool hit_anything = false;
            hit_record temp;
            for (const auto& obj: m_objects) {
                if (obj->hit(r, ray_t, temp)) {
                    hit_anything = true;
                    ray_t.max = temp.t;
                    rec = temp;
                }
            }
            return hit_anything;
        }
};

#endif

