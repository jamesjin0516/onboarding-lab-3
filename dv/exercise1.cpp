#include <cstdint>
#include <iostream>
#include <VExercise1.h>


uint8_t operation(uint8_t code, uint8_t a, uint8_t b) {
  if (code == 0) return a ^ b;
  if (code == 1) return b < 8 ? a << b : 0;
  if (code == 2) return a % b;
  if (code == 3) return ~(a & b);
  std::cerr << "Unknown opcode: " << code << std::endl;
  exit(1);
}


int main() {
  VExercise1 model;
  unsigned fails = 0;
  unsigned total = 0;
  for (uint8_t code = 0; code < 4; ++code) {
    model.op = code;
    model.a = 0;
    model.b = 0;
    do {
      if (code == 2 && model.b == 0) continue;
      do {
        model.eval();
        uint8_t ans = operation(code, model.a, model.b);
        if (model.out != ans) {
          std::cerr << "Test failed; op = " << static_cast<unsigned>(code) << ", a = " << static_cast<unsigned>(model.a) << ", b = "
          << static_cast<unsigned>(model.b) << "; output: " << static_cast<unsigned>(model.out) << " (expected: "
          << static_cast<unsigned>(ans) << ")." << std::endl;
          ++fails;
        }
        ++total;
      } while (++model.a);
    } while (++model.b);
  }
  if (fails) {
    std::cerr << "Unsuccessful, failed " << fails << " cases (out of " << total << ")." << std::endl;
    return 1;
  }
  std::cout << "Successful, all " << total << " cases passed." << std::endl;
  return 0;
}
