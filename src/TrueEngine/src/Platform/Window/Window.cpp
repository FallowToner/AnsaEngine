#include "Platform/Window/Window.hpp"

#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void TrueEngine::Platform::Window::CreateWindow()
{
	glfwInit();

	windowHandler = glfwCreateWindow(600, 600, "Pized", nullptr, nullptr);
	if (!windowHandler)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(windowHandler);
	// Set the required callback functions
	glfwSetKeyCallback(windowHandler, key_callback);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
	}

	int width, height;
	glfwGetFramebufferSize(windowHandler, &width, &height);
	glViewport(0, 0, width, height);

	while (!glfwWindowShouldClose(windowHandler))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response
		// functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//		glClear(GL_COLOR_BUFFER_BIT);

		// Swap the screen buffers
		glfwSwapBuffers(windowHandler);
	}
	glfwTerminate();
}
