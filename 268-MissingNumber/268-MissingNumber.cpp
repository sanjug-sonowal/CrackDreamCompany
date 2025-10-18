// Last updated: 18/10/2025, 09:06:15
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int ans = nums.size();

    for (int i = 0; i < nums.size(); ++i)
      ans ^= i ^ nums[i];

    return ans;
  }
};