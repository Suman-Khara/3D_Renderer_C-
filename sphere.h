#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
public:
    sphere(const point3 &center, double radius) : center(center), radius(fmax(0, radius)) {}

    bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const override
    {
        vec3 oc = center - r.origin();                  // Vector from ray origin to sphere center
        auto a = r.direction().length_squared();        // Length squared of the ray direction
        auto h = dot(r.direction(), oc);                // Projection of oc onto the ray direction
        auto c = oc.length_squared() - radius * radius; // Distance squared from sphere center to ray origin minus radius squared

        auto discriminant = h * h - a * c; // Discriminant of the quadratic equation
        if (discriminant < 0)
            return false;

        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range
        auto root = (h - sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root)
        {
            root = (h + sqrtd) / a;
            if (root <= ray_tmin || ray_tmax <= root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);                    // Calculate the intersection point
        rec.normal = (rec.p - center) / radius; // Calculate the normal at the intersection point

        return true;
    }

private:
    point3 center; // Center of the sphere
    double radius; // Radius of the sphere
};

#endif
