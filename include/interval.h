#ifndef INTERVAL_H
#define INTERVAL_H

#include "utils.h"

class interval {
    public:
        double min;
        double max;
        interval(): min(+infinity), max(-infinity) {}
        interval(double minimum, double maximum): min(minimum), max(maximum) {}
        bool contains(double x) { return x >= min && x <= max; }
        bool surrounds(double x) { return x > min && x < max; }
        double clamp(double x) const { 
            if (x < min) {
                return min;
            }
            if (x > max) {
                return max;
            }
            return x;
        }
        static const interval empty;
        static const interval universe;
};

static const interval empty(+infinity, -infinity);
static const interval universe(infinity, +infinity);

#endif
