// Last updated: 18/10/2025, 09:04:04
class Solution {
public:
    void selectionSort(vector<int> &arr){
        int n = arr.size();
        for(int i = 0; i< n - 1;i++){
            int idx = i;
            for(int j = i + 1;j<n;j++){
                if(arr[j] < arr[idx]){
                    idx = j;
                }
            }
            swap(arr[i],arr[idx]);
        }
    }
    int largestPerimeter(vector<int>& nums) {
         int n = nums.size();
        selectionSort(nums);

        for(int i = n - 1; i >= 2; i--){  
            if(nums[i - 2] + nums[i - 1] > nums[i]){
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
};