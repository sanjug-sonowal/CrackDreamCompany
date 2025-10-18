// Last updated: 18/10/2025, 09:06:33
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1){
            return 0;
        }
        while(n != 1){
            if(n % 2 == 1){
                return 0;
            }
            n /= 2;
        }
        return 1;
    }
};