// Last updated: 18/10/2025, 08:59:57
class Solution {
public:
    int pivotInteger(int n) {
       int total = n * (n + 1) / 2;
        int x = sqrt(total);
        if (x * x == total) return x;
        return -1;
    }
};