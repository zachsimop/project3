#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glfw3.h>
#include "Window.hpp"

class Camera
{
public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
        float yaw = -90.0f, float pitch = 0.0f);

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix() const;

    void update(const Window& window);

    void setCameraPosition(glm::vec3 position);
    void setCameraDirection(glm::vec3 direction);
    void setCameraUp(glm::vec3 up);
    void setCameraYaw(float yaw);
    void setCameraPitch(float pitch);
    void setCameraFOV(float fov);
    void setCameraAspectRatio(float aspectRatio);
    void setCameraNearClipPlane(float nearClipPlane);
    void setCameraFarClipPlane(float farClipPlane);

    glm::vec3 getCameraPosition() const;
    glm::vec3 getCameraDirection() const;
    glm::vec3 getCameraUp() const;
    float getCameraYaw() const;
    float getCameraPitch() const;
    float getCameraFOV() const;
    float getCameraAspectRatio() const;
    float getCameraNearClipPlane() const;
    float getCameraFarClipPlane() const;

private:
    glm::vec3 m_position;
    glm::vec3 m_up;
    glm::vec3 m_front;
    glm::vec3 m_right;
    float m_yaw;
    float m_pitch;
    float m_fov;
    float m_aspectRatio;
    float m_nearClipPlane;
    float m_farClipPlane;
    bool m_firstMouse;
    float m_lastX;
    float m_lastY;

    void updateCameraVectors();
};

#endif // CAMERA_HPP
