// Last updated: 18/10/2025, 09:02:39
class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> freq; // digitSum → frequency

    // Step 1: Count frequencies
    for (int i = 1; i <= n; i++) {
        int sum = digitSum(i);
        freq[sum]++;
    }

    // Step 2: Find maximum size
    int maxSize = 0;
    for (auto &p : freq) {
        maxSize = max(maxSize, p.second);
    }

    // Step 3: Count how many groups have max size
    int count = 0;
    for (auto &p : freq) {
        if (p.second == maxSize) count++;
    }

    return count;
    }
};