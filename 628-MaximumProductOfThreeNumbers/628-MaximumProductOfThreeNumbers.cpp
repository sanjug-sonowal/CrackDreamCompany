// Last updated: 18/10/2025, 09:05:14
class Solution {
public:
    void insertionSort(vector<int> &arr){
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int key = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                j--; 
            }
            arr[j+1] = key;
        }
        
    }
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        insertionSort(nums);

        int option1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int option2 = nums[0] * nums[1] * nums[n - 1];

        return max(option1,option2);
    }
};