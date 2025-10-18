// Last updated: 18/10/2025, 09:06:05
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n + 1,0);
        for(int i = 1; i<= n; i++){
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};