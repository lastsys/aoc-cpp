#include "day03.h"

#include <limits>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>

auto manhattan_distance(const Point &p1, const Point &p2) -> int32_t {
  return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

auto distance_to_closest_intersection(const vector<Direction> &path1,
                                      const vector<Direction> &path2) -> int32_t {
  auto map1 = generate_map(path1);
  auto map2 = generate_map(path2);
  // find intersections
  auto intersections = find_intersections(map1, map2);
  int32_t smallest_distance = numeric_limits<int32_t>::max();
  // find smallest manhattan distance
  const Point p0(0, 0);
  for (auto const &p : intersections) {
    auto dist = manhattan_distance(p0, p);
    if (dist < smallest_distance) {
      smallest_distance = dist;
    }
  }
  return smallest_distance;
}

auto closest_intersection_by_steps(const vector<Direction> &path1,
    const vector<Direction> &path2) -> int32_t {
  auto map1 = generate_map(path1);
  auto map2 = generate_map(path2);
  auto intersections = find_intersections(map1, map2);
  int32_t smallest_distance = numeric_limits<int32_t>::max();
  for (auto const &p : intersections) {
    if (map1[p] < smallest_distance) {
      smallest_distance = map1[p];
    }
    if (map2[p] < smallest_distance) {
      smallest_distance = map2[p];
    }
  }
  return smallest_distance;
}

auto parse_path(const string &path) -> vector<Direction> {
  stringstream ss(path);
  vector<Direction> v;
  while (ss.good()) {
    string substr;
    getline(ss, substr, ',');
    auto dir = substr[0];
    auto len = stoi(substr.substr(1));
    Direction d;
    d.length = len;
    switch (dir) {
      case 'L':
        d.orientation = Orientation::left;
        break;
      case 'R':
        d.orientation = Orientation::right;
        break;
      case 'U':
        d.orientation = Orientation::up;
        break;
      case 'D':
        d.orientation = Orientation::down;
        break;
      default:
        exit(EXIT_FAILURE);
    }
    v.push_back(d);
  }
  return v;
}

auto find_intersections(const PathMap &map1, const PathMap &map2) -> set<Point> {
  set<Point> keys1;
  for (const auto &d : map1) {
    keys1.insert(d.first);
  }
  set<Point> keys2;
  for (const auto &d : map2) {
    keys2.insert(d.first);
  }
  set<Point> intersection;
  set_intersection(keys1.begin(), keys1.end(), keys2.begin(), keys2.end(),
      inserter(intersection, intersection.begin()));
  return intersection;
}

auto generate_map(const vector<Direction> &path) -> PathMap {
  PathMap m;
  Point pos(0, 0);
  int32_t total_steps = 0;

  for (const auto &d : path) {
    switch (d.orientation) {
      case Orientation::up: {
        const int32_t yp = pos.y;
        for (int32_t y = yp + 1; y <= yp + d.length; ++y) {
          pos.y = y;
          total_steps++;
          auto it = m.find(pos);
          if (it == m.end()) {
            m[Point(pos)] = total_steps;
          }
        }
      }
        break;
      case Orientation::down: {
        const int32_t yp = pos.y;
        for (int32_t y = yp - 1; y >= yp - d.length; --y) {
          pos.y = y;
          total_steps++;
          auto it = m.find(pos);
          if (it == m.end()) {
            m[Point(pos)] = total_steps;
          }
        }
      }
        break;
      case Orientation::right: {
        const int32_t xp = pos.x;
        for (int32_t x = xp + 1; x <= xp + d.length; ++x) {
          pos.x = x;
          total_steps++;
          auto it = m.find(pos);
          if (it == m.end()) {
            m[Point(pos)] = total_steps;
          }
        }
      }
        break;
      case Orientation::left: {
        const int32_t xp = pos.x;
        for (int32_t x = xp - 1; x >= xp - d.length; --x) {
          pos.x = x;
          total_steps++;
          auto it = m.find(pos);
          if (it == m.end()) {
            m[Point(pos)] = total_steps;
          }
        }
      }
      default:
        exit(EXIT_FAILURE);
    }
  }
  return m;
}

auto read_input() -> vector<string> {
  ifstream is;
  is.open("input.txt");
  if (!is) {
    cerr << strerror(errno) << endl;
    exit(EXIT_FAILURE);
  }
  vector<string> lines;
  string line;
  while (is >> line) {
    lines.push_back(line);
  }
  return lines;
}
