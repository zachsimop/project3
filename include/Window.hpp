#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <glad.h>
#include <glfw3.h>

class Window
{
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose();
    void swapBuffers();
    GLFWwindow* getWindow() { return m_window; };
    GLFWwindow* m_window;
private:
    
};

#endif // WINDOW_HPP
