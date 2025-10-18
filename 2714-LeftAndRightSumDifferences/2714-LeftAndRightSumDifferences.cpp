// Last updated: 18/10/2025, 08:59:37
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int num : nums) totalSum += num;

        int preffixSum = 0;
        for(int i = 0;i<n;i++){
            int original = nums[i];
            int suffixSum = totalSum - preffixSum - original;
            nums[i] = abs(preffixSum - suffixSum);
            preffixSum += original;
        }
        return nums;
    }
};