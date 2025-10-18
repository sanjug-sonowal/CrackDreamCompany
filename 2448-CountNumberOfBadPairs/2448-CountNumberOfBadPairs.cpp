// Last updated: 18/10/2025, 09:00:22
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
         long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;
        long long goodPairs = 0;
        
        std::unordered_map<int, long long> freq;
        
        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            goodPairs += freq[key];  // Count good pairs
            freq[key]++;             // Increment frequency
        }
        
        return totalPairs - goodPairs;
    }
};