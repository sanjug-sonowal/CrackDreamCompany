// Last updated: 18/10/2025, 09:06:07
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
        return false;

        while(n != 1){
            if(n % 3 != 0)
            return false;
            n /= 3;
        }

        if(n == 1)
        return true;

        return false;
    }
};