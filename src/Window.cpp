#include "Window.hpp"

#include <iostream>

static GLFWwindow* window;
static const char* title;

namespace ChCore {
	void createWindow(WindowProperties properties) {
		if (!glfwInit())
			std::cerr << "Could not initialize GLFW!\n";

		// There is no way to get the window title out from GLFW so it has to be stored separately.
		title = properties.title;
		window = glfwCreateWindow(properties.width, properties.height, properties.title, nullptr, nullptr);

		if (!window)
			std::cerr << "Could not create a GLFW window!\n";

		// Sets the OpenGL version to 3.2
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

		// Set the OpenGL context to this window
		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK)
			std::cerr << "Could not initialize GLEW!\n";
	}

	void destroyWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	WindowProperties getWindowProperties() {
		WindowProperties properties;

		// Get the window size.
		glfwGetFramebufferSize(window, &properties.width, &properties.height);
		properties.title = title;

		return properties;
	}
	
	bool keyDown(int keyCode) {
		return glfwGetKey(window, keyCode);
	}

	bool updateWindow() {
		glfwSwapBuffers(window);
		glfwPollEvents();

		return !glfwWindowShouldClose(window);
	}
}
