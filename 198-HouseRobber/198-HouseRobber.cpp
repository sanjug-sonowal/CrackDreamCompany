// Last updated: 18/10/2025, 09:06:47
class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int curr;
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 2;i<=n;i++){
            curr = max(nums[i - 1] + prev2,prev);
            prev2 = prev;
            prev = curr;
        }

        return curr;
    }
};