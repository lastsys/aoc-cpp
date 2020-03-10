#include <iostream>

#include "day02.h"
#include "intcode.h"

using namespace std;

int main(int argc, char *argv[]) {
  cout << "2019 :: Day 02" << endl;
  auto data = read_input();

  auto ic = IntCode<int32_t>(data);


  return EXIT_SUCCESS;
}
