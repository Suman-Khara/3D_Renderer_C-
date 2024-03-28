#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

using colour = vec3;

void write_colour(ostream &out, colour pixel_colour)
{
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255 * pixel_colour.x()) << ' '
        << static_cast<int>(255 * pixel_colour.y()) << ' '
        << static_cast<int>(255 * pixel_colour.z()) << '\n';
}

#endif