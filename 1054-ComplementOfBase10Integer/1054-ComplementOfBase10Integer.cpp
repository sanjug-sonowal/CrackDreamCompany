// Last updated: 18/10/2025, 09:03:53
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
        return 1;

        int ans = 0,mul = 1,rem;
        while(n)
        {
            rem = n % 2;
            rem = rem ^ 1;
            n /= 2;
            ans = ans + rem * mul;
            mul *= 2;
        }
        return ans;
    }
};