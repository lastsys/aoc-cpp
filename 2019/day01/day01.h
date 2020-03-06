#ifndef ADVENT_OF_CODE_2019_DAY01_DAY01_H_
#define ADVENT_OF_CODE_2019_DAY01_DAY01_H_

#include <vector>

using namespace std;

auto  fuel_required(int32_t mass) -> int32_t;
auto read_input() -> vector<int>;
auto sum(const vector<int> &numbers) -> int;
auto compensated_fuel_required(const int32_t mass) -> int32_t;

#endif //ADVENT_OF_CODE_2019_DAY01_DAY01_H_
