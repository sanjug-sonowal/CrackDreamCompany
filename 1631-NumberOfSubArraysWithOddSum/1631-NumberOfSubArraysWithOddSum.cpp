// Last updated: 18/10/2025, 09:02:07
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd_count = 0, even_count = 1; // even_count = 1 to count empty prefix
        int prefix_sum = 0, result = 0;

        for (int num : arr) {
            prefix_sum += num;

            if (prefix_sum % 2 == 0) {
                result = (result + odd_count) % MOD;
                even_count++;
            } else {
                result = (result + even_count) % MOD;
                odd_count++;
            }
        }

        return result;
    }
};
