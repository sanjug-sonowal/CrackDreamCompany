// Last updated: 18/10/2025, 09:01:06
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i< n;i++){
            nums.push_back(nums[i]);
        }

        return nums;
    }
};