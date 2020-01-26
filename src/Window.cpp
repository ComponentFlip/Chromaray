#include "Window.hpp"

void onResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char* title) : m_Width(width), m_Height(height) {
	// Initialize GLFW
	if (!glfwInit())
		std::cout << "Failed to initialize GLFW!" << std::endl;

	// Create GLFW window and store it in our class
	this->m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!this->m_Window) {
		glfwTerminate();
		std::cout << "Failed to initialize window!" << std::endl;
	}

	// Set callback function for resizing the window
	glfwSetWindowSizeCallback(this->m_Window, onResize);

	// Set window context current for OpenGL
	glfwMakeContextCurrent(this->m_Window);

	// Initialize GLEW so we can use modern OpenGL functions
	if (glewInit() != GLEW_OK)
		std::cout << "Failed to initialize GLEW!" << std::endl;

	// Initialize OpenGL viewport
	glViewport(0, 0, m_Width, m_Height);
}

Window::~Window() {
	// Terminate GLFW window after we're finished
	glfwTerminate();
}

void Window::clear(int clearColour) {
	// Indicate which buffer(s) to clear
	glClear(GL_COLOR_BUFFER_BIT);

	FloatColour colour = RGBtoFloats(clearColour);
	glClearColor(colour.r, colour.g, colour.b, colour.a);
}

void Window::update() {
	// Swap window back buffer & front buffer
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(m_Window);
}
