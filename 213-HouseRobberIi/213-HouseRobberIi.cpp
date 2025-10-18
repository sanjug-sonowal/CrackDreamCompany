// Last updated: 18/10/2025, 09:06:39
class Solution {
public:
    int robbery(int i,int n,vector<int>&nums){
        int length = n - i + 1;
        if(length == 0)
        return 0;
        if(length == 1)
        return nums[i];

        int prev1 = max(nums[i],nums[i+1]) , prev2 = nums[i], curr = prev1;

        for(int j = 2; j < length; j++) {
            curr = max(nums[i + j] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int take_first_house = robbery(0, n - 2, nums);
        int take_last_house = robbery(1, n - 1, nums);

        return max(take_first_house, take_last_house);
    }
};