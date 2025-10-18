// Last updated: 18/10/2025, 09:01:19
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
      int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                maxSum = max(maxSum, currentSum);
                currentSum = nums[i];
            }
        }
        maxSum = max(maxSum, currentSum);
        
        return maxSum;
    }
};