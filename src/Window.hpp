#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include <unordered_map>

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
	bool isDown(int keyCode);

	void clear(int clearColour);
	void update();
	
	int getWidth() const;
	int getHeight() const;

	bool shouldClose();
private:
	GLFWwindow* m_Window;
	
	std::string m_Title;
	int m_Width, m_Height;
	unsigned m_glVersion[2];
};