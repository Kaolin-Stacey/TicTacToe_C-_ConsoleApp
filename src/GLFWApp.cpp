#include "GLFWApp.h"
#include <iostream>

GLFWApp::GLFWApp(int width, int height, const std::string& title)
	: width(width), height(height), title(title), window(nullptr)
{
	initGLFW();
}

GLFWApp::~GLFWApp() {
	if (window) {
		glfwDestroyWindow(window);
	}
	glfwTerminate();
}

void GLFWApp::errorCallback(int error, const char* description) {
	std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}

void GLFWApp::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void GLFWApp::initGLFW() {
	if (!glfwInit()) {
		throw std::runtime_error("Failed to initialise GLFW");
	}

	glfwSetErrorCallback(errorCallback);

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, keyCallback);
	glfwSwapInterval(1);
} 

void GLFWApp::mainLoop() {
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}
}

void GLFWApp::run() {
	mainLoop();
}