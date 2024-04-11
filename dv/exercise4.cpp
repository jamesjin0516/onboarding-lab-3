#include <iostream>
#include <VExercise4.h>

int main() {
  VExercise4 model;
  unsigned fails = 0;
  unsigned cases = 0;
  model.cs = 0;
  // Ensure any sel value and cs = 0 produce out = 0
  for (model.sel = 0; model.sel < 4; ++model.sel) {
    model.eval();
    if (model.out != 0) {
      std::cerr << "Zero cs produce nonzero output: " << model.out << std::endl;
      ++fails;
    }
    ++cases;
  }
  model.cs = 1;
  model.alpha = 0;
  model.beta = 0;
  model.gamma = 0;
  // Test all input combinations between alpha, beta, and gamma
  do {
    do {
      do {
        // Test all sel values given current combinations of inputs
        for (model.sel = 0; model.sel < 4; ++model.sel) {
          model.eval();
          uint8_t expected;
          if (model.sel == 0) expected = model.alpha;
          else if (model.sel == 1) expected = model.beta;
          else if (model.sel == 2) expected = model.gamma;
          else if (model.sel == 3) expected = model.alpha & (model.beta | model.gamma);
          if (model.out != expected) {
            std::cerr << "sel = " << model.sel << " failed, output: " << model.out << "; expected: " << expected << std::endl;
            ++fails;
          }
          ++cases;
        }
      } while (++model.gamma);
    } while (++model.beta);
  } while (++model.alpha);
  if (fails > 0) {
    std::cerr << fails << " out of " << cases << " tests failed" << std::endl;
    return 1;
  }
  std::cout << "All " << cases << " tests passed" << std::endl;
}
