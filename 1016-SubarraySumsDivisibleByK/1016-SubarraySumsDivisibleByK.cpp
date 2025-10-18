// Last updated: 18/10/2025, 09:04:07
class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int ans = 0;
    int prefix = 0;
    vector<int> count(k);
    count[0] = 1;

    for (const int num : nums) {
      prefix = (prefix + num % k + k) % k;
      ans += count[prefix];
      ++count[prefix];
    }

    return ans;
  }
};