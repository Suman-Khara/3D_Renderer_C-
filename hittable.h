#ifndef HITTABLE_H
#define HITTABLE_H

#include "constants.h" //this line is given only to remove the errors coming in hittable_list.h and sphere.h, the main.cpp works just fine without this line

class hit_record
{
public:
    point3 p;        // Intersection point
    vec3 normal;     // Normal vector at the intersection
    double t;        // Distance along the ray to the intersection
    bool front_face; // True if the ray is hitting the front face

    void set_face_normal(const ray &r, const vec3 &outward_normal)
    {
        // Determine if the ray is hitting the front face
        front_face = dot(r.direction(), outward_normal) < 0;
        // Set the normal vector to always point against the ray
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable
{
public:
    virtual ~hittable() noexcept = default; // Add noexcept // Virtual destructor for proper cleanup

    // Pure virtual function to be overridden by derived classes
    virtual bool hit(const ray &r, interval ray_t, hit_record &rec) const = 0;
};

#endif
