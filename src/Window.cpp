#include "Window.hpp"

//all code below enerated by ChatGTP prompted by Michael, Zach, and Binh unless otherwise specified
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

    //if statement added by Zach for exception check
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return;
    }

}

Window::~Window() //ChatGPT made it a const function, Zach changed to non-const function
{
    // Destroy GLFW window
    glfwDestroyWindow(m_window);

    // Terminate GLFW
    glfwTerminate();
}

bool Window::shouldClose()
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
