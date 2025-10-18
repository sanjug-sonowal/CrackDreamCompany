// Last updated: 18/10/2025, 08:59:47
class Solution {
 public:
  int passThePillow(int n, int time) {
    // Repeat every (n - 1) * 2 seconds.
    time %= (n - 1) * 2;
    if (time < n)  // Go forward from 1.
      return 1 + time;
    return n - (time - (n - 1));  // Go backward from n.
  }
};