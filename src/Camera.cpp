#include "Camera.hpp"


// All code generated from GPT prompts by Michael, Zach, and Binh unless otherwise specified
Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : m_position(position),
    m_up(up),
    m_front(glm::vec3(0.0f, 0.0f, -1.0f)),
    m_right(glm::vec3(1.0f, 0.0f, 0.0f)),
    m_yaw(yaw),
    m_pitch(pitch),
    m_fov(45.0f),
    m_aspectRatio(4.0f / 3.0f),
    m_nearClipPlane(0.1f),
    m_farClipPlane(100.0f),
    m_firstMouse(true),
    m_lastX(0.0f),
    m_lastY(0.0f)
{
    updateCameraVectors();
}

void Camera::update(const Window& window)
{
    float currentFrame = glfwGetTime();
    static float lastFrame = currentFrame;
    float deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    float cameraSpeed = 2.5f * deltaTime;
    if (glfwGetKey(window.m_window, GLFW_KEY_W) == GLFW_PRESS) //if statment parameters slightly adjusted from GPT code
        m_position += cameraSpeed * m_front;
    if (glfwGetKey(window.m_window, GLFW_KEY_S) == GLFW_PRESS) //if statement parameters slightly adjusted from GPT code
        m_position -= cameraSpeed * m_front;
    if (glfwGetKey(window.m_window, GLFW_KEY_A) == GLFW_PRESS) //if statement parameters slightly adjusted from GPT code
        m_position -= glm::normalize(glm::cross(m_front, m_up)) * cameraSpeed;
    if (glfwGetKey(window.m_window, GLFW_KEY_D) == GLFW_PRESS) //if statement parameters slightly adjusted from GPT code
        m_position += glm::normalize(glm::cross(m_front, m_up)) * cameraSpeed;

    double xpos, ypos;
    glfwGetCursorPos(window.m_window, &xpos, &ypos);
    if (m_firstMouse)
    {
        m_lastX = xpos;
        m_lastY = ypos;
        m_firstMouse = false;
    }

    float xoffset = xpos - m_lastX;
    float yoffset = m_lastY - ypos; // reversed since y-coordinates go from bottom to top
    m_lastX = xpos;
    m_lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    m_yaw += xoffset;
    m_pitch += yoffset;

    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (m_pitch > 89.0f)
        m_pitch = 89.0f;
    if (m_pitch < -89.0f)
        m_pitch = -89.0f;

    // Update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(m_position, m_position + m_front, m_up);
}

glm::mat4 Camera::getProjectionMatrix() const
{
    return glm::perspective(glm::radians(m_fov), m_aspectRatio, m_nearClipPlane, m_farClipPlane);
}

void Camera::setCameraPosition(glm::vec3 position)
{
    m_position = position;
}

void Camera::setCameraDirection(glm::vec3 direction)
{
    m_front = glm::normalize(direction);
}

void Camera::setCameraUp(glm::vec3 up)
{
    m_up = glm::normalize(up);
}

void Camera::setCameraYaw(float yaw)
{
    m_yaw = yaw;

}

void Camera::setCameraPitch(float pitch)
{
    m_pitch = pitch;

}
void Camera::setCameraFOV(float fov)
{
    m_fov = fov;
}

void Camera::setCameraAspectRatio(float aspectRatio)
{
    m_aspectRatio = aspectRatio;
}

void Camera::setCameraNearClipPlane(float nearClipPlane)
{
    m_nearClipPlane = nearClipPlane;
}

void Camera::setCameraFarClipPlane(float farClipPlane)
{
    m_farClipPlane = farClipPlane;
}

float Camera::getCameraYaw() const
{
    return m_yaw;
}

float Camera::getCameraPitch() const
{
    return m_pitch;
}

float Camera::getCameraFOV() const
{
    return m_fov;
}

glm::vec3 Camera::getCameraPosition() const
{
    return m_position;
}

glm::vec3 Camera::getCameraDirection() const
{
    return glm::normalize(m_front);
}

glm::vec3 Camera::getCameraUp() const
{
    return m_up;
}

float Camera::getCameraAspectRatio() const
{
    return m_aspectRatio;
}

float Camera::getCameraNearClipPlane() const
{
    return m_nearClipPlane;
}

float Camera::getCameraFarClipPlane() const
{
    return m_farClipPlane;
}


void Camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front = glm::normalize(front);
    m_right = glm::normalize(glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f)));
    m_up = glm::normalize(glm::cross(m_right, m_front));
}

