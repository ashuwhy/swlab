#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "hello_world.h"

TEST_CASE("Hello World from hello_world.cpp", "[hello_world]")
{
REQUIRE(print_hello_world(true) == true);
}