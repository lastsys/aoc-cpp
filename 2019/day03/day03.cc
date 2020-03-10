#include "day03.h"

auto distance_to_closest_intersection(const vector<Direction> &path1,
                                      const vector<Direction> &path2) -> int32_t {
  auto map1 = generate_map(path1);
  auto map2 = generate_map(path2);
  // find intersections
  find_intersections(map1, map2);
  // find smallest manhattan distance
}
