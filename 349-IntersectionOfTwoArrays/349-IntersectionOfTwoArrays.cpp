// Last updated: 18/10/2025, 09:06:00
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_set<int> set{nums1.begin(), nums1.end()};

    for (const int num : nums2)
      if (set.erase(num))
        ans.push_back(num);

    return ans;
  }
};