#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "day06.h"

#include <string>
#include <vector>

using namespace std;

TEST_CASE("Day6 example 1", "[2019 Day06]") {
  vector<string> ex {
    "COM)B", "B)C", "C)D", "D)E", "E)F", "B)G", "G)H", "D)I", "E)J", "J)K", "K)L"
  };

  auto orbits = parse_orbits(ex);
  auto count = count_orbits(orbits);
  REQUIRE(count == 42);
}
