#include <cstdint>
#include <iostream>
#include <VExercise2.h>

int main() {
  VExercise2 model;
  uint8_t critbits = 0;
  uint8_t success = 0;
  // Test each combination of the 4 bits participating in XOR operation
  while (critbits < 16) {
    uint16_t input = 0;
    // Set input according to current combination
    if (critbits & 1) input |= 2;
    if (critbits & 2) input |= 8;
    if (critbits & 4) input |= 256;
    if (critbits & 8) input |= 1024;
    // Test reset
    model.reset = 1;
    model.clk = 1;
    model.init = ~input;
    model.eval();
    model.clk = 0;
    model.eval();
    if (model.out != input) {
      std::cerr << "Reset failed. Output: " << model.out << "; expected " << input << std::endl;
    // Test shift if reset succeeded
    } else {
      model.reset = 0;
      model.clk = 1;
      model.eval();
      model.clk = 0;
      model.eval();
      uint16_t next_bit = ((input >> 1) & 1) ^ ((input >> 3) & 1) ^ ((input >> 8) & 1) ^ ((input >> 10) & 1);
      input = input << 1;
      input |= next_bit;
      if (model.out != input) {
        std::cerr << "Shift failed. Output: " << model.out << "; expected " << input << std::endl;
      } else {
        ++success;
      }
    }
    ++critbits;
  }
  // Report number of failed cases, if any.
  if (success != critbits) {
    std::cerr << static_cast<unsigned>(critbits - success) << " out of " << static_cast<unsigned>(critbits) << " test cases failed." << std::endl;
    return 1;
  }
  std::cout << "All " << static_cast<unsigned>(success) << " test cases passed." << std::endl;
}
