#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glfw3.h>

class Window
{
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose() const;
    void swapBuffers();
    GLFWwindow* getWindow() { return m_window; };

private:
    GLFWwindow* m_window;
};

#endif // WINDOW_HPP
