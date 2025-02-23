#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MyString.h"

TEST_CASE("MyString Print", "[mystring]") {
    SECTION("Testting <<") {
        MyString s("Let's Test\n");
        std::cout << s;
        REQUIRE(strcmp(s.c_str(), "Let's Test\n") == 0);
    }
}

TEST_CASE("MyString Construction", "[mystring]") {
    SECTION("Default constructor creates empty string") {
        MyString s;
        REQUIRE(s.size() == 0);
        REQUIRE(strcmp(s.c_str(), "") == 0);
    }

    SECTION("Parameterized constructor creates correct string") {
        MyString s("Hello");
        REQUIRE(s.size() == 5);
        REQUIRE(strcmp(s.c_str(), "Hello") == 0);
    }

    SECTION("Copy constructor creates identical string") {
        MyString s1("Hello");
        MyString s2(s1);
        REQUIRE(s2.size() == s1.size());
        REQUIRE(strcmp(s2.c_str(), s1.c_str()) == 0);
    }

    SECTION("Constructor with nullptr") {
        MyString s(nullptr);
        REQUIRE(s.size() == 0);
        REQUIRE(strcmp(s.c_str(), "") == 0);
    }
}

TEST_CASE("MyString Assignment", "[mystring]") {
    SECTION("Assignment operator performs deep copy") {
        MyString s1("Hello");
        MyString s2;
        s2 = s1;
        REQUIRE(strcmp(s2.c_str(), "Hello") == 0);
        
        // Modify s1 to ensure deep copy
        s1 = MyString("World");
        REQUIRE(strcmp(s2.c_str(), "Hello") == 0);
    }

    SECTION("Self assignment") {
        MyString s1("Hello");
        s1 = s1;
        REQUIRE(strcmp(s1.c_str(), "Hello") == 0);
    }
}

TEST_CASE("MyString Concatenation", "[mystring]") {
    SECTION("Concatenation of two strings") {
        MyString s1("Hello");
        MyString s2(" World");
        MyString s3 = s1 + s2;
        REQUIRE(strcmp(s3.c_str(), "Hello World") == 0);
    }

    SECTION("Concatenation with empty string") {
        MyString s1("Hello");
        MyString s2;
        MyString s3 = s1 + s2;
        REQUIRE(strcmp(s3.c_str(), "Hello") == 0);
    }
}

TEST_CASE("MyString Comparison", "[mystring]") {
    SECTION("Case-insensitive comparison") {
        MyString s1("Hello");
        MyString s2("HELLO");
        MyString s3("World");
        
        REQUIRE(s1 == s2);
        REQUIRE_FALSE(s1 == s3);
    }

    SECTION("Empty string comparison") {
        MyString s1;
        MyString s2;
        REQUIRE(s1 == s2);
    }
}

TEST_CASE("MyString Reverse", "[mystring]") {
    SECTION("Reverse even-length string") {
        MyString s("Hello");
        reverse(s);
        REQUIRE(strcmp(s.c_str(), "olleH") == 0);
    }

    SECTION("Reverse odd-length string") {
        MyString s("World");
        reverse(s);
        REQUIRE(strcmp(s.c_str(), "dlroW") == 0);
    }

    SECTION("Reverse empty string") {
        MyString s;
        reverse(s);
        REQUIRE(strcmp(s.c_str(), "") == 0);
    }

    SECTION("Reverse single character") {
        MyString s("A");
        reverse(s);
        REQUIRE(strcmp(s.c_str(), "A") == 0);
    }
}