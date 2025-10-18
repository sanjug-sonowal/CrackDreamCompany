// Last updated: 18/10/2025, 09:07:31
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        return binarySearch(1, x / 2, x);
    }

private:
    int binarySearch(long long low, long long high, int x) {
        if (low > high) return high;
        long long mid = low + (high - low) / 2;
        long long sq = mid * mid;

        if (sq == x) return mid;
        if (sq < x) return binarySearch(mid + 1, high, x);
        return binarySearch(low, mid - 1, x);
    }
};
