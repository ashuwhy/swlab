cmake_minimum_required(VERSION 3.10)
project(MontyHallGame VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(monty_hall_game
    main.cpp
    src/MontyHallGame.cpp
)