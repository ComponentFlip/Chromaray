#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace ChCore {
	// Defines information about the window size and title.
	struct WindowProperties {
		int width, height;
		const char* title;
	};

	void createWindow(WindowProperties properties);
	void destroyWindow();

	bool keyDown(int keyCode);

	WindowProperties getWindowProperties();

	// Returns false if the window should be closed.
	bool updateWindow();
}
