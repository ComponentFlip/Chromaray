#pragma once

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include "chromaray.hpp"

class Window {
public:
	Window(int width, int height, const char* title);
	~Window();

	void clear();
	void update();
	bool shouldClose();
private:
	GLFWwindow* m_Window;
	int m_Width, m_Height;
};