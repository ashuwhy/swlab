#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "list.h"

TEST_CASE("List Basic Operations", "[List]") {
    List list;

    SECTION("Append Elements") {
        list.append(10);
        REQUIRE(list.getSize() == 1);
        list.append(20);
        REQUIRE(list.getSize() == 2);
        list.append(30);
        REQUIRE(list.getSize() == 3);
        list.append(40);
        REQUIRE(list.getSize() == 4);
        list.append(50);
        REQUIRE(list.getSize() == 5);
    }

    SECTION("Access Elements with []") {
        list.append(10);
        list.append(20);
        list.append(30);
        list.append(40);
        list.append(50);
       REQUIRE(list[0] == 10);
       REQUIRE(list[1] == 20);
       REQUIRE(list[2] == 30);
       REQUIRE(list[3] == 40);
       REQUIRE(list[4] == 50);
    }

    SECTION("Out of Range Access Throws Exception") {
        list.append(5);
        REQUIRE_THROWS_AS(list[10], std::out_of_range);
        REQUIRE_THROWS_AS(list[11], std::out_of_range);
        REQUIRE_THROWS_AS(list[12], std::out_of_range);
        REQUIRE_THROWS_AS(list[13], std::out_of_range);
        REQUIRE_THROWS_AS(list[14], std::out_of_range);
    }
}

TEST_CASE("List Concatenation with + Operator", "[List]") {
    List list1, list2, list3;

    SECTION("Concatenate Two Lists") {
        list1.append(10);
        list1.append(20);
        list1.append(30);
        list1.append(40);
        list1.append(50);

        list2.append(10);
        list2.append(20);
        list2.append(30);
        list2.append(40);
        list2.append(50);
        list3=list1+list2;
        REQUIRE(list3.getSize() == 10);
    }
}

TEST_CASE("List Stream Output with <<", "[List]") {
    List list;
    list.append(5);
    list.append(10);
    list.append(15);

    SECTION("Stream Output") {
        std::ostringstream oss;
        oss << list;
        REQUIRE(oss.str() == "[5, 10, 15]");
    }
}