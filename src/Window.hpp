#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window(int width, int height, const char* title);
	~Window();

	int getWidth();
	int getHeight();

	void update();
	bool shouldClose();
private:
	GLFWwindow* m_Window;
	int m_Width, m_Height;
};