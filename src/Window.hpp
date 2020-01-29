#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include "chromaray.hpp"
#include "util/conversions.hpp"

class Window {
public:
	Window(int width, int height, std::string title);
	~Window();

	void setGLVersion(unsigned major, unsigned minor);

	// Window is not opened by default;
	// This function will construct the window with the parameters
	void open();

	void clear(int clearColour);
	void update();
	
	bool shouldClose();
private:
	std::string m_Title;
	GLFWwindow* m_Window;
	int m_Width, m_Height;
	unsigned int m_glVersion[2];
};