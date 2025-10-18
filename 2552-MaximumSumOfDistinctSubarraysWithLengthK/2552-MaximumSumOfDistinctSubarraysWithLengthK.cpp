// Last updated: 18/10/2025, 09:00:02
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long sum = 0, maxSum = 0;
        int start = 0;
        int n = nums.size();
        for(int end = 0; end < n; end++) {
            sum += nums[end];
            freq[nums[end]]++;

            // If we have duplicates, shrink the window from the left
            while(freq[nums[end]] > 1) {
                sum -= nums[start];
                freq[nums[start]]--;
                start++;
            }

            // Check if window size is exactly k
            if(end - start + 1 == k) {
                maxSum = max(maxSum, sum);

                // Move window forward by removing the leftmost element
                sum -= nums[start];
                freq[nums[start]]--;
                start++;
            }
        }

        return maxSum;

    }
};