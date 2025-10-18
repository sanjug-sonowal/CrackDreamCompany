// Last updated: 18/10/2025, 09:00:05
class Solution {
 public:
  int findMaxK(vector<int>& nums) {
    int ans = -1;
    unordered_set<int> seen;

    for (const int num : nums)
      if (seen.count(-num))
        ans = max(ans, abs(num));
      else
        seen.insert(num);

    return ans;
  }
};