#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "util.h"

TEST_CASE("split", "[util]") {
  const string s("1,2,3434,52323,332,33");
  auto result = split(s, ',');
  const vector<string> expect {"1", "2", "3434", "52323", "332", "33"};
  REQUIRE(result == expect);
}
