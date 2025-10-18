// Last updated: 18/10/2025, 09:06:10
class Solution {
public:

// solved using dynamic programming
   int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    vector<int> dp(n, 1); // dp[i] represents the length of LIS ending at index i

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
};