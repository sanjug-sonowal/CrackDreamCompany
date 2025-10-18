// Last updated: 18/10/2025, 09:00:31
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        long long prefixSum = 0;
        int validSplits = 0;
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            prefixSum += nums[i]; // Calculate prefix sum
            if (prefixSum >= totalSum - prefixSum) {
                validSplits++; // Check the condition and count valid splits
            }
        }
        
        return validSplits;
    }
};
