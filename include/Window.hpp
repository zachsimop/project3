#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <glad.h>
#include <glfw3.h>

//Binh, Michael, and Zach generated below Code from GPT
class Window
{
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose(); //Changed from const to non-const function from GTP original code
    void swapBuffers();
    GLFWwindow* getWindow() { return m_window; }; //added a getter function for easier access;
    GLFWwindow* m_window;
private:
    
};

#endif // WINDOW_HPP
