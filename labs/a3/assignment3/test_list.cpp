#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "list.h"

TEST_CASE("List Basic Operations", "[List]") {
    List list;

    SECTION("Append Elements") {
        list.append(1);
        REQUIRE(list.getSize() == 1);
    }

    SECTION("Access Elements with []") {
       // Implement this code
    }

    SECTION("Out of Range Access Throws Exception") {
        list.append(5);
        REQUIRE_THROWS_AS(list[1], std::out_of_range);
    }
}

TEST_CASE("List Concatenation with + Operator", "[List]") {

    SECTION("Concatenate Two Lists") {
       
    }
}

TEST_CASE("List Stream Output with <<", "[List]") {
    // Implement this code

    SECTION("Stream Output") {
        std::ostringstream oss;
        oss << list;
        REQUIRE(oss.str() == "[5, 10, 15]");
    }
}