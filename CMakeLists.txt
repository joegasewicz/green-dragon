cmake_minimum_required(VERSION 3.21)
project(green_dragon)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})

add_executable(green_dragon main.cpp)
target_link_libraries(green_dragon sfml-system sfml-window sfml-graphics sfml-network sfml-audio)