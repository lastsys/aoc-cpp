#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>

#include "day02.h"

using namespace std;

auto read_input() -> vector<int32_t> {
  ifstream is;
  is.open("input.txt");
  if (!is) {
    cerr << strerror(errno) << endl;
    exit(EXIT_FAILURE);
  }
  vector<int32_t> numbers;
  string token;
  while (getline(is, token, ',')) {
    numbers.push_back(stoi(token));
  }
  return numbers;
}
