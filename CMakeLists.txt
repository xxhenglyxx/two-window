
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(two-window)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/macosx)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL)
find_package(GLUT)

find_library(COCOA Cocoa)

include_directories(
    include
    ${OPENGL_INCLUDE_DIR}
    ${GLUT_INCLUDE_DIR}
)

add_executable(
    two-window
    src/main.cpp
    src/teapot.cpp
)

target_link_libraries(
    two-window
    ${COCOA_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)