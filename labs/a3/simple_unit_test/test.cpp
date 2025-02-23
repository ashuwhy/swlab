#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "operations.h"

TEST_CASE("Checking Operations", "[operations]")
{
    Operations operations;
    SECTION("Addition")
    {
        REQUIRE(operations.add(5, 3) == 8);
        REQUIRE(operations.add(8, 3) == 11);
        REQUIRE(operations.add(5, 3) != -8);

        //Five more assertions
        REQUIRE(operations.add(10, 3) == 13);
        REQUIRE(operations.add(100, -2) == 98);
        REQUIRE(operations.add(50, 5) == 55);
        REQUIRE(operations.add(6, 6) == 12);
        REQUIRE(operations.add(9, 5) != -14);
    }

    SECTION("Multiplication")
    {
        //Ten Assertions
        REQUIRE(operations.multiply(5, 3) != 8);
        REQUIRE(operations.multiply(5, 3) == 15);
        REQUIRE(operations.multiply(8, 3) == 24);
        REQUIRE(operations.multiply(9, 5) == 45);
        REQUIRE(operations.multiply(10, 3) == 30);
        REQUIRE(operations.multiply(100, -2) == -200);
        REQUIRE(operations.multiply(50, 5) == 250);
        REQUIRE(operations.multiply(6, 66) == 396);
        REQUIRE(operations.multiply(6, -6) == -36);
        REQUIRE(operations.multiply(90, 6) == 540);
    }
}