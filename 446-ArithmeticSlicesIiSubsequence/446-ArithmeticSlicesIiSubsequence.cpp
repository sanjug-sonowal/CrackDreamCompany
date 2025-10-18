// Last updated: 18/10/2025, 09:05:40
class Solution {
public:

 int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        // dp[i][diff] represents the number of subsequences ending at index i with a common difference of 'diff'
        std::vector<std::unordered_map<int, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];
                if (diff >= INT_MIN && diff <= INT_MAX) {
                    int diffInt = static_cast<int>(diff);
                    dp[i][diffInt] += dp[j][diffInt] + 1; // Increment count by 1 and add previous count
                    result += dp[j][diffInt];
                }
            }
        }

        return result;
    }
};