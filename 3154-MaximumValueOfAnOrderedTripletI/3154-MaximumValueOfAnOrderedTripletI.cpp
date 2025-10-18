// Last updated: 18/10/2025, 08:59:17
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxSum = 0;
        int n = nums.size();
        for(int i = 0; i< n;i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k< n; k++){
                   long long value = (long long)(nums[i] - nums[j]) * nums[k];
                   maxSum = max(maxSum,value);
                }
            }
        }

        return maxSum;
    }
};