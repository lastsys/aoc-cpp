#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "intcode.h"
#include "day02.h"

TEST_CASE("Day2 example 1", "[2019 Day02]") {
  vector<int32_t> prg {1,9,10,3,2,3,11,0,99,30,40,50};
  auto ic = IntCode<int32_t>(prg);
  ic.step();
  REQUIRE(ic.mem[3] == 70);
  ic.step();
  REQUIRE(ic.mem[0] == 3500);
  ic.step();
  REQUIRE(ic.state == IntCodeState::halted);
}

TEST_CASE("Day2 example 2", "[2019 Day02]") {
  vector<int32_t> prg {1, 0, 0, 0, 99};
  vector<int32_t> expected {2, 0, 0, 0, 99};
  auto ic = IntCode<int32_t>(prg);
  while (ic.state != IntCodeState::halted) {
    ic.step();
  }
  for (int i = 0; i < prg.size(); ++i) {
    REQUIRE(ic.mem[i] == expected[i]);
  }
}

TEST_CASE("Day2 example 3", "[2019 Day02]") {
  vector<int32_t> prg {2, 3, 0, 3, 99};
  vector<int32_t> expected {2, 3, 0, 6, 99};
  auto ic = IntCode<int32_t>(prg);
  while (ic.state != IntCodeState::halted) {
    ic.step();
  }
  for (int i = 0; i < prg.size(); ++i) {
    REQUIRE(ic.mem[i] == expected[i]);
  }
}

TEST_CASE("Day2 example 4", "[2019 Day02]") {
  vector<int32_t> prg {2, 4, 4, 5, 99, 0};
  vector<int32_t> expected {2, 4, 4, 5, 99, 9801};
  auto ic = IntCode<int32_t>(prg);
  while (ic.state != IntCodeState::halted) {
    ic.step();
  }
  for (int i = 0; i < prg.size(); ++i) {
    REQUIRE(ic.mem[i] == expected[i]);
  }
}

TEST_CASE("Day2 example 5", "[2019 Day02]") {
  vector<int32_t> prg {1, 1, 1, 4, 99, 5, 6, 0, 99};
  vector<int32_t> expected {30, 1, 1, 4, 2, 5, 6, 0, 99};
  auto ic = IntCode<int32_t>(prg);
  while (ic.state != IntCodeState::halted) {
    ic.step();
  }
  for (int i = 0; i < prg.size(); ++i) {
    REQUIRE(ic.mem[i] == expected[i]);
  }
}
