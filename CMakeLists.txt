cmake_minimum_required(VERSION 3.28)
project(tic-tac)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/.release")

add_executable(
        ${PROJECT_NAME}
        main.cpp
        AI.cpp
        Board3x3.cpp
        Board4x4.cpp
        FontLoader.cpp
        GestureRecognizer.cpp
        MenuButton.cpp
        Renderer.cpp
)