#ifndef VEC3_H
#define VEC3_H

struct Vec3 {
    float r, g, b;
    Vec3(float r=0.0f, float g= 0.0f, float b = 0.0f): r(r), g(g), b(b) {}
};

#endif