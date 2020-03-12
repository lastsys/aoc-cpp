#ifndef ADVENT_OF_CODE_2019_DAY03_DAY03_H_
#define ADVENT_OF_CODE_2019_DAY03_DAY03_H_

#include <cstdint>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

enum class Orientation {
  up = 0,
  right = 1,
  left = 2,
  down = 3
};

struct Direction {
  Orientation orientation;
  int32_t length;

  Direction() : orientation(Orientation::up), length(0) {};

  Direction(const Orientation orientation, const int32_t length)
  : orientation(orientation)
  , length(length) {}
};

struct Point;

auto manhattan_distance(const Point &p1, const Point &p2) -> int32_t;

struct Point {
  int32_t x, y;

  Point(const int32_t x, const int32_t y) : x(x), y(y) {}
  Point(const Point &p) = default;

  bool operator<(Point const& other) const {
    return tie(x, y) < tie(other.x, other.y);
  }

  bool operator==(Point const& other) const {
    return tie(x, y) == tie(other.x, other.y);
  }
};

using PathMap = map<Point, int32_t>;

auto distance_to_closest_intersection(const vector<Direction> &path1,
    const vector<Direction> &path2) -> int32_t;

auto closest_intersection_by_steps(const vector<Direction> &path1,
    const vector<Direction> &path2) -> int32_t;

auto parse_path(const string &path) -> vector<Direction>;

auto find_intersections(const PathMap &map1, const PathMap &map2) -> set<Point>;

auto generate_map(const vector<Direction> &path) -> PathMap;

auto read_input() -> vector<string>;

#endif //ADVENT_OF_CODE_2019_DAY03_DAY03_H_
