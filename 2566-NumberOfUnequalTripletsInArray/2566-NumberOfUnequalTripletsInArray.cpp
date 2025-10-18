// Last updated: 18/10/2025, 08:59:59
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(int x:nums){
            freq[x]++;
        }

        int ans = 0;
        int n = nums.size();
        int left = 0;

        for(auto &p:freq){
            int cnt = p.second;
            int right = n - left - cnt;
            ans += left * right * cnt;
            left += cnt;
        }

        return ans;
    }
};