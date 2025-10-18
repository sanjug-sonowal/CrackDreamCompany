// Last updated: 18/10/2025, 09:07:21
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, right = nums.size() - 1;

        while (start <= right) {
            int mid = start + (right - start) / 2;

            if (nums[mid] == target) return true;

            // Handle duplicates
            if (nums[start] == nums[mid] && nums[mid] == nums[right]) {
                start++;
                right--;
            }
            // Left half is sorted
            else if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    start = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
