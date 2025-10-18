// Last updated: 18/10/2025, 09:06:03
class Solution {
public:
    bool isPowerOfFour(int n) {
        return ((n > 0) && ((n & (n - 1)) == 0) && (((n - 1) % 3) == 0));
    }
};