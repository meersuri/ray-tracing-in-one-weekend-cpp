#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        ray() {}
        ray(const point3& origin, const vec3& direction): origin_(origin), dir_(direction) {}
        point3 origin() const { return origin_; }
        vec3 direction() const { return dir_; }
        point3 at(double t) const { return origin_ + t*dir_; }
    private:
        point3 origin_;
        vec3 dir_;
};

#endif
