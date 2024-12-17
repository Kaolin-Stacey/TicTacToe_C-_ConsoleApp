#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H
#include "Vec3.h"
#include "glfw3.h"
#include <string>


class TextRenderer {
public:
    static void renderText(const std::string& text, float x, float y, float scale, const Vec3& colour);
    static void init();
    static void cleanup();
};

#endif