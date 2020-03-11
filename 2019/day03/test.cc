#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "day03.h"

TEST_CASE("Day3 example 1", "[2019 Day03]") {
  string s1("R75,D30,R83,U83,L12,D49,R71,U7,L72");
  string s2("U62,R66,U55,R34,D71,R55,D58,R83");
  auto p1 = parse_path(s1);
  auto p2 = parse_path(s2);
  REQUIRE(p1.size() == 9);
  REQUIRE(p2.size() == 8);
  REQUIRE(p1[0].orientation == Orientation::right);
  REQUIRE(p1[0].length == 75);
  REQUIRE(p1[1].orientation == Orientation::down);
  REQUIRE(p1[1].length == 30);
  REQUIRE(p1[2].orientation == Orientation::right);
  REQUIRE(p1[2].length == 83);
  REQUIRE(p1[3].orientation == Orientation::up);
  REQUIRE(p1[3].length == 83);
  REQUIRE(p1[4].orientation == Orientation::left);
  REQUIRE(p1[4].length == 12);

  auto d = distance_to_closest_intersection(p1, p2);
  REQUIRE(d == 159);
}
