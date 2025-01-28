#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE("Factorials are computed", "[factorial]")
{
    CHECK(Factorial(0) == 1);
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    SECTION("checking with +ve n")
    {
        int n = 5;
        std::vector<int> res = AddN(v, n);
        srand(time(NULL));
        int random = rand() % v.size();
        REQUIRE(v.size() == res.size());
        REQUIRE(res[0] == 6);
        REQUIRE(res[v.size() - 1] == 15);
        REQUIRE(res[random] == v[random] + n);
    }

    SECTION("checking with -ve n")
    {
        int n = -5;
        std::vector<int> res = AddN(v, n);
        srand(time(NULL));
        int random = rand() % v.size();
        REQUIRE(v.size() == res.size());
        REQUIRE(res[0] == -4);
        REQUIRE(res[v.size() - 1] == 5);
        REQUIRE(res[random] == v[random] + n);
    }
}

// Test case for SubtractN function
TEST_CASE("SubtractN function subtracts correctly from vector", "[SubtractN]")
{
    std::vector<double> input = {10.5, 20.8, 30.3};
    std::vector<double> expected = {5.0, 15.3, 24.8};
    REQUIRE(SubtractN(input, 5.5) == expected);
}

// Test case for RemoveAllSubstrings function
TEST_CASE("RemoveAllSubstrings function removes all substrings", "[RemoveAllSubstrings]")
{
    SECTION("remove all occurences of substring")
    {
        std::string text = "one, two, one, three, four";
        std::string to_remove = "one";
        std::string expected = ", two, , three, four";

        REQUIRE(RemoveAllSubstrings(text, to_remove) == expected);
    }

    SECTION("no occurrences of substring")
    {
        std::string text = "one, two, three";
        std::string to_remove = "four";
        std::string expected = "one, two, three";

        REQUIRE(RemoveAllSubstrings(text, to_remove) == expected);
    }
}

// Test case for RemoveFirstSubString function
TEST_CASE("RemoveFirstSubstring function removes first substring", "[RemoveFirstSubstring]")
{
    SECTION("remove first occurrence")
    {
        std::string text = "one, two, three, four, one";
        std::string to_remove = "one";
        std::string expected = ", two, three, four, one";

        REQUIRE(RemoveFirstSubstring(text, to_remove) == expected);
    }

    SECTION("no occurrences of substring")
    {
        std::string text = "one, two, three";
        std::string to_remove = "four";
        std::string expected = "one, two, three";

        REQUIRE(RemoveFirstSubstring(text, to_remove) == expected);
    }
}