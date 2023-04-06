#pragma once
//included glew, not glad and did not include shaders

#include "Shader.hpp"
class Cube
{
public:
    Cube();

    void draw(Shader& shader);

private:
    GLuint VAO, VBO, EBO;
};