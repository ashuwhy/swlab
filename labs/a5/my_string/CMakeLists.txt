cmake_minimum_required(VERSION 3.10)
project(MyString VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create library
add_library(mystring
    src/MyString.cpp
)

# Create test executable
add_executable(mystring_test
    tests/MyStringTest.cpp
)
target_link_libraries(mystring_test mystring)

# Enable testing
enable_testing()
add_test(NAME MyStringTests COMMAND mystring_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

# Adding coverage task

find_program(LCOV_PATH lcov)
find_program(GENHTML_PATH genhtml)

add_custom_target(coverage
    COMMAND ${LCOV_PATH} --capture --directory . --output-file coverage.info
    COMMAND ${LCOV_PATH} --remove coverage.info '/usr/*' '*/tests/*' '*/cmake_tests/include/*' --output-file
coverage_filtered.info
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