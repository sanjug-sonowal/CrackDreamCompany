// Last updated: 18/10/2025, 09:06:18
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    const int xors = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
    const int lowbit = xors & -(unsigned int)xors; // Cast xors to unsigned before negation
    vector<int> ans(2);

    // Separate `nums` into two groups by `lowbit`.
    for (const int num : nums)
      if (num & lowbit)
        ans[0] ^= num;
      else
        ans[1] ^= num;

    return ans;
  }
};
