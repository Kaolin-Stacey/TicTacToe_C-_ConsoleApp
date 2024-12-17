#include "Button.h"
#include <iostream>

Button::Button(float x, float y, float width, float height, const char* label) 
: x(x), y(y), width(width), height(height), label(label){}


bool Button::isClicked(GLFWwindow* window) {
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    if(isPointInside(mouseX,mouseY)){
        if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            return true;
        }
    }
    return false;
}

void Button::render(GLFWwindow* window) {
    glBegin(GL_QUADS);
    glColor3f(colour.r, colour.g, colour.b);

    glVertex2f(x,y);
    glVertex2f(x+width,y);
    glVertex2f(x+width,y+height);
    glVertex2f(x,y+height);

    glEnd();

    if (isClicked(window)) {
        std::cout << "clicked" << std::endl;
    }
}

bool Button::isPointInside(float px, float py) {
    return px >= x && px <= (x+width) && py >= y && py <= (y+height);
}