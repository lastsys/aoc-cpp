#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "day01.h"

using namespace std;

int main(int argc, char *argv[]) {
  cout << "2019 :: Day 01" << endl;
  auto data = read_input();

  vector<int> part1_required_fuel;
  // This is the C++ way of "map".
  transform(data.begin(), data.end(),
      back_inserter(part1_required_fuel), fuel_required);
  cout << "Part 1 = " << sum(part1_required_fuel) << endl;

  vector<int> part2_required_fuel;
  transform(data.begin(), data.end(),
      back_inserter(part2_required_fuel), compensated_fuel_required);
  cout << "Part 2 = " << sum(part2_required_fuel) << endl;

  return EXIT_SUCCESS;
}

