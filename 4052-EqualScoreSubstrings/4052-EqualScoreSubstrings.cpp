// Last updated: 18/10/2025, 08:58:48
class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        vector<int>prefix(n + 1,0);

        for(int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + (s[i - 1] - 'a' + 1);
        }

        for(int i = 0; i < n - 1; ++i){
            int leftScore = prefix[i + 1];
            int rightScore = prefix[n] - prefix[i + 1];
            if(leftScore == rightScore){
                return true;
            }
        }
        return false;
    }
};