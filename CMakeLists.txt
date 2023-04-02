# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and languages
project(ProjectName CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find required packages
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(Bullet REQUIRED)
find_package(glm REQUIRED)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${BULLET_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})

# Set source files
set(SOURCES
        main.cpp
        src/MainWindow.cpp
        src/PhysicsEngine.cpp
        src/GraphicsEngine.cpp
        # Add additional source files here
        )

# Set header files
set(HEADERS
        src/MainWindow.h
        src/PhysicsEngine.h
        src/GraphicsEngine.h
        # Add additional header files here
        )

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link required libraries
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets ${BULLET_LIBRARIES})

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
