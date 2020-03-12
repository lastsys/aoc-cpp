#include "day04.h"

#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <sstream>
#include <iostream>

using namespace std;

auto count_passwords_1(int32_t start, int32_t end) -> int32_t {
  int32_t count = 0;
  for (int32_t pw = start; pw <= end; ++pw) {
    if (check_numbers_non_decreasing(pw) && check_repeating_numbers(pw)) {
      count++;
    }
  }
  return count;
}

auto count_passwords_2(int32_t start, int32_t end) -> int32_t {
  int32_t count = 0;
  for (int32_t pw = start; pw <= end; ++pw) {
    if (check_numbers_non_decreasing(pw) && check_exact_pair(pw)) {
      count++;
    }
  }
  return count;
}

auto check_numbers_non_decreasing(int32_t pw) -> bool {
  auto s = to_string(pw);
  vector<int32_t> unsorted_digits;
  for (auto c : s) {
    // Use ASCII-value offset for digit.
    unsorted_digits.push_back(c - 48);
  }
  vector<int32_t> sorted_digits(unsorted_digits);
  sort(sorted_digits.begin(), sorted_digits.end());

  return unsorted_digits == sorted_digits;
}

auto check_repeating_numbers(int32_t pw) -> bool {
  const regex pattern1("(\\d)\\1");
  auto s = to_string(pw);
  return regex_search(s, pattern1);
}

auto check_exact_pair(int32_t pw) -> bool {
  auto s = to_string(pw);
  // Start of string.
  if (s[0] == s[1] && s[2] != s[0]) {
    return true;
  }
  // End of string.
  if (*(s.end()-1) == *(s.end()-2) && *(s.end()-1) != *(s.end()-3)) {
    return true;
  }
  // All other positions.
  for (int i = 1; i < s.size()-1; ++i) {
    if (s[i] == s[i+1] && s[i-1] != s[i] && s[i+2] != s[i]) {
      return true;
    }
  }
  return false;
}
