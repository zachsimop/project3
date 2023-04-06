#include "Window.hpp"

Window::Window(int width, int height, const char* title)
{
    // Initialize GLFW
    glfwInit();

    // Set GLFW window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create GLFW window
    m_window = glfwCreateWindow(width, height, title, NULL, NULL);

    // Make the window's context current
    glfwMakeContextCurrent(m_window);
}

Window::~Window()
{
    // Destroy GLFW window
    glfwDestroyWindow(m_window);

    // Terminate GLFW
    glfwTerminate();
}

bool Window::shouldClose() const
{
    // Check if the GLFW window should close
    return glfwWindowShouldClose(m_window);
}

void Window::swapBuffers()
{
    // Swap the front and back buffers
    glfwSwapBuffers(m_window);

    // Poll for and process events
    glfwPollEvents();
}
