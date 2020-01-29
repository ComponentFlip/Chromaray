#include "Window.hpp"

void onResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char* title)
:
	m_Width(width)
	, m_Height(height)
	, m_glVersion({0, 0})
	, m_Title(title)
{
	// Initialize GLFW
	if (!glfwInit())
		std::cout << "Failed to initialize GLFW!" << std::endl;
}

Window::~Window() {
	// Terminate GLFW window after we're finished
	glfwTerminate();
}

void Window::set_gl_version(unsigned major, unsigned minor) {
	m_glVersion[0] = major;
	m_glVersion[1] = minor;
}

void Window::open() {
	// Set OpenGL version
	if (m_glVersion[0] != 0) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_glVersion[0]);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_glVersion[1]);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	// Create GLFW window and store it in our class
	this->m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);
	if (!m_Window) {
		glfwTerminate();
		std::cout << "Failed to initialize window!" << std::endl;
	}

	// Set callback function for resizing the window
	glfwSetWindowSizeCallback(m_Window, onResize);

	// Set window context current for OpenGL
	glfwMakeContextCurrent(m_Window);

	// Initialize GLEW so we can use modern OpenGL functions
	if (glewInit() != GLEW_OK)
		std::cout << "Failed to initialize GLEW!" << std::endl;

	// Initialize OpenGL viewport
	glViewport(0, 0, m_Width, m_Height);
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
