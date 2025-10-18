// Last updated: 18/10/2025, 09:00:39
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
       int n = questions.size();
        vector<long long> dp(n + 1, 0); // Use long long to handle large sums
        
        // Iterate from the last question to the first
        for (int i = n - 1; i >= 0; --i) {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            int next_question = i + brainpower + 1;
            
            // Option 1: Skip this question
            long long skip = dp[i + 1];
            
            // Option 2: Solve this question
            long long solve = points + (next_question < n ? dp[next_question] : 0);
            
            // Store the maximum of both choices
            dp[i] = max(skip, solve);
        }
        
        return dp[0];  
    }
};