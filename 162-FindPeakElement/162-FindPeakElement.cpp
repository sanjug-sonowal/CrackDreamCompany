// Last updated: 18/10/2025, 09:06:55
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
     int n = nums.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (nums[0] > nums[1]) return 0;
    if (nums[n - 1] > nums[n - 2]) return n - 1;
        
        int start = 0,end = nums.size()-1,mid;
        while(start  <= end)
        {
            mid = end + (start - end)/2;
            //peak element
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
            //right move
            else if(nums[mid] > nums[mid - 1])
            start = mid + 1;
            //left move
            else
            end = mid - 1;
        }
        return mid-1;
    }
};