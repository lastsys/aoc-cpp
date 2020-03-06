#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "day01.h"

TEST_CASE("Required fuel must match specification", "[2019 Day01]") {
  REQUIRE(fuel_required(12) == 2);
  REQUIRE(fuel_required(14) == 2);
  REQUIRE(fuel_required(1969) == 654);
  REQUIRE(fuel_required(100756) == 33583);
}

TEST_CASE("Added fuel must match specification", "[2019 Day01]") {
  REQUIRE(compensated_fuel_required(14) == 2);
  REQUIRE(compensated_fuel_required(1969) == 966);
  REQUIRE(compensated_fuel_required(100756) == 50346);
}
