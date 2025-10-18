// Last updated: 18/10/2025, 09:02:06
class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int ans = numBottles;

    while (numBottles >= numExchange) {
      ans += numBottles / numExchange;
      numBottles = numBottles / numExchange + numBottles % numExchange;
    }

    return ans;
  }
};