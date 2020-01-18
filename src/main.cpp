#include "chromaray.h"
#include "Window.h"

int main() {
	Window window(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, G_WINDOW_TITLE);

	while (!window.shouldClose()) {
		window.clear();

		glColor4f(0.2f, 0.2f, 0.4f, 1.0f);

		glBegin(GL_QUADS);
		{
			glVertex2f(-0.5f,  0.5f);
			glVertex2f( 0.5f,  0.5f);
			glVertex2f( 0.5f, -0.5f);
			glVertex2f(-0.5f, -0.5f);
		}
		glEnd();

		window.update();
	}

	return 0;
}