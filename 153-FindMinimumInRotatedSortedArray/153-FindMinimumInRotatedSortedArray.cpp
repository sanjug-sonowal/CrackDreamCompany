// Last updated: 18/10/2025, 09:06:56
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = nums[0];
        int mid;

        while(start <= end){
            mid = start + (end - start) / 2;
            if(nums[mid] >= nums[0]){
                start = mid + 1;
            }else{
                ans = nums[mid];
                end = mid - 1;
            }
        }

        return ans;
    }
};