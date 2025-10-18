// Last updated: 18/10/2025, 09:05:34
class Solution {
 public:
  int findComplement(long num) {
    for (long i = 1; i <= num; i <<= 1)
      num ^= i;
    return num;
  }
};