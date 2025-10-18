// Last updated: 18/10/2025, 08:59:30
class Solution {
public:
    bool canPartition(string s, int target, int index, int sum) {
        if (index == s.size()) return sum == target;
        
        int num = 0;
        for (int i = index; i < s.size(); ++i) {
            num = num * 10 + (s[i] - '0');
            if (num > target) break; // Optimization: Stop if num exceeds target
            if (canPartition(s, target, i + 1, sum + num)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            string s = to_string(square);
            if (canPartition(s, i, 0, 0)) {
                result += square;
            }
        }
        return result;
    }
};
