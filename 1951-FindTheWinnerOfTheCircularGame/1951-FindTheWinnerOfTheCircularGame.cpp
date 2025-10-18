// Last updated: 18/10/2025, 09:01:21
class Solution {
public:
    int winner(int n,int k){
        if(n == 1)
        return 0;

        return (winner(n - 1,k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        return winner(n,k) + 1;
    }
};