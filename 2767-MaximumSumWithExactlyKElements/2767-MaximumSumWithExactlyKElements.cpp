// Last updated: 18/10/2025, 08:59:31
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
            for(int i = 0;i<nums.size();i++){
                if(nums[i] > maxSum){
                    maxSum = nums[i];
                }
            }
        return k * maxSum + (k - 1) * k / 2;
    }
};