#include "Window.hpp"

#include <iostream>

Window::Window(int width, int height, const char* title) : m_Width(width), m_Height(height) {
	if (!glfwInit())
		std::cerr << "Could not initialize GLFW!\n";

	m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	if (!m_Window)
		std::cerr << "Could not create a GLFW window!\n";

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	// Set the OpenGL context to this window
	glfwMakeContextCurrent(m_Window);

	if (glewInit() != GLEW_OK)
		std::cerr << "Could not initialize GLEW!\n";
}

Window::~Window() {
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

int Window::getWidth() {
	return m_Width;
}

int Window::getHeight() {
	return m_Height;
}

void Window::update() {
	glfwSwapBuffers(m_Window);
	glfwPollEvents();

	// Update the width and height
	glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(m_Window);
}