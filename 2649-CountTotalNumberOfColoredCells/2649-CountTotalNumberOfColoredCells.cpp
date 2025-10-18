// Last updated: 18/10/2025, 08:59:46
class Solution {
public:
    long long coloredCells(int n) {
        return (long long)n * n + (long long)(n - 1) * (n - 1);
    }
};
