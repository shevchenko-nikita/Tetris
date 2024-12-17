cmake_minimum_required(VERSION 3.21)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tetris src/main.cpp src/shape.cpp src/field.cpp)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")

target_link_libraries(Tetris sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)