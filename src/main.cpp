#include <iostream>
#include "Cube.hpp"
#include "Camera.hpp"
#include "Shader.hpp"
#include "Window.hpp"

int main()
{
    // Create window
    Window window(800, 600, "My OpenGL Window");

    // Initialize camera
    Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

    // Initialize cube
    Cube cube;

    // Initialize shader
    Shader shader("shaders/vertex.shader", "shaders/fragment.shader");

    // Render loop
    while (!window.shouldClose())
    {
        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update camera
        camera.update(window);

        // Draw cube
        shader.use();
        shader.setMat4("view", camera.getViewMatrix());
        shader.setMat4("projection", camera.getProjectionMatrix());
        cube.draw(shader);

        // Swap buffers
        window.swapBuffers();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}