# Required for compatibility reasons
cmake_minimum_required(VERSION 3.10)

# Name of the project and the release version
project(HelloWorldProject VERSION 1.0)

# This specifies the C++ standard version we want our project to be
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# We are including the header files required
include_directories(include)

# The following specifies the name of the executable - 'HelloWorldProject'
add_executable(HelloWorldProject main.cpp src/hello_world.cpp)

# Added the following lines for integrating tests
add_executable(HelloWorldTest tests/test_hello_world.cpp src/hello_world.cpp)

enable_testing()

add_test(NAME HelloWorldTest COMMAND HelloWorldTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

# Adding coverage task

find_program(LCOV_PATH lcov)
find_program(GENHTML_PATH genhtml)

add_custom_target(coverage
    COMMAND ${LCOV_PATH} --capture --directory . --output-file coverage.info
    COMMAND ${LCOV_PATH} --remove coverage.info '/usr/*' '*/tests/*' '*/cmake_tests/include/*' --output-file coverage_filtered.info
    COMMAND ${GENHTML_PATH} coverage_filtered.info --output-directory coverage_report
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Creating coverage"
)

add_custom_target(coverage_clean
    COMMAND find . -name "*.gcda" -delete
    COMMAND find . -name "*.gcno" -delete
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Deleted the coverage files"
)