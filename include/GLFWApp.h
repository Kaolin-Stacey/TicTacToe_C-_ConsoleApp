#ifndef GLFWApp_H
#define GLFWAPP_H

#include "glfw3.h"
#include <string>
#include "GameMode.h"

class GLFWApp
{
public:
	GLFWApp(int width, int height, const std::string& title);
	~GLFWApp();

	void run();

private:
	GLFWwindow* window;
	int width;
	int height;
	std::string title;

	static void errorCallback(int error, const char* description);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	void initGLFW();
	void mainLoop();

	GameMode currentMode = GameMode::MainMenu;
};

#endif