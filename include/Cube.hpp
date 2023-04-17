#pragma once
//Zach Comment: included glew, not glad and did not include shaders

#include "Shader.hpp" //Zach added line to include shader, GTP used shader in the code but did not include the class

//Binh, Michael and Zach generated below code from GPT
class Cube
{
public:
    Cube();

    void draw(Shader& shader);

private:
    GLuint VAO, VBO, EBO;
};