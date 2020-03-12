#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "intcode.h"
#include "day05.h"

TEST_CASE("Day5 example 1", "[2019 Day05]") {
  vector<int32_t> prg {3,0,4,0,99};
  for (int32_t i = -100; i <= 100; ++i) {
    auto ic = IntCode<int32_t>(prg);
    ic.add_input(i);
    ic.run_to_halt();
    REQUIRE(ic.has_output());
    REQUIRE(ic.get_output() == i);
  }
}

TEST_CASE("Day5 example 2", "[2019 Day05]") {
  vector<int32_t> prg {1002,4,3,4,33};
  auto ic = IntCode<int32_t>(prg);
  ic.run_to_halt();
  REQUIRE(ic.read_mem(4) == 99);
}

TEST_CASE("Day5 example 3", "[2019 Day05]") {
  vector<int32_t> prg {3,9,8,9,10,9,4,9,99,-1,8};
  for (int32_t i = 0; i <= 10; ++i) {
    auto ic = IntCode<int32_t>(prg);
    ic.add_input(i);
    ic.run_to_halt();
    REQUIRE(ic.has_output());
    if (i == 8) {
      REQUIRE(ic.get_output() == 1);
    } else {
      REQUIRE(ic.get_output() == 0);
    }
  }
}

TEST_CASE("Day5 example 4", "[2019 Day05]") {
  vector<int32_t> prg {3,9,7,9,10,9,4,9,99,-1,8};
  for (int32_t i = 0; i <= 10; ++i) {
    auto ic = IntCode<int32_t>(prg);
    ic.add_input(i);
    ic.run_to_halt();
    REQUIRE(ic.has_output());
    if (i < 8) {
      REQUIRE(ic.get_output() == 1);
    } else {
      REQUIRE(ic.get_output() == 0);
    }
  }
}

TEST_CASE("Day5 example 5", "[2019 Day05]") {
  vector<int32_t> prg {3,3,1108,-1,8,3,4,3,99};
  for (int32_t i = 0; i <= 10; ++i) {
    auto ic = IntCode<int32_t>(prg);
    ic.add_input(i);
    ic.run_to_halt();
    REQUIRE(ic.has_output());
    if (i == 8) {
      REQUIRE(ic.get_output() == 1);
    } else {
      REQUIRE(ic.get_output() == 0);
    }
  }
}

TEST_CASE("Day5 example 6", "[2019 Day05]") {
  vector<int32_t> prg {3,3,1107,-1,8,3,4,3,99};
  for (int32_t i = 0; i <= 10; ++i) {
    auto ic = IntCode<int32_t>(prg);
    ic.add_input(i);
    ic.run_to_halt();
    REQUIRE(ic.has_output());
    if (i < 8) {
      REQUIRE(ic.get_output() == 1);
    } else {
      REQUIRE(ic.get_output() == 0);
    }
  }
}

TEST_CASE("Day5 example 7", "[2019 Day05]") {
  vector<int32_t> prg {3,12,6,12,15,1,13,14,13,4,13,99,-1,0,1,9};
  for (int32_t i = -10; i <= 10; ++i) {
    auto ic = IntCode<int32_t>(prg);
    ic.add_input(i);
    ic.run_to_halt();
    REQUIRE(ic.has_output());
    if (i != 0) {
      REQUIRE(ic.get_output() == 1);
    } else {
      REQUIRE(ic.get_output() == 0);
    }
  }
}

TEST_CASE("Day5 example 8", "[2019 Day05]") {
  vector<int32_t> prg {3,3,1105,-1,9,1101,0,0,12,4,12,99,1};
  for (int32_t i = -10; i <= 10; ++i) {
    auto ic = IntCode<int32_t>(prg);
    ic.add_input(i);
    ic.run_to_halt();
    REQUIRE(ic.has_output());
    if (i != 0) {
      REQUIRE(ic.get_output() == 1);
    } else {
      REQUIRE(ic.get_output() == 0);
    }
  }
}

TEST_CASE("Day5 example 9", "[2019 Day05]") {
  vector<int32_t> prg {3,21,1008,21,8,20,1005,20,22,107,8,21,20,1006,20,31,
                       1106,0,36,98,0,0,1002,21,125,20,4,20,1105,1,46,104,
                       999,1105,1,46,1101,1000,1,20,4,20,1105,1,46,98,99};
  for (int32_t i = -10; i <= 10; ++i) {
    auto ic = IntCode<int32_t>(prg);
    ic.add_input(i);
    ic.run_to_halt();
    REQUIRE(ic.has_output());
    if (i < 8) {
      REQUIRE(ic.get_output() == 999);
    } else if (i > 8) {
      REQUIRE(ic.get_output() == 1001);
    } else {
      REQUIRE(ic.get_output() == 1000);
    }
  }
}
