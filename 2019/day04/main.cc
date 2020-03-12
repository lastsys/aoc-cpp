#include <cstdlib>

#include <iostream>

#include "day04.h"

using namespace std;

int main() {
  const int32_t start = 256310;
  const int32_t end = 732736;

  cout << "Part 1 = " << count_passwords_1(start, end) << endl;
  cout << "Part 2 = " << count_passwords_2(start, end) << endl;

  return EXIT_SUCCESS;
}