// Last updated: 18/10/2025, 09:05:02
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};