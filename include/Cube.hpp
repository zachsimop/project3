#pragma once

#include <GL/glew.h>

class Cube
{
public:
    Cube();

    void draw(Shader& shader);

private:
    GLuint VAO, VBO, EBO;
};