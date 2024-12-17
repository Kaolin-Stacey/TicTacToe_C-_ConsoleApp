
#include "GLFWApp.h"
#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <fstream>


GLFWApp::GLFWApp(int width, int height, const std::string& title)
	: width(width), height(height), title(title), window(nullptr)
{
	initGLFW();
	initImGui();
}

GLFWApp::~GLFWApp() {
	cleanupImGui();
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

	// Set the OpenGL version to 4.6
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, keyCallback);
	glfwSwapInterval(1);
} 

void GLFWApp::initImGui() {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void) io;

	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 450");
}


void GLFWApp::cleanupImGui() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void GLFWApp::run() {
	mainLoop();
}
void GLFWApp::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImVec2 windowSize = ImGui::GetIO().DisplaySize;

        float buttonWidth = windowSize.x * 0.5f;
        float buttonHeight = windowSize.y * 0.1f;  // Adjust height dynamically to make buttons larger

        buttonWidth = std::max(buttonWidth, 200.0f);  // Ensure a minimum width of 200px

        // Set cursor position for Main Menu (you can adjust this based on your design)
        ImGui::SetCursorPos(ImVec2(windowSize.x * 0.5f - buttonWidth * 0.5f, windowSize.y * 0.2f));

        // Begin the "Main Menu" window without title bar, no resizing, no scrollbar
        ImGui::Begin("Main Menu", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);

        switch(currentMode) {
            case GameMode::MainMenu:
                if (ImGui::Button("Player vs AI", ImVec2(buttonWidth, buttonHeight))) {
                    currentMode = GameMode::PlayerVsAi;
                    std::cout << "Switched to Player vs AI!" << std::endl;
                }

                if (ImGui::Button("Player vs Player (Local)", ImVec2(buttonWidth, buttonHeight))) {
                    currentMode = GameMode::PlayerVsPlayerLocal;
                    std::cout << "Switched to Player vs Player (Local)!" << std::endl;
                }

                if (ImGui::Button("Player vs Player (Online)", ImVec2(buttonWidth, buttonHeight))) {
                    currentMode = GameMode::PlayerVsPlayerOnline;
                    std::cout << "Switched to Player vs Player (Online)!" << std::endl;
                }
                break;

            case GameMode::PlayerVsAi:
                ImGui::Text("Player vs AI mode activated!");
                if (ImGui::Button("Back to Main Menu", ImVec2(buttonWidth, buttonHeight))) {
                    currentMode = GameMode::MainMenu;
                }
                break;

            case GameMode::PlayerVsPlayerLocal:
                ImGui::Text("Player vs Player (Local) mode activated!");
                if (ImGui::Button("Back to Main Menu", ImVec2(buttonWidth, buttonHeight))) {
                    currentMode = GameMode::MainMenu;
                }
                break;

            case GameMode::PlayerVsPlayerOnline:
                ImGui::Text("Player vs Player (Online) mode activated!");
                if (ImGui::Button("Back to Main Menu", ImVec2(buttonWidth, buttonHeight))) {
                    currentMode = GameMode::MainMenu;
                }
                break;
        }

        ImGui::End();  // End the "Main Menu" window

        ImGui::Render();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
}
