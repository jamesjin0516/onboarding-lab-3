# Week 3 Lab: Verification

## Exercise 2 Testing Strategy
Since this test is to verify correct behaviour after module modification, I decided to test the reset mechanism and the least significant bit generation. I iterated through all 16 combinations of the four bits producing the least siginificant bit and checked for correct output after one clock cycle. Since bit shift is relible, this strategy ensures that the module behaves correctly for all possible inputs.

## Exercise 4 Testing Igored Value
Since all possible sel values should produce 0 when cs is 0, I can simply verify this by looping through all sel values (0 to 3) and check that out is 0 given cs is fixed to 0.