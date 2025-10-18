// Last updated: 18/10/2025, 09:05:26
class Solution {
public:
    int checkLRS(string &s, string &s2 ,int i, int j, vector<vector<int>> &dp) {
        if (i == 0 || j == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i - 1] == s2[j - 1])
            return dp[i][j] = 1 + checkLRS(s, s2,i - 1, j - 1, dp);
        else
            return dp[i][j] = max(checkLRS(s,s2, i - 1, j, dp), checkLRS(s,s2, i, j - 1, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return checkLRS(s,s2, n, n, dp);
    }
};