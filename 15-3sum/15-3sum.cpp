// Last updated: 18/10/2025, 09:08:05
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> ans;

    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;  // Skip duplicate elements

        int start = i + 1;
        int end = n - 1;

        while (start < end) {
            int sum = nums[i] + nums[start] + nums[end];

            if (sum == 0) {
                ans.push_back({nums[i], nums[start], nums[end]});

                // Skip duplicate elements
                while (start < end && nums[start] == nums[start + 1])
                    start++;
                while (start < end && nums[end] == nums[end - 1])
                    end--;

                start++;
                end--;
            } else if (sum < 0) {
                start++;
            } else {
                end--;
            }
        }
    }

    return ans;
    }
};