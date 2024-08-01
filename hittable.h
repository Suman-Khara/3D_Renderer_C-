#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record
{
public:
    point3 p;    // Point of intersection
    vec3 normal; // Surface normal at the intersection point
    double t;    // Ray parameter at the intersection point
};

class hittable
{
public:
    virtual ~hittable() = default; // Virtual destructor for proper cleanup

    // Pure virtual function to be overridden by derived classes
    virtual bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const = 0;
};

#endif
