cmake_minimum_required(VERSION 3.10)
project(DirectoryBrowser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(directory_browser 
    src/main.cpp
    src/directory_scanner.cpp
    src/html_generator.cpp
)

# Copy templates to build directory
file(COPY ${CMAKE_SOURCE_DIR}/src/templates DESTINATION ${CMAKE_BINARY_DIR})
