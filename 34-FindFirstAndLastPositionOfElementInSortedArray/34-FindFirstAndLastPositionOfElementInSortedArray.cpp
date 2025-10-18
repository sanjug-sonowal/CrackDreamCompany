// Last updated: 18/10/2025, 09:07:52
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0,end = nums.size() - 1,first = -1,last = -1,mid;

        //first
        while(start <= end){
            mid = start + (end - start) / 2;
            if(nums[mid] == target){
                first = mid;
                end = mid - 1;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        start = 0,end = nums.size() - 1;

        //last
          while(start <= end){
            mid = start + (end - start) / 2;
            if(nums[mid] == target){
                last = mid;
                start = mid + 1;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        return vector<int> {first,last};
    }
};