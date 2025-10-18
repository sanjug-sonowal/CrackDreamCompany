// Last updated: 18/10/2025, 08:59:44
class Solution {
public:
    int splitNum(int num) {
         vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        int n = digits.size();
        int minSum = INT_MAX;

        // try all subsets
        for (int mask = 1; mask < (1 << n) - 1; mask++) {
            vector<int> d1, d2;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) d1.push_back(digits[i]);
                else d2.push_back(digits[i]);
            }
            sort(d1.begin(), d1.end());
            sort(d2.begin(), d2.end());

            // build numbers
            long long num1 = 0, num2 = 0;
            for (int d : d1) num1 = num1 * 10 + d;
            for (int d : d2) num2 = num2 * 10 + d;

            minSum = min(minSum, (int)(num1 + num2));
        }
        return minSum;
    }
};