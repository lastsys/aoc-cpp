#include "day06.h"

#include <vector>
#include <string>

#include "util.h"

using namespace std;

auto parse_orbits(const vector<string> &data) -> Orbits {
  Orbits orbits;
  for (const auto &d : data) {
    auto s = split(d, ')');
    auto parent = s[0];
    auto child = s[1];
    {
      auto it = orbits.find(parent);
      if (it == orbits.end()) {
        set<string> value{child};
        orbits[parent] = value;
      } else {
        orbits[parent].insert(child);
      }
    }
    {
      auto it = orbits.find(child);
      if (it != orbits.end()) {
        set<string> value;
        orbits[child] = value;
      }
    }
  }
  return orbits;
}

auto count_tree(const Orbits &orbits, const string &orbit, int depth = 1) -> int {
  auto children = orbits.at(orbit);
  auto child_depth_sum = static_cast<int>(children.size() * depth);
  auto subtree_depth_sum = 0;
  for (const auto &child : children) {
    auto it = orbits.find(child);
    if (it != orbits.end()) {
      subtree_depth_sum += count_tree(orbits, child, depth + 1);
    }
  }
  auto total = child_depth_sum + subtree_depth_sum;
  return total;
}

auto count_orbits(const Orbits &orbits) -> int {
  return count_tree(orbits, "COM");
}
