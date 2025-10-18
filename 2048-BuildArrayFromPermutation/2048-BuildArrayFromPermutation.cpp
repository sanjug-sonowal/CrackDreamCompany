// Last updated: 18/10/2025, 09:01:09
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size();i++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};