// Last updated: 18/10/2025, 09:05:11
class Solution {
 public:
  bool judgeSquareSum(int c) {
    unsigned l = 0;
    unsigned r = sqrt(c);

    while (l <= r) {
      const unsigned sum = l * l + r * r;
      if (sum == c)
        return true;
      if (sum < c)
        ++l;
      else
        --r;
    }

    return false;
  }
};