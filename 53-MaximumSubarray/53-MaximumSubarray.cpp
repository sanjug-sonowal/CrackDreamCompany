// Last updated: 18/10/2025, 09:07:37
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int counting = nums[0]; 
        
        for (int i = 1; i < nums.size(); i++) {
            counting = max(nums[i], counting + nums[i]); 
            maxSum = max(maxSum, counting); 
        }
        return maxSum;
    }
};