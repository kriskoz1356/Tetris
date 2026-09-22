cmake_minimum_required(VERSION 3.16)

project(Tetris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(Tetris
    src/main.cpp
    src/Game.cpp
    src/Board/Board.cpp
    src/Tetromino/Tetromino.cpp
)

target_include_directories(Tetris PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Board
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Tetromino
)

target_link_libraries(Tetris PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)