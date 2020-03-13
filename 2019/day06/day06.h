#ifndef ADVENT_OF_CODE_2019_DAY06_DAY06_H_
#define ADVENT_OF_CODE_2019_DAY06_DAY06_H_

#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

using Orbits = map<string, set<string>>;
using Graph = map<string, set<string>>;

auto parse_orbits(const vector<string> &data) -> Orbits;
auto count_orbits(const Orbits &orbits) -> int;
auto shortest_path(const Orbits &orbits, const string &start, const string &end) -> int;
auto convert_orbits_to_graph(const Orbits &orbits) -> Graph;

#endif //ADVENT_OF_CODE_2019_DAY06_DAY06_H_
