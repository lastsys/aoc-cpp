#ifndef ADVENT_OF_CODE_2019_DAY03_DAY03_H_
#define ADVENT_OF_CODE_2019_DAY03_DAY03_H_

#include <cstdint>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

enum class Direction {
  up, right, left, down
};

struct Point {
  int32_t x;
  int32_t y;
};

using PathMap = map<Point, int32_t>;

auto distance_to_closest_intersection(const vector<Direction> &path1,
    const vector<Direction> &path2) -> int32_t;

auto closest_intersection_by_steps(const vector<Direction> &path1,
    const vector<Direction> &path2) -> int32_t;

auto parse_path(string path) -> vector<Direction>;

auto find_intersections(PathMap &map1, PathMap &map2) -> set<Point>;

auto generate_map(const vector<Direction> &path) -> PathMap;

#endif //ADVENT_OF_CODE_2019_DAY03_DAY03_H_
