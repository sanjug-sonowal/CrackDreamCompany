// Last updated: 18/10/2025, 09:01:41
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();
        int maxWealth = 0;
        for(int i = 0;i < n;i++){
            int sum = 0;
            for(int j = 0;j<m;j++){
                sum += accounts[i][j];
                if(sum > maxWealth){
                    maxWealth = sum;
                }
            }
        }
        return maxWealth;
    }
};