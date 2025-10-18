// Last updated: 18/10/2025, 09:04:08
class Solution {
public:
    //memoization
    // int fibHelper(int n,vector<int>&dp){
    //      if(n <= 1) return n;

    //     if(dp[n] != -1) return dp[n];

    //     dp[n] = fib(n - 1) + fib(n - 2);

    //     return dp[n];
    // }

    //tabulaton
    // int fibHelper(int n,vector<int>&dp){
    //     if(n <= 1) return n;
    //     dp[0] = 0;
    //     dp[1] = 1;

    //     for(int i = 2;i<=n;i++){
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

    


    int fib(int n) {
        if(n <= 1) return n;
        //space optimization
        int prev1 = 0;
        int prev2 = 1;
        int curr;

        for(int i = 2;i<=n;i++){
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
    }
};