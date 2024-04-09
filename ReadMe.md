# Week 3 Lab: Verification

## Exercise 2 Testing Strategy
Since this test is to verify correct behaviour after module modification, I decided to test the reset mechanism and the least significant bit generation. I iterated through all 16 combinations of the four bits producing the least siginificant bit and checked for correct output after one clock cycle. Since bit shift is relible, this strategy ensures that the module behaves correctly for all possible inputs.