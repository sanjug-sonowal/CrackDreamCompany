// Last updated: 18/10/2025, 09:05:58
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> countMap;

    // Count occurrences of each element in nums1
    for (const int num : nums1)
      ++countMap[num];

    // Find common elements in nums2
    for (const int num : nums2) {
      if (countMap[num] > 0) {
        ans.push_back(num);
        --countMap[num];
      }
    }

    return ans;
  }
};