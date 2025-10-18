// Last updated: 18/10/2025, 09:04:03
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, pos = n - 1;
        vector<int> res(n);

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[pos--] = nums[left] * nums[left];
                left++;
            } else {
                res[pos--] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};