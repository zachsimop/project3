#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad.h> //Changed By Zach for proper include
#include <glfw3.h> //Changed By Zach for proper include
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


//Michael, Binh, and Zach generated below code from GTP
class Shader
{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setMat4(const std::string& name, const glm::mat4& value) const;

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif
