#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include "chromaray.hpp"
#include "util/conversions.h"

class Window {
public:
	Window(int width, int height, const char* title);
	~Window();

	void set_gl_version(unsigned major, unsigned minor);

	// Window is not opened by default;
	// This function will construct the window with the parameters
	void open();

	void clear(int clearColour);
	void update();
	// Wrapper around glfwWindowShouldClose
	bool shouldClose();
private:
	std::string m_Title;
	GLFWwindow* m_Window;
	int m_Width, m_Height;
	unsigned int m_glVersion[2];
};