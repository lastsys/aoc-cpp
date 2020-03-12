#include <iostream>

#include "day05.h"
#include "intcode.h"

using namespace std;

int main() {
  cout << "2019 :: Day 05" << endl;
  auto data = read_input();
  {
    auto ic = IntCode<int32_t>(data);
    ic.add_input(1);
    ic.run_to_halt();
    while (ic.has_output()) {
      auto value = ic.get_output();
      if (value != 0) {
        cout << "Part 1 = " << value << endl;
      }
    }
  }

  {
    auto ic = IntCode<int32_t>(data);
    ic.add_input(5);
    ic.run_to_halt();
    while (ic.has_output()) {
      auto value = ic.get_output();
      if (value != 0) {
        cout << "Part 2 = " << value << endl;
      }
    }
  }
}
