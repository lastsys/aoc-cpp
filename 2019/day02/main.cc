#include <iostream>

#include "day02.h"
#include "intcode.h"

using namespace std;

int main(int argc, char *argv[]) {
  cout << "2019 :: Day 02" << endl;
  auto data = read_input();

  {
    auto ic = IntCode<int32_t>(data);
    ic.write_mem(1, 12);
    ic.write_mem(2, 2);
    ic.run_to_halt();
    cout << "Part 1 = " << ic.read_mem(0) << endl;
  }

  {
    int32_t response = 0;
    for (int32_t noun = 0; noun < 100; ++noun) {
      for (int32_t verb = 0; verb < 100; ++verb) {
        auto ic = IntCode<int32_t>(data);
        ic.write_mem(1, noun);
        ic.write_mem(2, verb);
        ic.run_to_halt();
        if (ic.read_mem(0) == 19690720) {
          response = 100 * noun + verb;
          goto done;
        }
      }
    }
  done:
    cout << "Part 2 = " << response << endl;
  }

  return EXIT_SUCCESS;
}
