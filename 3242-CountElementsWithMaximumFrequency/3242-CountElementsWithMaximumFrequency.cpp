// Last updated: 18/10/2025, 08:59:11
class Solution {
 public:
  int maxFrequencyElements(vector<int>& nums) {
    constexpr int kMax = 100;
    vector<int> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    const int maxFreq = ranges::max(count);
    return ranges::count(count, maxFreq) * maxFreq;
  }
};