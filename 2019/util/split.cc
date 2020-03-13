#include "util.h"

#include <string>
#include <vector>
#include <sstream>

using namespace std;

auto split(const string &s, const char separator) -> vector<string> {
  vector<string> out;
  stringstream ss;
  ss << s;
  string part;
  while (getline(ss, part, separator)) {
    out.push_back(part);
  }
  return out;
}
