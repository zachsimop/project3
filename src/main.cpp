#include <iostream>
#include "Cube.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include "Shader.hpp"

// All code generated from GPT prompts by Binh, Michael, and Zach unless otherwise specified
int main()
{
    // Create window
    Window window(800, 600, "My OpenGL Window");

    // Initialize camera
    Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

    // Initialize cube
    Cube cube;

    // Initialize shader, custom code added by Zach
    Shader shader("C:\\Users\\zachs\\vandy-c\\cc\\p3\\code\\shaders\\vertex_shader.glsl", 
        "C:\\Users\\zachs\\vandy-c\\cc\\p3\\code\\shaders\\fragment_shader.glsl");

    // Render loop
    while (!window.shouldClose())
    {
        // Clear screen
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT); //programmer-added line
        glEnable(GL_DEPTH_TEST);//programmer-added line
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //programmer-added line

        // Update camera
        camera.update(window);

        // Draw cube
        shader.use();
        shader.setMat4("view", camera.getViewMatrix());
        shader.setMat4("model", glm::mat4(1.0f)); //programmer-added line
        shader.setMat4("projection", camera.getProjectionMatrix());
        cube.draw(shader);
        // Swap buffers
        window.swapBuffers();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}