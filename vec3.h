#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using namespace std;

class vec3
{
public:
    double e[3];

    vec3() : e{0, 0, 0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    double x() const
    {
        return e[0];
    }
    double y() const
    {
        return e[1];
    }
    double z() const
    {
        return e[2];
    }

    vec3 operator-() const
    {
        return vec3(-e[0], -e[1], -e[2]);
    }
    double operator[](int i) const
    {
        return e[i];
    }
    double &operator[](int i)
    {
        return e[i];
    }

    vec3 &operator*=(double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3 &operator/=(double t)
    {
        return *this *= 1 / t;
    }

    double length() const
    {
        return sqrt(length_squared());
    }

    double length_squared() const
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

    friend ostream &operator<<(ostream &out, const vec3 &v)
    {
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
    }

    vec3 operator+(const vec3 &u)
    {
        return vec3(u.e[0] + e[0], u.e[1] + e[1], u.e[2] + e[2]);
    }

    vec3 operator-(const vec3 &v)
    {
        return vec3(e[0] - v.e[0], e[1] - v.e[1], e[2] - v.e[2]);
    }

    vec3 operator*(const vec3 &u)
    {
        return vec3(u.e[0] * e[0], u.e[1] * e[1], u.e[2] * e[2]);
    }

    vec3 operator*(double t)
    {
        return vec3(t * e[0], t * e[1], t * e[2]);
    }

    friend vec3 operator*(double t, const vec3 &v)
    {
        vec3 r = v;
        return r * t;
    }

    vec3 operator/(double t)
    {
        return (*this) * (1 / t);
    }
};

vec3 unit_vector(vec3 v)
{
    return v / v.length();
}

double dot(const vec3 &v, const vec3 &u)
{
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// point3 is an alias for vec3, useful for geometric clarity in the code.
using point3 = vec3;

#endif