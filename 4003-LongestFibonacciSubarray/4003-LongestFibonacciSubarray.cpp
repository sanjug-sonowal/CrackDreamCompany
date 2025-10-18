// Last updated: 18/10/2025, 08:58:53
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int maxLen = 2;
        for (int i = 0; i < n - 2; i++) {
            int len = 2;

            while (i + len < n && 
                   nums[i + len] == nums[i + len - 1] + nums[i + len - 2]) {
                len++;
            }
            
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
    }
};