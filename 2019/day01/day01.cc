#include <cstdint>
#include <fstream>
#include <iostream>
#include <cstring>

#include "day01.h"

auto fuel_required(const int32_t mass) -> int32_t {
  // Integer division works well here.
  return mass / 3 - 2;
}

auto read_input() -> vector<int> {
  ifstream is;
  is.open("day01.txt");
  if (!is) {
    cerr << strerror(errno) << endl;
    exit(EXIT_FAILURE);
  }
  vector<int> numbers;
  int number;

  while (is >> number) {
    numbers.push_back(number);
  }
  return numbers;
}

auto sum(const vector<int> &numbers) -> int {
  int s = 0;
  for (auto n : numbers) {
    s += n;
  }
  return s;
}

auto compensated_fuel_required(const int32_t mass) -> int32_t {
  int32_t added_mass = fuel_required(mass);
  int32_t total_mass = 0;
  do {
    total_mass += added_mass;
    added_mass = fuel_required(added_mass);
  } while (added_mass > 0);
  return total_mass;
}
