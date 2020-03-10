#ifndef ADVENT_OF_CODE_2019_INTCODE_INTCODE_H_
#define ADVENT_OF_CODE_2019_INTCODE_INTCODE_H_

#include <map>
#include <queue>

using namespace std;

enum class IntCodeState { running, waiting, halted };

enum class IntCodeOpCode {
  add = 1,
  multiply = 2,
  input = 3,
  output = 4,
  jump_if_true = 5,
  jump_if_false = 6,
  less_than = 7,
  equals = 8,
  adjust_rel_base = 9,
  halt = 99
};

template<typename T>
struct IntCode {
  map<T, T> mem;
  T pc = 0;
  T rel_base = 0;
  queue<T> input;
  queue<T> output;
  IntCodeState state = IntCodeState::running;

  vector<void (IntCode::*)(const T, const T, const T)> op_codes;

  explicit IntCode(const vector<T> init_mem) {
    T addr = 0;
    for (auto &v : init_mem) {
      write_mem(addr++, v);
    }

    op_codes.push_back(this->oc_add);
    op_codes.push_back(this->oc_multiply);
    op_codes.push_back(this->oc_input);
    op_codes.push_back(this->oc_output);
    op_codes.push_back(this->oc_jump_if_true);
    op_codes.push_back(this->oc_jump_if_false);
    op_codes.push_back(this->oc_less_than);
    op_codes.push_back(this->oc_equals);
    op_codes.push_back(this->oc_adjust_rel_base);
  }

  auto has_output() const noexcept -> bool {
    return !output.empty();
  }

  auto has_input() const noexcept -> bool {
    return !input.empty();
  }

  auto add_input(const T value) noexcept -> void {
    input.push(value);
  }

  auto step() noexcept -> void {
    const auto instruction = read_mem(pc++);
    // TODO: Can this be done in a nicer way?
    const auto m3 = instruction / 10'000;
    const auto m2 = (instruction - m3 * 10'000) / 1'000;
    const auto m1 = (instruction - m3 * 10'000 - m2 * 1'000) / 100;
    const auto op_code = (instruction - m3 * 10'000 - m2 * 1'000 - m1 * 100);

    if (op_code == static_cast<T>(IntCodeOpCode::halt) || state == IntCodeState::halted) {
      state = IntCodeState::halted;
      return;
    }

    if (op_code >= static_cast<T>(IntCodeOpCode::add) &&
        op_code <= static_cast<T>(IntCodeOpCode::adjust_rel_base)) {
      (this->*(op_codes[op_code - 1]))(m1, m2, m3);
    } else {
      exit(EXIT_FAILURE);
    }
  }

  auto read(const T mode, const T value) const noexcept -> T {
    switch (mode) {
      case 0:
        // Position mode.
        return read_mem(value);
      case 1:
        // Immediate mode.
        return value;
      case 2:
        // Relative mode.
        return read_mem(rel_base + value);
      default:exit(EXIT_FAILURE);
    }
  }

  auto read_literal(const T mode, const T value) const noexcept -> T {
    switch (mode) {
      case 0:
      case 1:
        return value;
      case 2:
        return rel_base + value;
      default:exit(EXIT_FAILURE);
    }
  }

 private:
  auto read_mem(const T address) const noexcept -> T {
    const auto it = mem.find(address);
    if (mem.find(address) != mem.end()) {
      return it->second;
    }
    // Default to zero if there is nothing declared already.
    return 0;
  }

  auto write_mem(const T address, const T value) noexcept -> void {
    mem[address] = value;
  }

 private:
  auto oc_add(const T m1, const T m2, const T m3) noexcept -> void {
    const auto arg1 = read(m1, read_mem(pc++));
    const auto arg2 = read(m2, read_mem(pc++));
    const auto arg3 = read_literal(m3, read_mem(pc++));
    write_mem(arg3, arg1 + arg2);
  }

  auto oc_multiply(const T m1, const T m2, const T m3) noexcept -> void {
    const auto arg1 = read(m1, read_mem(pc++));
    const auto arg2 = read(m2, read_mem(pc++));
    const auto arg3 = read(m3, read_literal(m3, read_mem(pc++)));
    write_mem(arg3, arg1 * arg2);
  }

  auto oc_input(const T m1, const T m2, const T m3) noexcept -> void {
    const auto arg1 = read_literal(m1, read_mem(pc++));
    if (has_input()) {
      const auto in = input.front();
      input.pop();
      write_mem(arg1, in);
    } else {
      state = IntCodeState::waiting;
      // Rewind program counter.
      pc -= 2;
    }
  }

  auto oc_output(const T m1, const T m2, const T m3) noexcept -> void {
    const auto arg1 = read(m1, read_mem(pc++));
    output.push(arg1);
  };

  auto oc_jump_if_true(const T m1, const T m2, const T m3) noexcept -> void {
    const auto arg1 = read(m1, read_mem(pc++));
    const auto arg2 = read(m2, read_mem(pc++));
    if (arg1 != 0) {
      pc = arg2;
    }
  }

  auto oc_jump_if_false(const T m1, const T m2, const T m3) noexcept -> void {
    const auto arg1 = read(m1, read_mem(pc++));
    const auto arg2 = read(m2, read_mem(pc++));
    if (arg1 == 0) {
      pc = arg2;
    }
  }

  auto oc_less_than(const T m1, const T m2, const T m3) noexcept -> void {
    const auto arg1 = read(m1, read_mem(pc++));
    const auto arg2 = read(m2, read_mem(pc++));
    const auto arg3 = read_literal(m3, read_mem(pc++));
    write_mem(arg3, arg1 < arg2 ? 1 : 0);
  }

  auto oc_equals(const T m1, const T m2, const T m3) noexcept -> void {
    const auto arg1 = read(m1, read_mem(pc++));
    const auto arg2 = read(m2, read_mem(pc++));
    const auto arg3 = read_literal(m3, read_mem(pc++));
    write_mem(arg3, arg1 == arg2 ? 1 : 0);
  }

  auto oc_adjust_rel_base(const T m1, const T m2, const T m3) noexcept -> void {
    const auto arg1 = read(m1, read_mem(pc++));
    rel_base += arg1;
  }
};

#endif //ADVENT_OF_CODE_2019_INTCODE_INTCODE_H_
