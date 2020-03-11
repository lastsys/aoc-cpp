#include "day03.h"

#include <iostream>

using namespace std;

int main() {
  cout << "2019 :: Day 03" << endl;
  auto data = read_input();
  auto p1 = parse_path(data[0]);
  auto p2 = parse_path(data[1]);
  auto part1 = distance_to_closest_intersection(p1, p2);
  cout << "Part 1 = " << part1 << endl;

  auto part2 = closest_intersection_by_steps(p1, p2);
  cout << "Part 2 = " << part2 << endl;
}
