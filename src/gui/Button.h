#ifndef BUTTON_H
#define BUTTON_H

#include "glfw3.h"
#include "Vec3.h"

class Button {
public:
    Button(float x, float y, float width, float height, const char* label);
    void draw();
    bool isClicked(GLFWwindow* window);
    void render(GLFWwindow* window);
    bool isPointInside(float px, float py);

private:
    float x, y, width, height;
    std::string label;
    Vec3 colour;
};

#endif