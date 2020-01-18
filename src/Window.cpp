#include "Window.h"

void onResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char* title) : m_Width(width), m_Height(height) {
	if (!glfwInit())
		LOG_ERROR("Failed to initialize GLFW!");

	m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!m_Window) {
		glfwTerminate();
		LOG_ERROR("Failed to initialize window!");
	}

	glfwSetWindowSizeCallback(m_Window, onResize);

	glfwMakeContextCurrent(m_Window);

	if (glewInit() != GLEW_OK)
		LOG_ERROR("Failed to initialize GLEW!");

	glViewport(0, 0, m_Width, m_Height);
}

Window::~Window() {
	glfwTerminate();
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
}

void Window::update() {
	glfwSwapBuffers(m_Window);

	glfwPollEvents();
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(m_Window);
}
