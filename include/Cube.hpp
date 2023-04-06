#pragma once
//included glew and did not include shaders

#include <glfw3.h>
#include "Shader.hpp"
class Cube
{
public:
    Cube();

    void draw(Shader& shader);

private:
    GLuint VAO, VBO, EBO;
};