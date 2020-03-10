#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "intcode.h"
#include "day02.h"

TEST_CASE("Program examples must match specification", "[2019 Day02]") {
  vector<int32_t> prg {1,9,10,3,2,3,11,0,99,30,40,50};
  auto ic = IntCode<int32_t>(prg);
  ic.step();
  REQUIRE(ic.mem[3] == 70);
  ic.step();
  REQUIRE(ic.mem[0] == 3500);
  ic.step();
  REQUIRE(ic.state == IntCodeState::halted);
}
