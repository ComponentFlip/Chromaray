#include "Window.hpp"

void onResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

Window::Window(int width, int height, std::string title) : m_Width(width), m_Height(height) {
	// Set to 0 until an OpenGL version is specified
	setGLVersion(0, 0);

	// Some compilers complain about having this string in the initializer list so we initialize it here
	m_Title = title;

	// Initialize GLFW
	if (!glfwInit())
		std::cout << "Failed to initialize GLFW!" << std::endl;
}

Window::~Window() {
	glfwTerminate();
}

void Window::setGLVersion(unsigned major, unsigned minor) {
	m_glVersion[0] = major;
	m_glVersion[1] = minor;
}

void Window::open() {
	// Set OpenGL version if one has been specified
	if (m_glVersion[0] != 0) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_glVersion[0]);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_glVersion[1]);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	// Create GLFW window and store it in our class
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);
	if (!m_Window) {
		glfwTerminate();
		std::cout << "Failed to initialize window!" << std::endl;
	}

	glfwSetWindowSizeCallback(m_Window, onResize);
	glfwMakeContextCurrent(m_Window);

	// Initialize GLEW so we can use modern OpenGL functions
	if (glewInit() != GLEW_OK)
		std::cout << "Failed to initialize GLEW!" << std::endl;

	glViewport(0, 0, m_Width, m_Height);
}

void Window::clear(int clearColour) {
	// Indicate which buffers to clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
