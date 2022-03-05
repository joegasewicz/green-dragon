cmake_minimum_required(VERSION 3.21)
project(green_dragon)

set(CMAKE_CXX_STANDARD 17)

# Move assets
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Add SFML
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})

# Build targets
add_executable(green_dragon main.cpp)
target_link_libraries(green_dragon sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

