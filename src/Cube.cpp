#include "Cube.hpp"

Cube::Cube()
{
    GLfloat vertices[] = {
        // Front face
        -0.5f, -0.5f,  0.5f,  // Bottom-left
         0.5f, -0.5f,  0.5f,  // Bottom-right
         0.5f,  0.5f,  0.5f,  // Top-right
        -0.5f,  0.5f,  0.5f,  // Top-left
        // Back face
        -0.5f, -0.5f, -0.5f,  // Bottom-left
         0.5f, -0.5f, -0.5f,  // Bottom-right
         0.5f,  0.5f, -0.5f,  // Top-right
        -0.5f,  0.5f, -0.5f,  // Top-left
    };

    GLuint indices[] = {
        // Front face
        0, 1, 2,
        2, 3, 0,
        // Right face
        1, 5, 6,
        6, 2, 1,
        // Back face
        7, 6, 5,
        5, 4, 7,
        // Left face
        4, 0, 3,
        3, 7, 4,
        // Bottom face
        4, 5, 1,
        1, 0, 4,
        // Top face
        3, 2, 6,
        6, 7, 3,
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind VBO and EBO and upload data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
   
    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Unbind VAO
    glBindVertexArray(0);
}

void Cube::draw(Shader& shader)
{
    // Bind VAO
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);

    // Draw cube
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // Unbind VAO
    glBindVertexArray(0);
}