// Last updated: 18/10/2025, 09:08:09
class Solution {
public:
    bool isPalindrome(int x) {
        int ans = 0,rem,num = x;
        if ( x < 0)
        return 0;

        while(num)
        {
            rem = num % 10;
            num /= 10;
            if (ans > INT_MAX/10)
            return 0;
            ans = ans * 10 + rem;
        }
        if(ans == x)
        return 1;
        else
        return 0;
    }
};