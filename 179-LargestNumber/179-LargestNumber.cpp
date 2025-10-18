// Last updated: 18/10/2025, 09:06:49
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    string ans;

    ranges::sort(nums, [](int a, int b) {
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });

    for (const int num : nums)
      ans += to_string(num);

    return ans[0] == '0' ? "0" : ans;
  }
};