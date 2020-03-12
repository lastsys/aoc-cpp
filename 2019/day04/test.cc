#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "day04.h"

TEST_CASE("Day4 example 1", "[2019 Day04]") {
  REQUIRE(check_repeating_numbers(122345));
  REQUIRE(check_numbers_non_decreasing(111123));
  REQUIRE(check_numbers_non_decreasing(135679));
  REQUIRE(check_repeating_numbers(111111));
  REQUIRE(check_numbers_non_decreasing(111111));
  REQUIRE_FALSE(check_numbers_non_decreasing(223450));
  REQUIRE(check_repeating_numbers(223450));
  REQUIRE_FALSE(check_repeating_numbers(123789));
  REQUIRE(check_numbers_non_decreasing(123789));
}

TEST_CASE("Day4 example 2", "[2019 Day04]") {
  REQUIRE(check_numbers_non_decreasing(112233));
  REQUIRE(check_exact_pair(112233));
  REQUIRE(check_numbers_non_decreasing(123444));
  REQUIRE_FALSE(check_exact_pair(123444));
  REQUIRE(check_numbers_non_decreasing(111122));
  REQUIRE(check_exact_pair(111122));
  REQUIRE(check_numbers_non_decreasing(111223));
  REQUIRE(check_exact_pair(111223));
}
