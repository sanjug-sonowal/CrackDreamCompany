// Last updated: 18/10/2025, 09:01:27
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) return false;  // If remainder is 2, we can't form n using distinct powers of 3
            n /= 3;  // Reduce n by dividing it by 3
        }
        return true;
    }
};
